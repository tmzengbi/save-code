#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e4+10;
const int inf=2e9;
struct Edge
{
	int v,d;
	Edge(int v,int d):v(v),d(d){}
};
vector<Edge>edges[maxn];
int n;ll ans=0;
//重心相关
int tr,f[maxn],siz[maxn],sum,vis[maxn];
void findtr(int u,int fa)
{
	siz[u]=1;f[u]=0;
	for(auto to:edges[u])
	{
		if(to.v==fa||vis[to.v]) continue;
		findtr(to.v,u);
		siz[u]+=siz[to.v];
		f[u]=max(f[u],siz[to.v]);
	}
	f[u]=max(f[u],sum-f[u]);
	if(f[tr]>f[u]) tr=u;
}
// 距离相关
int d[maxn],s[maxn];
void finddis(int u,int fa)
{
	s[++s[0]]=d[u];
	for(auto to:edges[u])
	{
		if(to.v==fa||vis[to.v]) continue;
		d[to.v]=(d[u]+to.d)%3;
		finddis(to.v,u);
	}
}
//桶相关
int p[3];
void solve(int u)
{
	p[0]=1;
	for(auto to:edges[u])
	{
		if(vis[to.v]) continue;
		s[0]=0;d[to.v]=to.d%3;finddis(to.v,u);
		for(int i=1;i<=s[0];i++) ans+=p[(3-s[i])%3]*2;
		for(int i=1;i<=s[0];i++) p[s[i]]++;		
	}
	memset(p,0,sizeof p);
}
//点分治
void divide(int u)
{
	vis[u]=1;solve(u);
	for(auto to:edges[u])
	{
		if(vis[to.v]) continue;
		f[tr=0]=inf;sum=siz[to.v];
		findtr(to.v,u);
		divide(tr);
	}
}
//约分相关
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,d;scanf("%d%d%d",&u,&v,&d);d%=3;
		edges[u].push_back(Edge(v,d));
		edges[v].push_back(Edge(u,d));
	}
	sum=f[tr=0]=n;ans+=n;
	findtr(1,1);
	divide(tr);
	int fm=n*n,fz=ans;
	int r=gcd(fz,fm);
	printf("%d/%d\n",fz/r,fm/r);
//	system("pause");
}
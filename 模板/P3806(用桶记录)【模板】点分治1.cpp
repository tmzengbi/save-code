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
const int maxn=1e4+10;
const int maxnum=1e7+10;
struct Edge
{
	int v,d;
	Edge(int v,int d):v(v),d(d){}
};
vector<Edge>edges[maxn];
int n,m,siz[maxn],f[maxn],vis[maxn],rt,d[maxn],sum;
int s[maxn],k[maxnum],test[maxn];
void dfs(int u,int fa)
{
	siz[u]=1;f[u]=0;
	for(auto e:edges[u])
	{
		if(e.v==fa||vis[e.v]) continue;
		dfs(e.v,u);
		f[u]=max(f[u],siz[e.v]);
		siz[u]+=siz[e.v];
	}
	f[u]=max(f[u],sum-f[u]);
	if(f[rt]>f[u]) rt=u;
}
void getdis(int u,int fa)
{
	if(d[u]<maxnum) s[++s[0]]=d[u];
	for(auto to:edges[u])
	{
		if(vis[to.v]||to.v==fa) continue;
		d[to.v]=d[u]+to.d;
		getdis(to.v,u);
	}
}
int aim[maxn],q[maxn];
void solve(int r)
{
	int p=0;
	for(auto to:edges[r])
	{
		if(vis[to.v]) continue;
		s[0]=0;d[to.v]=to.d;
		getdis(to.v,r);
		for(int i=s[0];i;i--)
			for(int j=1;j<=m;j++)
				if(aim[j]>=s[i])
					test[j]|=k[aim[j]-s[i]];
		for(int i=s[0];i;i--)
			q[++p]=s[i],k[s[i]]=1;
	}
	for(int i=1;i<=p;i++)
		k[q[i]]=0;
//	memset(k,0,sizeof k);
}
void divide(int r)
{
	vis[r]=1;k[0]=1;solve(r);
	for(auto to:edges[r])
	{
		if(vis[to.v]) continue;
		sum=siz[to.v];f[rt=0]=1e8+10;
		dfs(to.v,to.v);divide(rt);
//		printf("%d\n",rt);
	}
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		edges[u].push_back(Edge(v,d));
		edges[v].push_back(Edge(u,d));
	}
	for(int i=1;i<=m;i++) scanf("%d",&aim[i]);
	f[rt]=sum=n;
	dfs(1,1);
	divide(rt);
	for(int i=1;i<=m;i++)
	{
		if(test[i]) printf("AYE\n");
		else printf("NAY\n");
	}
//	system("pause");
}
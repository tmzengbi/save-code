#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=5e5+10;
vector<int>edges[maxn];
int pre[maxn][30],dep[maxn],rt,n,m;
void findpre(int u)
{
	for(int v:edges[u])
	{
		if(v==pre[u][0]) continue;
		pre[v][0]=u;
		dep[v]=dep[u]+1;
		for(int i=1;(1<<i)<=dep[v];i++)
			pre[v][i]=pre[pre[v][i-1]][i-1];
		findpre(v);
	}
}
int getlca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
		if(dep[u]-(1<<i)>=dep[v]) u=pre[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--)
		if(pre[u][i]!=pre[v][i]) u=pre[u][i],v=pre[v][i];
	return pre[u][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&rt);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	findpre(rt);
	while(m--)
	{
		int u,v;scanf("%d%d",&u,&v);
		printf("%d\n",getlca(u,v));
	}
//	system("pause");
}
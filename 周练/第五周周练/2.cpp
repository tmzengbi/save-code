#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100010;
template<typename T> T max(T a,T b,T c)
{
	return max(max(a,b),c);
}
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Edge>G;
vector<int>edges[maxn];
int N;
ll dis[maxn],ans[maxn];
bool vis[maxn];
void dp(int u)
{
	vis[u]=1;
	for(int i=0;i<edges[u].size();i++)
	{
		Edge e=G[edges[u][i]];
		int v=e.v;
		if(v==u) v=e.u;
		if(vis[v]) continue;
		dp(v);
		ans[u]=max(ans[u],ans[v],dis[u]+dis[v]+e.d);
		dis[u]=max(dis[u],dis[v]+e.d);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d",&N)==1)
	{
		memset(vis,false,sizeof vis);
		for(int i=1;i<=N;i++)
			edges[i].clear();
		G.clear();
		memset(ans,0,sizeof ans);
		memset(dis,0,sizeof dis);
		for(int i=1;i<N;i++)
		{
			int u,v,d;scanf("%d%d%d",&u,&v,&d);
			G.push_back(Edge(u,v,d));
			edges[u].push_back(i-1);
			edges[v].push_back(i-1);
		}
		dp(1);
		for(int i=1;i<=N;i++)
			printf("%lld\n",ans[i]);
	}
}
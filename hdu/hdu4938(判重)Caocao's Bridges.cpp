#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1010;
struct Edge
{
	int u,v,f;
	Edge(int u,int v,int f):u(u),v(v),f(f){}
};
int dfn[maxn],low[maxn],cnt=0,N,M,ans=1e9,s[maxn],Index=0;
vector<Edge> G;
vector<int> edges[maxn];
void init()
{
	memset(dfn,0,sizeof dfn);
	cnt=0;ans=1e9;
	for(int i=1;i<=N;i++)
		edges[i].clear();
	G.clear();
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	int ccnt=0;
	for(int i=0;i<edges[u].size();i++)
	{
		
		Edge e=G[edges[u][i]];
		int v=e.v,f=e.f;
		if(u==v) v=e.u;
		if(fa==v&&ccnt==0){ccnt++;continue;}
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				ans=min(ans,f);
		}
		else if(dfn[v]<dfn[u])
			low[u]=min(low[u],dfn[v]);
	}
}
int main()
{
	while(scanf("%d%d",&N,&M)&&(N||M))
	{
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v,f;scanf("%d%d%d",&u,&v,&f);
			G.push_back(Edge(u,v,f));
			edges[u].push_back(i-1);
			edges[v].push_back(i-1);
		}
		tarjan(1,0);
		if(ans==0) ans=1;
		if(cnt!=N) ans=0;
		if(ans==1e9) ans=-1;
		printf("%d\n",ans);
	}
	
}
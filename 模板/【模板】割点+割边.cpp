#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=20010;
int dfn[maxn],low[maxn],N,M,cnt=0,ans=0;
bool iscut[maxn];
struct Edge
{
	int u,v;
	Edge(int u,int v):u(u),v(v){}
};
vector<Edge> e;
vector<int> edges[maxn];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	int child=0;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			child++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
				iscut[u]=true;
			if(low[v]>dfn[u])
				e.push_back(Edge(u,v));
		}
		else if(dfn[v]<dfn[u]&&v!=fa) 
			low[u]=min(low[u],dfn[v]);
	}
	if(fa==0&&child==1) iscut[u]=false;
	if(iscut[u]) ans++;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i,0);
	printf("%d\n",ans);
	for(int i=1;i<=N;i++)
		if(iscut[i]) printf("%d ",i);
	printf("\n");
	for(int i=0;i<e.size();i++)
		printf("%d %d\n",e[i].u,e[i].v);
}
/*
6 6
1 2
2 3
2 4
3 4
4 5
5 6
*/
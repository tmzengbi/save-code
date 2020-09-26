#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;
struct Edge
{
	int u,v;
	Edge(){}
	Edge(int u,int v):u(u),v(v){}
}s[100010];
int M,N,dfn[maxn],low[maxn],cnt=0,ans1=0,ans2=0,Index=0,belong[maxn],cnt_bcc=0;
vector<int> edges[maxn];
void addedge(int u,int v)
{
	edges[u].push_back(v);
	edges[v].push_back(u);
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			s[++Index]=Edge(u,v);
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				if(low[v]>dfn[u]) ans1++;
				int sum_edge=0,sum_node=0;
				cnt_bcc++;
				for(Edge e;;)
				{
					e=s[Index--];
					sum_edge++;
					if(belong[e.u]!=cnt_bcc){belong[e.u]=cnt_bcc;sum_node++;}
					if(belong[e.v]!=cnt_bcc){belong[e.v]=cnt_bcc;sum_node++;}
					if(e.u==u&&e.v==v) break;
				}
				if(sum_node<sum_edge) ans2+=sum_edge;
			}
		}
		else if(dfn[v]<dfn[u]&&fa!=v)
		{
			s[++Index]=Edge(u,v);
			low[u]=min(low[u],dfn[v]);
		}
	}
}
void init()
{
	for(int i=1;i<=N;i++)
		edges[i].clear();
	memset(dfn,0,sizeof dfn);
	memset(belong,0,sizeof belong);
	cnt=0;cnt_bcc=0;ans1=ans2=0;
}
int main()
{
	while(true)
	{
		scanf("%d%d",&N,&M);
		if(N==0&&M==0) break;
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			addedge(u+1,v+1);
		}
		for(int i=1;i<=N;i++)
			if(!dfn[i]) tarjan(i,0);
		printf("%d %d\n",ans1,ans2);
	}
}
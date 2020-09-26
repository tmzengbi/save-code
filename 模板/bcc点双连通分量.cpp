#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct E
{
	int u,v;
}s[maxn];
int dfn[maxn],low[maxn],cnt=0,Index=0,N,M,bcc_cnt=0,bccno[maxn];
bool iscut[maxn];
vector<int> edges[maxn],bcc[maxn];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	int child=0;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
//		s[++Index]=(E){u,v};
		if(!dfn[v])
		{
			s[++Index]=(E){u,v};
			child++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				iscut[u]=true;
				bcc_cnt++;bcc[bcc_cnt].clear();
				for(;;)
				{
					E e=s[Index--];
					if(bccno[e.u]!=bcc_cnt){bccno[e.u]=bcc_cnt;bcc[bcc_cnt].push_back(e.u);}
					if(bccno[e.v]!=bcc_cnt){bccno[e.v]=bcc_cnt;bcc[bcc_cnt].push_back(e.v);}
					if(e.u==u&&e.v==v) break;
				}
			}
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
		{
			s[++Index]=(E){u,v};
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(fa==0&&child==1) iscut[u]=false;
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
	for(int i=1;i<=bcc_cnt;i++)
	{
		for(int j=0;j<bcc[i].size();j++)
			printf("%d ",bcc[i][j]);
		printf("\n");
	}
}
/*
5 6
1 2
2 3
1 3
3 4
3 5
4 5
*/
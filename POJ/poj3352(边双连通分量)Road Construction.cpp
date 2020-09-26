#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
struct Edge
{
	int u,v;
};
int dfn[maxn],low[maxn],cnt=0,bcc_cnt=0,s[maxn],Index=0,belong[maxn],in[maxn];
bool vis[maxn];
vector<Edge> bridge;
vector<int> edges[maxn];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	s[++Index]=u;
	vis[u]=true;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) bridge.push_back((Edge){u,v});
		}
		else if(dfn[u]>dfn[v]&&v!=fa)
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		bcc_cnt++;
		for(int cur;;)
		{
			cur=s[Index--];
			belong[cur]=bcc_cnt;
			vis[cur]=false;
			if(cur==u) break;
		}
	}
}
int main()
{
	int N,M;
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
//	for(int i=0;i<bridge.size();i++)
//		cout<<bridge[i].u<<" "<<bridge[i].v<<endl;
	for(int i=0;i<bridge.size();i++)
	{
		Edge e=bridge[i];
		in[belong[e.u]]++;in[belong[e.v]]++;
	}
	int sum=0;
	for(int i=1;i<=bcc_cnt;i++)
		if(in[i]==1) sum++;
	printf("%d\n",(sum+1)/2);
}

/*
10 12
1 2
1 3
1 4
2 5
2 6
5 6
3 7
3 8
7 8
4 9
4 10
9 10
*/
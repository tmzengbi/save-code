#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=5050;
struct Edge
{
	int u,v;
};
int dfn[maxn],low[maxn],s[maxn],Index=0,cnt=0,cnt_bcc=0,N,M,belong[maxn],in[maxn];
vector<int> edges[maxn];
vector<Edge> mk;
void addedges(int x,int y)
{
	edges[x].push_back(y);
	edges[y].push_back(x);
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	s[++Index]=u;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				mk.push_back((Edge){u,v});
		}
		else if(dfn[u]>dfn[v]&&v!=fa)
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++cnt_bcc;
		for(int cur;cur!=u;)
		{
			cur=s[Index--];
			belong[cur]=cnt_bcc;
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		addedges(u,v);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i,0);
	for(int i=0;i<mk.size();i++)
	{
		Edge e=mk[i];
		in[belong[e.u]]++;in[belong[e.v]]++;
	}
	int ans=0;
	for(int i=1;i<=cnt_bcc;i++)
		if(in[i]==1) ans++;
	ans=(ans+1)/2;
	printf("%d\n",ans);
}
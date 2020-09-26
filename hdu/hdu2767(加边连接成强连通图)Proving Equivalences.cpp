#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=20010;
int dfn[maxn],low[maxn],cnt=0,Index=0,cntscc=0,s[maxn],N,M,T,belong[maxn];
int U[50010],V[50010];
bool vis[maxn];
vector<int> edges[maxn];
void addedge(int u,int v)
{
	edges[u].push_back(v);
}
void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s[++Index]=u;
	vis[u]=true;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		int cur;cntscc++;
		for(;;)
		{
			cur=s[Index--];
			vis[cur]=false;
			belong[cur]=cntscc;
			if(cur==u) break;
		}
	}
}
void solve()
{
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	int out[maxn],in[maxn];
	memset(out,0,sizeof out);
	memset(in,0,sizeof in);
	if(cntscc==1) printf("0\n");
	else
	{	
		for(int i=1;i<=M;i++)
		{
			int u=U[i],v=V[i];
			if(belong[u]!=belong[v]) {out[belong[u]]++;in[belong[v]]++;}
		}
		int ans1=0,ans2=0;
		for(int i=1;i<=cntscc;i++)
		{
			if(out[i]==0) ans1++;
			if(in[i]==0) ans2++;
		}
		printf("%d\n",max(ans1,ans2));
	}
}
void init()
{
	memset(dfn,0,sizeof dfn);
	memset(belong,0,sizeof belong);
	for(int i=1;i<=N;i++)
		edges[i].clear();
	cnt=cntscc=0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		init();
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d",&U[i],&V[i]);
			addedge(U[i],V[i]);
		}
		solve();
	}
}	
/*
2 2
1 2  
2 1

8 6
1 4
2 4
3 4
4 5
4 6
7 8
*/
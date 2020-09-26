#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100010;
int dfn[maxn],low[maxn],dep[maxn],pre[maxn],cnt=0,N,M,Q,Cutedge=0,s[maxn],Index=0,belong[maxn];
bool iscut[maxn];
vector<int>edges[maxn];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	dep[u]=dep[fa]+1;
	pre[u]=fa;
	s[++Index]=u;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
			{
				Cutedge++;
				iscut[v]=true;
			}
		}
		else if(v!=fa&&dfn[v]<dfn[u])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		for(int cur;;)
		{
			cur=s[Index--];
			belong[cur]=u;
			if(cur==u) break;
		}
	}
}
void lca(int u,int v)
{
/*
	if(dep[u]>dep[v]) swap(u,v);
	while(dep[u]<dep[v])
	{
		if(iscut[v]){iscut[v]=false;Cutedge--;}
		v=pre[v];
	}
	while(u!=v)
	{
		if(iscut[v]){iscut[v]=false;Cutedge--;}
		if(iscut[u]){iscut[u]=false;Cutedge--;}
		v=pre[v];u=pre[u];
	}
	*/
	while(u!=v)
	{
		if(dep[u]<dep[v]) swap(u,v);
		while(dep[u]>dep[v])
		{
			u=belong[u];
			if(iscut[u]){iscut[u]=false;Cutedge--;}
			u=pre[u];
		}
		if(u==v) break;
		else if(dep[u]==dep[v])
		{
			u=belong[u];v=belong[v];
			if(iscut[u]){iscut[u]=false;Cutedge--;}
			if(iscut[v]){iscut[v]=false;Cutedge--;}
			u=pre[u];v=pre[v];
		}
	}
}
void addedges(int a,int b)
{
	edges[a].push_back(b);
	edges[b].push_back(a);
}
void init()
{
	memset(dfn,0,sizeof dfn);
	memset(dep,0,sizeof dep);
	memset(iscut,false,sizeof iscut);
	cnt=0;Cutedge=0;
	for(int i=1;i<=N;i++)
		edges[i].clear();
}
int main()
{
	int Cas=0;
	while(true)
	{
		scanf("%d%d",&N,&M);
		if(N==0&&M==0) break;
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedges(u,v);
		}
		tarjan(1,0);
		scanf("%d",&Q);
		printf("Case %d:\n",++Cas);
		while(Q--)
		{
			int u,v;scanf("%d%d",&u,&v);
			lca(u,v);
			printf("%d\n",Cutedge);
		}
		printf("\n");
	}
}
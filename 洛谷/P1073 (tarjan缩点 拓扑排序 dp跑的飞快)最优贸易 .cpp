#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=100010;
int dfn[maxn],low[maxn],cnt=0,_cnt=0,Index=0,ccnt=0,s[maxn],t[maxn],M,N,belong[maxn];
int mint[maxn],maxt[maxn],Min[maxn],U[500010],V[500010],D[500010],List[maxn],dp[maxn],in[maxn];
bool vis[maxn],isget[maxn];
vector<int> edges[maxn];
vector<int> edge[maxn];
vector<int> conedge[maxn];
void topo()
{
	ccnt=0;
	queue<int> q;
	for(int i=1;i<=_cnt;i++)
		if(!in[i])	q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		List[++ccnt]=u;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
}
void dfs(int u)
{
	if(isget[u])return;
	isget[u]=true;
	for(int i=0;i<conedge[u].size();i++)
	{
		int v=conedge[u][i];
		dfs(v);
	}
}
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	s[++Index]=now;
	vis[now]=true;
	for(int i=0;i<edges[now].size();i++)
	{
		int v=edges[now][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[now]=min(low[v],low[now]);
		}
		else if(vis[v])
			low[now]=min(low[now],dfn[v]);
	}
	if(dfn[now]==low[now])
	{
		++_cnt;
		int cur,tmin=1e7,tmax=0;
		do
		{
			cur=s[Index--];
			vis[cur]=false;
			belong[cur]=_cnt;
			tmin=min(tmin,t[cur]);
			tmax=max(tmax,t[cur]);
		}while(cur!=now);
		mint[_cnt]=tmin;maxt[_cnt]=tmax;
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&U[i],&V[i],&D[i]);
		edges[U[i]].push_back(V[i]);
		if(D[i]==2) edges[V[i]].push_back(U[i]);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=M;i++)
	{
		int bu=belong[U[i]],bv=belong[V[i]];
		if(bu!=bv)
		{
			edge[bu].push_back(bv);in[bv]++;conedge[bv].push_back(bu);
			if(D[i]==2) {edge[bv].push_back(bu);in[bu]++;conedge[bu].push_back(bv);}
		}
	}
	topo();dfs(belong[N]);
	for(int i=1;i<=ccnt;i++) {dp[i]=mint[i];}
	int ans=0;
	for(int i=1;i<=ccnt;i++)
	{
		int u=List[i];
		if(isget[u]) ans=max(ans,maxt[u]-dp[u]);
		for(int j=0;j<edge[u].size();j++)
		{
			int v=edge[u][j];
			dp[v]=min(dp[v],dp[u]);
		}
	}
	printf("%d\n",ans);
}
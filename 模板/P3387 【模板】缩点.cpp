#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=10010;
int N,M,dfn[maxn],low[maxn],t[maxn],cnt=0,cntscc=0,s[maxn],Index=0,belong[maxn],T[maxn];
int U[100010],V[100010],in[maxn],topo[maxn],dp[maxn],ans=0;
bool vis[maxn];
vector<int>edges[maxn];
vector<int>edge[maxn];
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
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		cntscc++;
		int cur;
		while(true)
		{
			cur=s[Index--];
			vis[cur]=false;
			belong[cur]=cntscc;
			T[cntscc]+=t[cur];
			if(cur==u) break;
		}
	}
}
void toposort()
{
	int tot=0;
	queue<int>q;
	for(int i=1;i<=cntscc;i++)
		if(in[i]==0) q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		topo[++tot]=u;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%d",&t[i]);
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
		edges[U[i]].push_back(V[i]);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=M;i++)
	{
		int b1=belong[U[i]],b2=belong[V[i]];
		if(b1!=b2)
		{
			edge[b1].push_back(b2);
			in[b2]++;
		}
	}
	toposort();
	for(int i=1;i<=cntscc;i++) dp[i]=T[i];
	for(int i=1;i<=cntscc;i++)
	{
		int u=topo[i];
		ans=max(dp[u],ans);
		for(int j=0;j<edge[u].size();j++)
		{
			int v=edge[u][j];
			dp[v]=max(dp[v],dp[u]+T[v]);
		}
	}
	printf("%d\n",ans);
//	system("pause");
}
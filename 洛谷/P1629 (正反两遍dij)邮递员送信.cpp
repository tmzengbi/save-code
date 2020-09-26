#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int maxn=2e8;
int N,M,dist[1010];
bool vis[1010];
struct Node
{
	int u,v,d;
	Node(int u,int v,int d):u(u),v(v),d(d){}
};
struct edge
{
	int u,d;
	edge(int u,int d):u(u),d(d){}
	bool operator < (const edge E)const
	{
		return d>E.d;
	}
};
vector<Node>G;
vector<int> edges[1010];
vector<int> edges2[1010];
void dij(int from)
{
	for(int i=1;i<=N;i++)
		dist[i]=maxn;
	memset(vis,false,sizeof vis);
	priority_queue<edge> q;
	q.push(edge(from,0));
	dist[from]=0;
	while(!q.empty())
	{
		edge tmp=q.top();q.pop();
		int u=tmp.u;
		if(vis[u]) continue;
		else vis[u]=true;
		int len=edges[u].size();
		for(int i=0;i<len;i++)
		{
			Node e=G[edges[u][i]];
			int v=e.v,d=e.d;
			if((dist[u]+d)<dist[v])
			{
				dist[v]=dist[u]+d;
				q.push(edge(v,dist[v]));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G.push_back(Node(u,v,d));
		edges[u].push_back(i-1);
		edges2[v].push_back(i-1);
	}
	int ans=0;
	dij(1);
	for(int i=2;i<=N;i++)
		ans+=dist[i];
	for(int i=0;i<M;i++)
		swap(G[i].u,G[i].v);
	for(int i=1;i<=N;i++)
	{
		edges[i].clear();
		edges[i]=edges2[i];
	}
	dij(1);
	for(int i=2;i<=N;i++)
		ans+=dist[i];
	printf("%d\n",ans);
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int N,M;
bool vis[5010];
struct Node
{
	int u,v,d;
	Node(int u,int v,int d):u(u),v(v),d(d){}
};
struct edge
{
	int u,d;
	edge(int u,int d):u(u),d(d){}
	bool operator < (edge E) const
	{
		return d>E.d;
	}
};
vector<Node> G;
vector<int> edges[5010];
int prim()
{
	memset(vis,false,sizeof vis);
	int ans=0,cnt=0;
	priority_queue<edge> q;
	q.push(edge(1,0));
	while(!q.empty()&&cnt<N)
	{
		edge E=q.top();q.pop();
		int u=E.u;
		if(vis[u]) continue;
		else vis[u]=true;
		cnt++;ans+=E.d;
		int len=edges[u].size();
		for(int j=0;j<len;j++)
		{
			Node e=G[edges[u][j]];
			int v=e.v,d=e.d;
			if(u==v) v=e.u;
			if(!vis[v])	q.push(edge(v,d));
		}
	}
	if(cnt==N) return ans;
	else return -1;
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
		edges[v].push_back(i-1);
	}
	int ans=prim();
	if(ans!=-1)	printf("%d\n",ans);
	else printf("orz\n");
}
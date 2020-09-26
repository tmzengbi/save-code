#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=310;
int N,M,S,T,dist[maxn];
bool vis[maxn];
struct Edge
{
	int u,v,d,a,b;
	Edge(int u,int v,int d,int a,int b):u(u),v(v),d(d),a(a),b(b){}
};
struct Node
{
	int u,d;
	Node(int u,int d):u(u),d(d){}
	bool operator < (const Node NN)const
	{
		return d>NN.d;
	}
};
vector<Edge>G;
vector<int>edges[maxn];
int dij()
{
	priority_queue<Node>q;
	for(int i=1;i<=N;i++) dist[i]=1e8;
	memset(vis,false,sizeof vis);
	q.push(Node(S,0));
	dist[S]=0;
	while(!q.empty())
	{
		Node node=q.top();q.pop();
		int u=node.u,d=node.d;
		if(u==T) return d;
		if(vis[u]) continue;
		else vis[u]=true;
		for(int i=0;i<edges[u].size();i++)
		{
			Edge e=G[edges[u][i]];
			int t=d,addd,last=t%(e.a+e.b);
			if(last+e.d<=e.a) addd=e.d;
			else addd=e.a+e.b-last+e.d;
			if(t+addd<dist[e.v])
			{
				dist[e.v]=t+addd;
				q.push(Node(e.v,dist[e.v]));
			}
		}
	}
	return dist[T];
}
void init()
{
	G.clear();
	for(int i=1;i<=N;i++)
		edges[i].clear();
}
int main()
{
	int Cas=0;
	while(scanf("%d%d%d%d",&N,&M,&S,&T)==4)
	{
		int cnt=0;
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v,a,b,t;
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
			if(t>a) continue;
			if(a+b==0) continue;
			G.push_back(Edge(u,v,t,a,b));
			edges[u].push_back(cnt++);
		}
		printf("Case %d: ",++Cas);
		printf("%d\n",dij());
	}
}
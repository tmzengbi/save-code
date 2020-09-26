#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1010;
const int inf=2e9;
int n,m,k,from,to;
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
vector<int>edges[maxn];
vector<Edge>G;
vector<int>reedges[maxn];
vector<Edge>reG;
int dis[maxn];bool vis[maxn];
struct Node2
{
	int u,d;
	Node2(int u,int d):u(u),d(d){}
	bool operator<(const Node2&rhs)const
	{
		return d>rhs.d;
	}
};
void dij(int from,int to)
{
	priority_queue<Node2>q;
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[from]=0;
	q.push(Node2(from,0));
	while(!q.empty())
	{
		auto f=q.top();q.pop();
		if(vis[f.u]) continue;
		vis[f.u]=1;
		for(int edge:reedges[f.u])
		{
			auto e=reG[edge];
			if(dis[e.v]>dis[e.u]+e.d)
			{
				dis[e.v]=dis[e.u]+e.d;
				q.push(Node2(e.v,dis[e.v]));
			}
		}
	}
}
struct Node
{
	int u,d;
	Node(int u,int d):u(u),d(d){}
	bool operator<(const Node&rhs)const
	{
		return dis[u]+d>dis[rhs.u]+rhs.d;
	}
};
void kthpath()
{
	dij(to,from);
	if(dis[from]==inf)
	{
		for(int i=1;i<=k;i++) printf("-1\n");
		return;
	}
	priority_queue<Node>q;
	q.push(Node(from,0));
	int cnt=0;
	while(!q.empty())
	{
		auto now=q.top();q.pop();
		if(now.u==to)
		{
			cnt++;
			printf("%d\n",now.d);
			if(cnt==k) return;
		}
		for(int edge:edges[now.u])
		{
			auto e=G[edge];
			if(dis[e.v]==inf) continue;
			q.push(Node(e.v,e.d+now.d));
		}
	}
	for(int i=cnt;i<k;i++) printf("-1\n");
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	from=n;to=1;
	for(int i=1;i<=m;i++)
	{
		static int cnt=0;
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G.push_back(Edge(u,v,d));
		edges[u].push_back(cnt);
		reG.push_back(Edge(v,u,d));
		reedges[v].push_back(cnt++);
	}
	kthpath();
//	system("pause");
}
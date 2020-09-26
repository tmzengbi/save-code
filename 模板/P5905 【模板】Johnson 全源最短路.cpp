#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<random>
#include<bitset>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=3e3+10;
const int maxm=6e3+10;
const int inf=1e9;
int n,m;
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Edge>G;
vector<int>edges[maxn];
int h[maxn];
bool bellmanford()
{
	for(int i=1;i<=n;i++) G.push_back(Edge(0,i,0));
	memset(h,0x3f,sizeof h);
	h[0]=0;
	for(int i=0;i<n-1;i++)
		for(auto e:G) if(h[e.u]!=0x3f3f3f3f)
			h[e.v]=min(h[e.v],h[e.u]+e.d);
	for(auto &e:G)
	{
		if(h[e.v]>h[e.u]+e.d) return false;
		if(!e.u) break;
		e.d+=h[e.u]-h[e.v];
	}
	return true;
}
struct Node
{
	int u,d;
	Node(int u,int d):u(u),d(d){}
	bool operator<(const Node&rhs)const
	{
		return d>rhs.d;
	}
};
bool vis[maxn];
int dist[maxn];
ll dij(int u)
{
	priority_queue<Node>q;
	for(int i=1;i<=n;i++) dist[i]=inf;
	memset(vis,false,sizeof vis);
	dist[u]=0;
	q.push(Node(u,0));
	while(!q.empty())
	{
		auto from=q.top();q.pop();
		int u=from.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int to:edges[u])
		{
			auto e=G[to];
			if(dist[e.v]>dist[e.u]+e.d)
			{
				dist[e.v]=dist[e.u]+e.d;
				q.push(Node(e.v,dist[e.v]));
			}
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==inf) sum+=(ll)inf*i;
		else sum+=(ll)(dist[i]+h[i]-h[u])*i;
	}
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		G.push_back(Edge(u,v,d));
		edges[u].push_back(G.size()-1);
	}
	if(!bellmanford()){puts("-1");return 0;}
	for(int i=1;i<=n;i++)
		printf("%lld\n",dij(i));
}
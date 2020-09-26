#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=10010;
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
struct Node
{
	int u,dist;
	Node(int u,int dist):u(u),dist(dist){}
	bool operator < (const Node &T)const
	{
		return dist>T.dist;
	}
};
vector<Edge> G;
vector<int> edges[maxn];
priority_queue<Node> q;
int N,M,f[maxn],c[maxn];
bool vis[maxn];
ll hp,dis[maxn];
bool check(int fee)
{
	if(f[1]>fee||f[N]>fee)	return false;
	for(int i=1;i<=N;i++)
		if(f[i]>fee)	vis[i]=true;
		else vis[i]=false;
	for(int i=2;i<=N;i++)
		dis[i]=2e15L;
	dis[1]=0;
	q.push(Node(1,0));
	while(!q.empty())
	{
		Node node=q.top();q.pop();
		if(vis[node.u])continue;
		vis[node.u]=true;
		for(int i=0;i<edges[node.u].size();i++)
		{
			int v=G[edges[node.u][i]].v,d=G[edges[node.u][i]].d;
			if(node.u==v)	v=G[edges[node.u][i]].u;
			if(dis[v]>dis[node.u]+d)
			{
				dis[v]=dis[node.u]+d;
				q.push(Node(v,dis[v]));
			}
		}
	}
	if(dis[N]>hp)	return false;
	return true;

}
int main()
{
	scanf("%d%d%lld",&N,&M,&hp);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&f[i]);
		c[i]=f[i];
	}
	sort(c+1,c+N+1);
	for(int i=1;i<=M;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G.push_back(Edge(u,v,d));
		edges[u].push_back(i-1);
		edges[v].push_back(i-1);
	}
	if(!check(c[N])){printf("AFK\n");return 0;}
	int l=1,r=N;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(c[mid])) r=mid;
		else l=mid+1;
	}

	printf("%d\n",c[l]);

//	system("pause");
}
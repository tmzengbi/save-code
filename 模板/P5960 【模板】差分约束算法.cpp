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
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=5e3+10;
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Edge>G;
vector<int>edges[maxn];
int cntedges=0;
int n,m,dis[maxn],vis[maxn],dep[maxn];
queue<int>q;
bool spfa()
{
	memset(dis,0x3f,sizeof dis);
	q.push(0);
	vis[0]=1;dis[0]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int pos:edges[u])
		{
			auto e=G[pos];
			if(dis[e.v]>dis[e.u]+e.d)
			{
				dep[e.v]=dep[e.u]+1;
				if(dep[e.v]>n) return false;
				dis[e.v]=dis[e.u]+e.d;
				if(!vis[e.v])
				{
					q.push(e.v);
					vis[e.v]=1;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		G.push_back(Edge(0,i,0));
		edges[0].push_back(cntedges++);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,v;scanf("%d%d%d",&x,&y,&v);
		G.push_back(Edge(y,x,v));
		edges[y].push_back(cntedges++);
	}
	if(spfa())
	{
		for(int i=1;i<=n;i++)
			printf("%d ",dis[i]);
		puts("");
	}
	else puts("NO");
}
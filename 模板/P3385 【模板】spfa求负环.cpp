#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2e9;
int n,m,T,dis[2010],cnt[2010];
bool vis[2010];
struct Node
{
	int u,v,d;
	Node(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Node> G;
vector<int> edges[2010];
void init_vec()
{
	G.clear();
	for(int i=1;i<=n;i++)
		edges[i].clear();
}
bool SPFA()
{
	queue<int> q;
	memset(vis,false,sizeof vis);
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)
		dis[i]=maxn;
	q.push(1);
	vis[1]=true;cnt[1]++;dis[1]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=false;
		int len=edges[u].size();
		for(int i=0;i<len;i++)
		{
			Node e=G[edges[u][i]];
			int v=e.v,d=e.d;
			if(v==u) v=e.u;
			if((dis[u]+d)<dis[v])
			{
				dis[v]=dis[u]+d;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>n)
					return false;
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init_vec();
		for(int i=1;i<=m;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			G.push_back(Node(u,v,d));
			edges[u].push_back(i-1);
			if(d>=0) edges[v].push_back(i-1);
		}
		if(!SPFA()) printf("YE5\n");
		else printf("N0\n");
	}
//	system("pause");
}
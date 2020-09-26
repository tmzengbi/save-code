#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2010;
struct Flow
{
	int u,v,f,c,cost;
	Flow(int u,int v,int f,int c,int cost):u(u),v(v),f(f),c(c),cost(cost){}
};
vector<Flow> G;
vector<int> edges[maxn];
int N,M,cnt=0,pre[maxn],d[maxn],a[maxn],tot=0,ans=0;
bool vis[maxn];
bool spfa()
{
	queue<int>q;
	memset(vis,false,sizeof vis);
	vis[1]=true;
	for(int i=1;i<=N*2;i++)
		d[i]=1e8;
	d[1]=0;a[1]=1e8;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=false;
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			if(e.c>e.f&&d[e.v]>d[u]+e.cost)
			{
				a[e.v]=min(a[u],e.c-e.f);
				d[e.v]=d[u]+e.cost;
				pre[e.v]=edges[u][i];
				if(!vis[e.v])
				{
					vis[e.v]=true;
					q.push(e.v);
				}
			}
		}
	}
	return d[N]!=1e8;
}
void ek()
{
	tot=ans=0;
	while(spfa())
	{
		int k=N;
		while(k!=1)
		{
			Flow &e=G[pre[k]];
			Flow &fe=G[pre[k]^1];
			e.f+=a[N];fe.f-=a[N];
			k=e.u;
		}
		tot++;ans+=d[N];
		if(tot==2) break;
	}
}
void init()
{
	G.clear();
	for(int i=1;i<=N*2;i++)
		edges[i].clear();
	cnt=0;
}
int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			if(u>1&&u<N) u+=N;  
			G.push_back(Flow(u,v,0,1,c));
			edges[u].push_back(cnt++);
			G.push_back(Flow(v,u,1,1,-c));
			edges[v].push_back(cnt++);
		}
		for(int i=2;i<N;i++)
		{
			G.push_back(Flow(i,i+N,0,1,0));
			edges[i].push_back(cnt++);
			G.push_back(Flow(i+N,i,1,1,0));
			edges[i+N].push_back(cnt++);
		}
		ek();
		printf("%d\n", ans);
	}
}
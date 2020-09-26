#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=50010;
int N,M,S,T,cnt=0,pre[5010],d[5010],a[5010],ans_cost=0,ans_flow=0;
bool vis[5010];
struct Flow
{
	int u,v,f,c,cost;
	Flow(int u,int v,int f,int c,int cost):u(u),v(v),f(f),c(c),cost(cost){}
};
vector<Flow> G;
vector<int> edges[maxn<<1];
bool bfs()
{
	queue<int> q;
	memset(vis,false,sizeof vis);
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=N;i++)
		a[i]=d[i]=1e8;
	d[S]=0;vis[S]=true;
	q.push(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=false;
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			if(e.c>e.f&&d[e.v]>d[u]+e.cost)
			{
				d[e.v]=d[u]+e.cost;
				pre[e.v]=edges[u][i];
				a[e.v]=min(a[e.u],e.c-e.f);
				if(!vis[e.v])
				{
					q.push(e.v);
					vis[e.v]=true;
				}
			}
		}
	}
	return d[T]!=1e8;
}
void ek()
{
	while(bfs())
	{
		int t=T;
		while(t!=S)
		{
			Flow &e=G[pre[t]];
			Flow &fe=G[pre[t]^1];
			e.f+=a[T];fe.f-=a[T];
			t=e.u;
		}
		ans_flow+=a[T];
		ans_cost+=d[T]*a[T];
	}
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&T);
	for(int i=1;i<=M;i++)
	{
		int u,v,w,f;scanf("%d%d%d%d",&u,&v,&w,&f);
		G.push_back(Flow(u,v,0,w,f));
		edges[u].push_back(cnt++);
		G.push_back(Flow(v,u,w,w,-f));
		edges[v].push_back(cnt++);
	}
	ek();
	printf("%d %d\n",ans_flow,ans_cost);

//	system("pause");
}

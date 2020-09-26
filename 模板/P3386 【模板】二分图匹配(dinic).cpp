#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2010;
int N1,N2,M,cnt=0,vis[maxn],d[maxn],cur[maxn];
long long ans=0;
struct Flow
{
	int u,v,f,c;
	Flow(int u,int v,int f,int c):u(u),v(v),f(f),c(c){}
};
vector<Flow> G;
vector<int> edges[maxn];
bool bfs()
{
	queue<int>q;
	memset(vis,false,sizeof vis);
	d[0]=0;
	vis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			if(!vis[e.v]&&e.c>e.f)
			{
				vis[e.v]=true;
				d[e.v]=d[u]+1;
				q.push(e.v);
			}
		}
	}
	return vis[N1+N2+1];
}
int dfs(int u,int a)
{
	if(u==N1+N2+1||a==0) return a;
	int f,flow=0;
	for(int &i=cur[u];i<edges[u].size();i++)
	{
		Flow &e=G[edges[u][i]];
		if(d[e.v]==d[u]+1&&((f=dfs(e.v,min(a,e.c-e.f)) )>0) )
		{
			e.f+=f;
			G[edges[u][i]^1].f-=f;
			flow+=f;
			a-=f;
			if(a==0) break;
		}
	}
	return flow;
}
void dinic()
{
	while(bfs())
	{
		memset(cur,0,sizeof cur);
		ans+=dfs(0,1e8);
	}
}
int main()
{
//	freopen("testdata.in","r",stdin);
//	freopen("11.txt","w",stdout);
	scanf("%d%d%d",&N1,&N2,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(u>N1||v>N2) continue;
		G.push_back(Flow(u,v+N1,0,1));
		edges[u].push_back(cnt++);
		G.push_back(Flow(v+N1,u,1,1));
		edges[v+N1].push_back(cnt++);
	}
	for(int i=1;i<=N1;i++)
	{
		G.push_back(Flow(0,i,0,1));
		edges[0].push_back(cnt++);
		G.push_back(Flow(i,0,1,1));
		edges[i].push_back(cnt++);
	}
	for(int i=N1+1;i<=N1+N2;i++)
	{
		G.push_back(Flow(i,N1+N2+1,0,1));
		edges[i].push_back(cnt++);
		G.push_back(Flow(N1+N2+1,i,1,1));
		edges[N1+N2+1].push_back(cnt++);
	}
	dinic();
	printf("%lld\n",ans);

//	system("pause");
}
/*
5 4 8
1 1 
2 1
2 3
3 2
3 3
3 4
4 3
5 3
*/
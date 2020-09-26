#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=10010;
struct Flow
{
	int u,v,f,c;
	Flow(int u,int v,int f,int c):u(u),v(v),f(f),c(c){}
};
int N,M,S,T,cnt=0,vis[maxn],d[maxn],cur[maxn],ans=0;
vector<Flow> G;
vector<int> edges[maxn];
bool bfs()
{
	queue<int>q;
	memset(vis,0,sizeof vis);
	q.push(S);
	vis[S]=1;
	d[S]=0;
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
	return vis[T];
}
int dfs(int u,int a)
{
	if(u==T||a==0) return a;
	int flow=0,f;
	for(int &i=cur[u];i<edges[u].size();i++)
	{
		Flow &e=G[edges[u][i]];
		if(d[e.v]==d[u]+1&&( (f=dfs(e.v,min(a,e.c-e.f))) >0))
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
		ans+=dfs(S,1e8);
	}
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&T);
	for(int i=1;i<=M;i++)
	{
		int u,v,c;scanf("%d%d%d",&u,&v,&c);
		G.push_back(Flow(u,v,0,c));
		edges[u].push_back(cnt++);
		G.push_back(Flow(v,u,c,c));
		edges[v].push_back(cnt++);
	}
	dinic();
	printf("%d\n",ans);

//	system("pause");
}
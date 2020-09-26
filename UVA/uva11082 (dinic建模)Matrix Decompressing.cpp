#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=110;
int T,R,C,a[21],b[21],cnt=0,ans[21][21],vis[45],d[45],cur[45];
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
	memset(vis,0,sizeof vis);
	vis[0]=1;
	d[0]=0;
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
	return vis[R+C+1];
}
int dfs(int u,int a)
{
	if(u==R+C+1||a==0) return a;
	int f,flow=0;
	for(int &i=cur[u];i<edges[u].size();i++)
	{
		Flow &e=G[edges[u][i]];
		if(d[e.v]==d[u]+1&&((f=dfs(e.v,min(a,e.c-e.f)))>0))
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
		int k=dfs(0,1e8);
	}
	for(int i=1;i<=R;i++)
	{
		for(int j=0;j<edges[i].size();j++)
		{
			Flow e=G[edges[i][j]];
			if(e.v>R&&e.v<=R+C)
				ans[i][e.v-R]=e.f;
		}
	}
}
void init()
{
	G.clear();
	for(int i=0;i<=50;i++)
		edges[i].clear();
	cnt=0;
}
int main()
{
	int Cas=0;
	scanf("%d",&T);
	while(T--)
	{
		if(Cas) printf("\n");
		init();
		scanf("%d%d",&R,&C);
		for(int i=1;i<=R;i++) scanf("%d",&a[i]);
		for(int i=1;i<=C;i++) scanf("%d",&b[i]);
		for(int i=R;i>1;i--) a[i]=a[i]-a[i-1];
		for(int i=C;i>1;i--) b[i]=b[i]-b[i-1];
		for(int i=1;i<=R;i++) a[i]-=C;
		for(int i=1;i<=C;i++) b[i]-=R;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
			{
				G.push_back(Flow(i,j+R,0,19));
				edges[i].push_back(cnt++);
				G.push_back(Flow(j+R,i,19,19));
				edges[j+R].push_back(cnt++);
			}
		for(int i=1;i<=R;i++)
		{
			G.push_back(Flow(0,i,0,a[i]));
			edges[0].push_back(cnt++);
			G.push_back(Flow(i,0,a[i],a[i]));
			edges[i].push_back(cnt++);
		}
		for(int j=1;j<=C;j++)
		{
			G.push_back(Flow(j+R,C+R+1,0,b[j]));
			edges[j+R].push_back(cnt++);
			G.push_back(Flow(C+R+1,j+R,b[j],b[j]));
			edges[C+R+1].push_back(cnt++);
		}
		dinic();
		printf("Matrix %d\n",++Cas);
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
			{
				printf("%d",ans[i][j]+1);
				if(j<C) printf(" ");
			}
			printf("\n");
		}
	}
}
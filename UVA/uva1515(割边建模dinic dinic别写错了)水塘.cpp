#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=3000;
int T,w,h,cost[3],cnt=0,dep[maxn],cur[maxn];	//0为cao->dong 1为dong->cao 2为边界
ll ans=0;
const int Fx[4]={0,1,0,-1},Fy[4]={1,0,-1,0};
bool vis[maxn];
struct Flow
{
	int u,v,c,f;
	Flow(int u,int v,int c,int f):u(u),v(v),c(c),f(f){}
};
vector<Flow>G;
vector<int>edges[maxn];
char s[55][55];
bool bfs()
{
	memset(vis,false,sizeof vis);
	queue<int>q;
	dep[w*h]=0;
	vis[w*h]=true;
	q.push(w*h);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			if(!vis[e.v]&&e.c>e.f)
			{
				dep[e.v]=dep[u]+1;
				vis[e.v]=true;
				q.push(e.v);
			}
		}
	}
	return vis[w*h+1];
}
int dfs(int u,int a)
{
	if(u==w*h+1||a==0) return a;
	int f,flow=0;
	for(int &i=cur[u];i<edges[u].size();i++)
	{
		Flow &e=G[edges[u][i]];
		if(dep[u]+1==dep[e.v]&&( (f=dfs(e.v,min(a,e.c-e.f)))>0))
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
		ans+=dfs(w*h,1e9);
	}
}
void init()
{
	ans=cnt=0;
	G.clear();
	for(int i=0;i<=w*h+1;i++) edges[i].clear();
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&w,&h);
		init();
		for(int i=0;i<3;i++) scanf("%d",&cost[i]);
		for(int i=0;i<h;i++)
			scanf("%s",s[i]);
		for(int i=0;i<h;i++)
		{
			if(i==0||i==h-1)
				for(int j=0;j<w;j++)
				{
					int now=i*w+j;
					G.push_back(Flow(w*h,now,1e9,0));
					edges[w*h].push_back(cnt++);
					G.push_back(Flow(now,w*h,0,0));
					edges[now].push_back(cnt++);
					if(s[i][j]=='.'){ans+=cost[1];s[0][j]='#';}
				}
			else
			{
				int now=i*w;
				G.push_back(Flow(w*h,now,1e9,0));
				edges[w*h].push_back(cnt++);
				G.push_back(Flow(now,w*h,0,0));
				edges[now].push_back(cnt++);
				if(s[i][0]=='.'){ans+=cost[1];s[i][0]='#';}
				now=i*w+w-1;
				G.push_back(Flow(w*h,now,1e9,0));
				edges[w*h].push_back(cnt++);
				G.push_back(Flow(now,w*h,0,0));
				edges[now].push_back(cnt++);
				if(s[i][w-1]=='.'){ans+=cost[1];s[i][w-1]='#';}
			}
			
		}
		for(int i=1;i<h-1;i++)
			for(int j=1;j<w-1;j++)
			{
				int now=i*w+j;
/*
				if(i==0||i==h-1||j==0||j==w-1)
				{
					G.push_back(Flow(w*h,now,1e9,0));
					edges[w*h].push_back(cnt++);
					G.push_back(Flow(now,w*h,0,0));
					edges[now].push_back(cnt++);
					if(s[i][j]=='.')
					{
						G.push_back(Flow(now,w*h+1,cost[1],0));
						edges[now].push_back(cnt++);
						G.push_back(Flow(w*h+1,now,0,0));
						edges[w*h+1].push_back(cnt++);
					}
				}
*/
//				else
				if(s[i][j]=='#')
				{
					G.push_back(Flow(w*h,now,cost[0],0));
					edges[w*h].push_back(cnt++);
					G.push_back(Flow(now,w*h,0,0));
					edges[now].push_back(cnt++);
				}
				else if(s[i][j]=='.')
				{
					G.push_back(Flow(now,w*h+1,cost[1],0));
					edges[now].push_back(cnt++);
					G.push_back(Flow(w*h+1,now,0,0));
					edges[w*h+1].push_back(cnt++);
				}
		}
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				int now1=i*w+j;
				for(int k=0;k<4;k++)
				{
					int nx=i+Fx[k],ny=j+Fy[k];
					if(nx<0||nx>=h||ny<0||ny>=w) continue;
					int now2=nx*w+ny;
					G.push_back(Flow(now1,now2,cost[2],0));
					edges[now1].push_back(cnt++);
					G.push_back(Flow(now2,now1,0,0));
					edges[now2].push_back(cnt++);
				}
			}
		dinic();
		printf("%lld\n",ans);	
	}
//	system("pause");
}
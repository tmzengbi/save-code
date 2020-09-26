#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct Edges
{
	int u,v,d;
	Edges(int u=0,int v=0,int d=0):u(u),v(v),d(d){	}
};
struct node
{
	int u,d;
	node(int u,int d):u(u),d(d){	}
	bool operator < (const node& rhs) const
	{
		return d>rhs.d;
	}
};
const int maxn=1000000+10;
int n,m,s,dis[maxn];
bool vis[maxn];
vector <Edges> edges;
vector <int> G[maxn];
void init();
int read();
int main()
{
	n=read();m=read();s=read();
	init();
	for(int i=1;i<=m;i++)
	{
		int t1=read(),t2=read(),t3=read();
		edges.push_back(Edges(t1,t2,t3));
		G[t1].push_back(i-1);
	}
	dis[s]=0;
	priority_queue<node> q;
	q.push(node(s,0));
	while(!q.empty())
	{
		node nod=q.top();
		q.pop();
		int x=nod.u,k=G[x].size();
		if(vis[x]) continue;
		vis[x]=true;
		for(int j=0;j<k;j++)
		{
			Edges e=edges[G[x][j]];
			if(dis[e.v]>dis[x]+e.d)
			{
				dis[e.v]=dis[x]+e.d;
				q.push(node(e.v,dis[e.v]));
			}
		}
		
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
}
void init()
{
	edges.clear();
	for(int i=0;i<n;i++)
		G[i].clear(); 
	for(int i=1;i<=n;i++)
		dis[i]=2147483647;
	memset(vis,false,sizeof vis);
}
int read()
{
	int f=1,shu=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}

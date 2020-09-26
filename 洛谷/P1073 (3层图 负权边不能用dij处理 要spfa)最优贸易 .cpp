#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int N,M,dist[300010];
bool vis[300010];
struct Node
{
	int u,v,d;
	Node(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Node> G;
vector<int> edges[300010];
int spfa(int from,int to)
{
	for(int i=1;i<=N*3;i++)
		dist[i]=1e6;
	memset(vis,false,sizeof vis);
	vis[from]=true;dist[from]=0;
	queue<int> q;
	q.push(from);
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
			if((d+dist[u])<dist[v])
			{
				dist[v]=d+dist[u];
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dist[N*3];
}
int main()
{
	int cnt=0;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		int val;scanf("%d",&val);
		G.push_back(Node(i,i+N,val));
		edges[i].push_back(cnt++);
		G.push_back(Node(i+N,i+2*N,-val));
		edges[i+N].push_back(cnt++);
	}
	for(int i=1;i<=M;i++)
	{
		int u,v,r;
		scanf("%d%d%d",&u,&v,&r);
		for(int t=0;t<3;t++)
		{	
			G.push_back(Node(u+N*t,v+N*t,0));
			edges[u+N*t].push_back(cnt);
			if(r==2)
//				G.push_back(Node(u+N*t,v+N*t,0));
				edges[v+N*t].push_back(cnt);
			cnt++;
		}
	}
	printf("%d\n",-spfa(1,N*3));
/*
	for(int i=1;i<=3*N;i++)
	{
		printf("%d %d ",i,edges[i].size());
		for(int j=0;j<edges[i].size();j++)
		{
			int v=G[edges[i][j]].v;
			if(v==i) v=G[edges[i][j]].u;
			printf(" %d",v);
		}
		printf("\n");
	}
*/
//	system("pause");
}
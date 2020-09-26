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
vector<Edges> Edge;
vector<int> edges[1005];
int dis[1005];
bool vis[1005];
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		dis[i]=0xfffffff;
		vis[i]=false;
	}
	for(int i=1;i<=m;i++)
	{
		int uu,vv,dd;
		cin>>uu>>vv>>dd;
		Edge.push_back(Edges(uu,vv,dd));
		edges[uu].push_back(i-1);
	}
	queue<int> q;
	q.push(s);
	vis[s]=true;
	dis[s]=0;
	while(!q.empty())
	{
		int st=q.front();q.pop();
		vis[s]=false;
		int len=edges[st].size();
		for(int i=0;i<len;i++)
		{
			Edges e=Edge[edges[st][i]];
			if(dis[e.v]>dis[e.u]+e.d)
			{
				dis[e.v]=dis[e.u]+e.d;
				if(!vis[e.v])
				{
					q.push(e.v);
					vis[e.v]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	
}

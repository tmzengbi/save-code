#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Flow
{
	int u,v,c,f,cost;
	Flow(int u,int v,int c,int f,int cost):u(u),v(v),c(c),f(f),cost(cost){}
};
int n,dist[110][110],a[110],pre[110],d[110];
bool vis[110];
vector<int> low_node,up_node;
vector<Flow> G;
vector<int>edges[110];
bool bfs()
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n+1;i++)
		d[i]=1e7;
	queue<int>q;
	q.push(0);
	vis[0]=true;
	a[0]=1e7;d[0]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=false;
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			if(e.cost+d[u]<d[e.v]&&e.f<e.c)
			{
				d[e.v]=d[u]+e.cost;
				a[e.v]=min(a[u],e.c-e.f);
				pre[e.v]=edges[u][i];
				if(!vis[e.v])
				{
					vis[e.v]=true;
					q.push(e.v);
				}
			}
		}
	}
	return d[n+1]!=1e7;
}
int ek()
{
	int sum=0;
	while(bfs())
	{
		int cur=n+1,k=a[n+1];
/*
		for(int i=1;i<=n+1;i++)
			cout<<G[pre[i]].u<<" "<<G[pre[i]].v<<endl;
		cout<<k<<endl;
		system("pause");
*/
		while(cur)
		{
			Flow &e=G[pre[cur]],&fe=G[pre[cur]^1];
			e.f+=k;fe.f-=k;
			cur=e.u;
		}
		sum+=d[n+1]*k;
	}
	return sum;
}
int main()
{
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			dist[j][i]=dist[i][j]=min(j-i,i+n-j);
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<sum) low_node.push_back(i);
		if(a[i]>sum) up_node.push_back(i);
	}
	int cnt=0;
	for(int i=0;i<up_node.size();i++)
		for(int j=0;j<low_node.size();j++)
		{
			int u=up_node[i],v=low_node[j];
			G.push_back(Flow(u,v,1e7,0,dist[u][v]));
			edges[u].push_back(cnt++);
			G.push_back(Flow(v,u,1e7,1e7,-dist[u][v]));
			edges[v].push_back(cnt++);
		}
	for(int i=0;i<up_node.size();i++)
	{
		int v=up_node[i];
		G.push_back(Flow(0,v,a[v]-sum,0,0));
		edges[0].push_back(cnt++);
		G.push_back(Flow(v,0,a[v]-sum,a[v]-sum,0));
		edges[v].push_back(cnt++);
	}
	for(int i=0;i<low_node.size();i++)
	{
		int v=low_node[i];
		G.push_back(Flow(v,n+1,sum-a[v],0,0));
		edges[v].push_back(cnt++);
		G.push_back(Flow(n+1,v,sum-a[v],sum-a[v],0));
		edges[n+1].push_back(cnt++);
	}
	int ans=ek();
	printf("%d\n",ans);

	system("pause");
}
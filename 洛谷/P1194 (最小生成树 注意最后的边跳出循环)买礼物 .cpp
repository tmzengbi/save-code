#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int A,B,Map[510][510];
bool vis[510];
struct edge
{
	int u,d;
	edge(int u,int d):u(u),d(d){}
	bool operator < (const edge E) const
	{
		return d>E.d;
	}
};
int work()
{
	int ans=0,cnt=0;
	for(int i=1;i<=B;i++)
	{
		if(vis[i]) continue;
		priority_queue<edge> q;
		ans+=A;
		q.push(edge(i,0));
		while(!q.empty()&&cnt<B)
		{
			edge E=q.top();q.pop();
			int u=E.u;
			if(vis[u]) continue;
			vis[u]=true;ans+=E.d;cnt++;
			for(int v=1;v<=B;v++)
			{
				if(vis[v]) continue;
				if(Map[u][v]==0||Map[u][v]>A) continue;
				q.push(edge(v,Map[u][v]));
			}
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d",&A,&B);
	memset(vis,false,sizeof vis);
	for(int i=1;i<=B;i++)
		for(int j=1;j<=B;j++)
			scanf("%d",&Map[i][j]);
	printf("%d\n",work());

//	system("pause");
}
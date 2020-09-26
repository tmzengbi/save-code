#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;
}n[1010];
int N;
double dist[1010][1010],dp[1010][1010];
double getdist(Node x,Node y)
{
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double dfs(int i,int j)
{
	if(dp[i][j])return dp[i][j];
	if(i==j) return 1e8;
	if(i==N-1) return dist[i][N]+dist[j][N];
	dp[i][j]=min(dfs(i+1,j)+dist[i][i+1],dfs(i+1,i)+dist[j][i+1]);
	return dp[i][j];
}
int main()
{
	while(scanf("%d",&N)==1)
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<=N;i++)
			scanf("%d%d",&n[i].x,&n[i].y);
		for(int i=1;i<N;i++)
			for(int j=i+1;j<=N;j++)
				dist[i][j]=getdist(n[i],n[j]);
		printf("%.2lf\n",dfs(2,1)+dist[1][2]);
	}
	
}
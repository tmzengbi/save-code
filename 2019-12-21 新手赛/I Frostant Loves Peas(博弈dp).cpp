#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int N,a[100010],dp[100010][2],sum=0;
int dfs(int x,int k)
{
	if(x==N)
	{
		if(k==0) return a[N];
		else return 0;
	}
	if(dp[x][k]>-1) return dp[x][k];
	if(a[x]>1)
	{
		if(dfs(x+1,0)+a[x]-1>dfs(x+1,1)+a[x])
		{
			dp[x][0]=dfs(x+1,0)+a[x]-1;
			dp[x][1]=dfs(x+1,1)+1;
		}
		else
		{
			dp[x][0]=dfs(x+1,1)+a[x];
			dp[x][1]=dfs(x+1,0);
		}
	}
	else if(a[x]==1)
	{
		dp[x][0]=dfs(x+1,1)+1;
		dp[x][1]=dfs(x+1,0);
	}
	return dp[x][k];
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",dfs(1,0)-dfs(1,1));
//	for(int i=1;i<=N;i++)
//		printf("%d %d\n",dp[i][0],dp[i][1]);
	system("pause");
}
/*
3
3 1 2

10
1 2 1 2 1 2 1 2 1 2
*/
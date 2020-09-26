#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dp[5010][5010],v[5050],N;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&v[i]);
	for(int i=N-1;i>=1;i--)
	{
		for(int j=1;j+i<=N;j++)
		{
			int s=0;
			if((i+1)%2==0)
			{
				dp[j+1][j+i]=max(dp[j+1][j+i],dp[j][j+i]+v[j]);
				dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][j+i]+v[i+j]);
			}
			else
			{
				dp[j+1][j+i]=max(dp[j+1][j+i],dp[j][j+i]);
				dp[j][j
				+i-1]=max(dp[j][j+i-1],dp[j][j+i]);
			}
		}
	}
	for(int i=1;i<=N;i++)
		printf("%d\n",dp[i][i]);

	system("pause");
}
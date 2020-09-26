#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1010;
const int p=19650827;
int h[maxn],dp[maxn][maxn][2],n;//0是左边 1是右边
int main()
{
	memset(dp,0,sizeof dp);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
		dp[i][i][0]=1;
	for(int k=1;k<n;k++)
		for(int i=1;i+k<=n;i++)
		{
			dp[i][i+k][0]+=(dp[i+1][i+k][0]*(h[i]<h[i+1])+dp[i+1][i+k][1]*(h[i]<h[i+k]))%p;
			dp[i][i+k][1]+=(dp[i][i+k-1][0]*(h[i]<h[i+k])+dp[i][i+k-1][1]*(h[i+k-1]<h[i+k]))%p;
		}
		
	printf("%d\n",(dp[1][n][0]+dp[1][n][1])%p);
//	for(int i=1;i<n;i++)
//		for(int j=i;j<=n;j++)
//			printf("%d %d\t%d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
//	system("pause");			
}
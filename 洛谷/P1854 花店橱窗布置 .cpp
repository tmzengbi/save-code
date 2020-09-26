#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,M,m[110][110],dp[110][110],pre[110][110];
void print(int n,int k)
{
	if(n==0)return;
	print(n-1,pre[n][k]);
	printf("%d ",k);
}
int main()
{
	scanf("%d%d",&N,&M);
	memset(dp,-0x3f,sizeof dp);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%d",&m[i][j]);
	for(int i=1;i<=M;i++) dp[1][i]=m[1][i];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=i-1;k<j;k++)
			{
//				dp[i][j]=max(dp[i-1][k]+m[i][j],dp[i][j]);
				if(dp[i-1][k]+m[i][j]>dp[i][j])
				{
					dp[i][j]=dp[i-1][k]+m[i][j];
					pre[i][j]=k;
				}
			}
//	for(int j=1;j<=N;j++)
//	{
//	for(int i=1;i<=M;i++)
//		printf("%d ",dp[j][i]);
//	printf("\n");
	int mk=0,Max=0;
	for(int i=1;i<=M;i++)
		if(Max<dp[N][i])
		{
			Max=dp[N][i];
			mk=i;
		}
	printf("%d\n",Max);
	print(N,mk);
//	system("pause");
}
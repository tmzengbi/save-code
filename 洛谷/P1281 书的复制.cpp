#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[550][550],n,K,a[550],sum[550],pre[550][550],ans;
void print(int x)
{
	if(x==0) return;
	for(int i=x;i>=0;i--)
	{
		if(sum[x]-sum[i-1]>ans||i==0)
		{
			print(i);
			printf("%d %d\n",i+1,x);
			break;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++) dp[i][0]=sum[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<i&&j<K;j++)
			for(int k=i-1;k>j;k--)
			{
				int Max=max(dp[k][j-1],sum[i]-sum[k]);
				if(dp[i][j]>=Max)
				{
					dp[i][j]=Max;
					pre[i][j]=k+1;
				}
			}
	ans=dp[n][K-1];
//	printf("%d\n",dp[n][K-1]);
	print(n);
//	system("pause");
}
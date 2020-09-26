#include<iostream>
#include<cstdio>
using namespace std;
const int inf=1e9;
int n,a[110],dp[110][110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
/*	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n-1;j++)
		{
			if(i==j)	{dp[i][j]=0;continue;}
			else dp[i][j]=inf;
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1],dp[i][j]);
		}
	}
*/
	for(int i=1;i<n;++i)
	{
		dp[i][i]=0;
		for(int j=i+1;j<n;j++)
			dp[i][j]=inf;
	}
	for(int k=1;k<n-1;k++)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=i+k;j++)
				dp[i][i+k]=min(dp[i][j-1]+dp[j][i+k]+a[i]*a[j]*a[i+k+1],dp[i][i+k]);
		}
	}
//	printf("%d\n",dp[1][n-1]);
/*	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n-1;j++)
			cout<<i<<" "<<j<<" "<<"\t"<<dp[i][j]<<endl;
	}
*/
	printf("%d\n",dp[1][n-1]);
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int m,n,M[510][510],dp[510][510],f[510][510],sum[510];
int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<m;i++)
	{
		int d;cin>>d;
		sum[i+1]=sum[i]+d;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=1e8;
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
			M[j][i]=M[i][j]=sum[j]-sum[i];
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
		{
			int mid=(i+j)>>1;
			for(int k=i;k<=j;k++)
				f[i][j]+=M[k][mid];
		}
	dp[1][1]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=i&&j<=n;j++)
		{
			if(j==1) dp[i][j]=f[1][i];
			else
				for(int k=1;k<i;k++)
					dp[i][j]=min(dp[i][j],dp[k][j-1]+f[k+1][i]);
		}
/*
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
*/
/*
	for(int i=1;i<=m;i++)
		for(int j=1;j<=i&&j<=n;j++)
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
*/
	printf("%d\n",dp[m][n]);
//	system("pause");
}
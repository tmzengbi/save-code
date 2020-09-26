#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=310;
int g[maxn][maxn];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	for(int i=1;i<=300;i++)	
		for(int j=1;j<=300;j++)
			g[i][j]=gcd(i,j);
	int n,m,dp[maxn][maxn];
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(g[i][j]==1);
//				printf("%d %d %d\n",i,j,dp[i][j]);
			}
		ll sum=0;
		for(int i=1,ii=n-2;i<n;i++,ii--)	
			for(int j=1,jj=m-2;j<m;j++,jj--)
				sum+=dp[i][j]-dp[min(ii,i)][min(jj,j)];
		printf("%lld\n",sum*2);
	}
}
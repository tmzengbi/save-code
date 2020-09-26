#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e9;
template<typename T>
T min(T a,T b,T c)
{
	return min(min(a,b),c);
}
char str[55];
int n,dp[55][55];
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1;
		for(int j=i+1;j<=n;j++)
			dp[i][j]=maxn;
	}
	for(int k=1;k<n;k++)
		for(int i=1;i+k<=n;i++)
		{
			if(str[i]==str[i+k])
				dp[i][i+k]=min(dp[i][i+k-1],dp[i+1][i+k]);
			else
				for(int j=i;j<i+k;j++)
					dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);
		}
	printf("%d\n",dp[1][n]);
//	system("pause");
}
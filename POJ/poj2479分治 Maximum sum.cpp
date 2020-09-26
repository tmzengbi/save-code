#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,N,K,dp[50010][2],ans[50010][2],a[50010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		memset(dp,-0x3f,sizeof dp);
		memset(ans,-0x3f,sizeof ans);
		for(int i=1;i<=N;i++)
		{
			dp[i][0]=max(0,dp[i-1][0])+a[i];
			ans[i][0]=max(dp[i][0],ans[i-1][0]);
		}
		for(int i=N;i>=1;i--)
		{
			dp[i][1]=max(0,dp[i+1][1])+a[i];
			ans[i][1]=max(dp[i][1],ans[i+1][1]);
		}
		int anss=-1e9;
		for(int i=1;i<N;i++)
			anss=max(ans[i][0]+ans[i+1][1],anss);
		printf("%d\n",anss);
	}
//	system("pause");
}
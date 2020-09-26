#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,T,M1,Left[55],M2,Right[55],dp[55][210],d[55][55],kase=0;
bool havetrain[55][210][2];
void solve()
{
	for(int i=1;i<=N;i++) dp[i][T]=1e9;
	dp[N][T]=0;
	for(int i=T-1;i>=0;i--)
		for(int j=1;j<=N;j++)
		{
			dp[j][i]=dp[j][i+1]+1;
			if(j<N&&havetrain[j][i][0]&&i+d[j][j+1]<=T)
				dp[j][i]=min(dp[j][i],dp[j+1][i+d[j][j+1]]);
			if(j>1&&havetrain[j][i][1]&&i+d[j-1][j]<=T)
				dp[j][i]=min(dp[j][i],dp[j-1][i+d[j-1][j]]);
		}
	printf("Case Number %d: ",++kase);
	if(dp[1][0]>=1e9) printf("impossible\n");
	else printf("%d\n",dp[1][0]);
}
int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		memset(havetrain,0,sizeof havetrain);
		scanf("%d",&T);
		for(int i=1;i<N;i++) scanf("%d",&d[i][i+1]);
		for(int i=2;i<N;i++)
			for(int j=1;j+i<=N;j++)
				d[j][j+i]=d[j][j+i-1]+d[j+i-1][j+i];
		scanf("%d",&M1);
		for(int i=1;i<=M1;i++) scanf("%d",&Left[i]);
		scanf("%d",&M2);
		for(int i=1;i<=M2;i++) scanf("%d",&Right[i]);

		for(int i=1;i<=M1;i++)
			for(int j=1;j<=N;j++)
				if(Left[i]+d[1][j]<=T)
					havetrain[j][Left[i]+d[1][j]][0]=1;
		for(int i=1;i<=M2;i++)
			for(int j=1;j<=N;j++)
				if(Right[i]+d[j][N]<=T)
					havetrain[j][Right[i]+d[j][N]][1]=1;
		solve();
	}
//	system("pause");
}
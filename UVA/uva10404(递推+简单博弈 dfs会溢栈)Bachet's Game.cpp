#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,M,a[11],dp[1000010];
int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=M;i++) scanf("%d",&a[i]);
		dp[0]=0;
		for(int i=0;i<=N;i++)
		{
			if(dp[i]==-1) continue;
			for(int j=1;j<=M;j++)
			{
				if(i+a[j]>N) continue;
				if(dp[i+a[j]]==-1&&dp[i]==1) dp[i+a[j]]=0;
				else if(dp[i]==0) dp[i+a[j]]=1;
			}
		}
		bool win=dp[N];
		if(win) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
}
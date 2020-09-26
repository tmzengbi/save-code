#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,K,zt[1<<9],nbit[1<<9];
long long dp[10][1<<9][110];
int main()
{
	memset(nbit,0,sizeof nbit);
	scanf("%d%d",&N,&K);
	for(int i=0;i<(1<<N);i++)
	{
		zt[i]=0;
		for(int j=0;j<N;j++)
		{
			if((i>>j)&1)	nbit[i]++;
			if(((i>>j)&3)==3)	zt[i]=1;
		}
		if(!zt[i])	dp[1][i][nbit[i]]=1;
	}
		
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<(1<<N);j++)
		{
			if(zt[j])	continue;
			for(int k=0;k<(1<<N);k++)
			{
				if(j&k)	continue;
				if((j>>1)&k)	continue;
				if(j&(k>>1))	continue;
				for(int t=0;t+nbit[j]<=K;t++)
					dp[i][j][t+nbit[j]]+=dp[i-1][k][t];
			}
		}
	}
	long long ans=0;
//	for(int dep=1;dep<=N;dep++)
	for(int i=0;i<(1<<N);i++)
		ans+=dp[N][i][K];
	//	cout<<dp[dep][i][K]<<" ";
//		cout<<zt[i]<<" ";
//	cout<<endl;
	cout<<ans<<endl;
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=9999973;
int N,M;
ll dp[101][101][101],c[101][3];
int main()
{
	scanf("%d%d",&N,&M);
	memset(dp,0,sizeof dp);
	for(int i=1;i<=M;i++)
	{
		c[i][0]=1;
		c[i][1]=i;
		c[i][2]=i*(i-1)/2;
	}
	for(int i=0;i<=2;i++)
		dp[1][i][0]=c[M][i];
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			for(int k=0;j+k<=M;k++)
			{
				if(dp[i-1][j][k]==0)	continue;
				dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;	//不放
				if(M-j-k)
					dp[i][j+1][k]=(dp[i][j+1][k]+dp[i-1][j][k]*(M-j-k))%mod;
				if(j)
					dp[i][j-1][k+1]=(dp[i][j-1][k+1]+dp[i-1][j][k]*j)%mod;	//放一个
				if(j>=2)
					dp[i][j-2][k+2]=(dp[i][j-2][k+2]+dp[i-1][j][k]*c[j][2])%mod;
				if((M-j-k)>=2)	
					dp[i][j+2][k]=(dp[i][j+2][k]+dp[i-1][j][k]*c[M-j-k][2])%mod;
				if((M-j-k)>0&&j>0)
					dp[i][j][k+1]=(dp[i][j][k+1]+dp[i-1][j][k]*j*(M-j-k))%mod;	//放两个
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=M;i++)
		for(int j=0;i+j<=M;j++)
			ans=(ans+dp[N][i][j])%mod;
	cout<<ans<<endl;
//	}
	system("pause");
}
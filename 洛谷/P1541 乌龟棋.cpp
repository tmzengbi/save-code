#include<iostream>
#include<cstdio>
using namespace std;
int N,M,a[355],m[5]={0},dp[45][45][45][45];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=M;i++)
	{
		int tmp;scanf("%d",&tmp);
		m[tmp]++;
	}
	for(int i=0;i<=m[1];i++)
		for(int j=0;j<=m[2];j++)
			for(int k=0;k<=m[3];k++)
				for(int d=0;d<=m[4];d++)
				{
					int Max=0,r=1+i+j*2+k*3+d*4;
					if(i>0)	Max=max(Max,dp[i-1][j][k][d]+a[r]);
					if(j>0)	Max=max(Max,dp[i][j-1][k][d]+a[r]);
					if(k>0)	Max=max(Max,dp[i][j][k-1][d]+a[r]);
					if(d>0)	Max=max(Max,dp[i][j][k][d-1]+a[r]);	
					if(i==0&&j==0&&k==0&&d==0)	dp[i][j][k][d]=a[1];
					else	dp[i][j][k][d]=Max;
				}
	printf("%d\n",dp[m[1]][m[2]][m[3]][m[4]]);
//	system("pause");
}
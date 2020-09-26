#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=1e9;
int L,N,p[55],dp[55][55];
int main()
{
	while(true)
	{
		scanf("%d",&L);
		if(L==0)	return 0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",&p[i+1]);
		p[1]=0;p[N+2]=L;
		for(int i=1;i<N+2;i++)
			for(int j=i+1;j<=N+2;j++)
				dp[i][j]=inf;
		for(int k=1;k<N+2;k++)
		{
			for(int i=1;i+k<=N+2;i++)
			{
				if(k==1)	dp[i][i+k]=0;
				else
					for(int j=i+1;j<i+k;j++)
						dp[i][i+k]=min(dp[i][j]+dp[j][i+k]+p[i+k]-p[i],dp[i][i+k]);
			}
		}
/*	for(int i=1;i<N+2;i++)
		for(int j=i+1;j<=N+2;j++)
			cout<<i<<" "<<" "<<j<<"\t"<<dp[i][j]<<endl;	
*/		


		printf("The minimum cutting is %d.\n",dp[1][N+2]);
	}

}
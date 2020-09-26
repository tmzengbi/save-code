#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,M,v[110],t[110],dp[110][1010];
int main()
{
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++)
		scanf("%d%d",&t[i],&v[i]);
	for(int i=1;i<=M;i++)
	{
		for(int j=T;j>=0;j--)
		{		
			dp[i][j]=(i==1)?0:dp[i-1][j];
			if(j>=t[i])
				dp[i][j]=max(dp[i][j],dp[i-1][j-t[i]]+v[i]);
		}
	}
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=T;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}

	cout<<dp[M][T]<<endl;
	system("pause");
}

/*
10 5
1 1
5 9
3 5
7 10
9 15
*/
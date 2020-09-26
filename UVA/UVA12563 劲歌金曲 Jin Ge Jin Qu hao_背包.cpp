#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int jm=678;
int n,t,m[55],dp[55][180*55+678];
int main()
{
	memset(dp,0,sizeof dp);
	int tt;
	scanf("%d",&tt);
	for(int ttt=1;ttt<=tt;ttt++)
	{
		scanf("%d%d",&n,&t);
		for(int i=1;i<=n;i++)
			scanf("%d",&m[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=t;j++)
			{ 
				dp[i][j]=dp[i-1][j];
				if(j-m[i]==0||dp[i-1][j-m[i]]!=0&&j>=m[i])
					dp[i][j]=max(dp[i][j],dp[i-1][j-m[i]]+1);
			}

		}
		
/*		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=t;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
*/
		int k=0,Max=0;
		for(int i=t-1;i>=1;i--)
			if(Max<dp[n][i]){Max=dp[n][i];k=i;}
//		cout<<k<<endl;
		printf("Case %d: %d %d\n",ttt,Max+1,k+jm);
	}
	system("pause");
}
/*
1
10 15
1 1 1 1 1 1 1 1 1 15
*/
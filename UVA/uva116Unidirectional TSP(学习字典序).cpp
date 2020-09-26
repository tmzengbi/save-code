#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int N,M,Map[110][110],dp[110][110],Next[110][110];
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int Add(int a)
{
	return a==N?1:a+1;
}
int Minus(int a)
{
	return a==1?N:a-1;
}
int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(Next,0,sizeof Next);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				scanf("%d",&Map[i][j]);
		int ans=1e9,First;
		for(int i=1;i<=N;i++) 
		{
			dp[i][M]=Map[i][M];
			if(M==1&&ans>dp[i][M]){ans=dp[i][M];First=i;}
		}
		for(int i=M-1;i>=1;i--)
		{
			for(int j=1;j<=N;j++)
			{	
				dp[j][i]=1e9;
				int Row[3]={Add(j),Minus(j),j};
				sort(Row,Row+3);
				for(int k=0;k<3;k++)
					if(dp[j][i]>dp[Row[k]][i+1]+Map[j][i]){dp[j][i]=dp[Row[k]][i+1]+Map[j][i];Next[j][i]=Row[k];}
				if(i==1&&ans>dp[j][i]){ans=dp[j][i];First=j;}
			}
		}
		int now=1;
		printf("%d",First);
		while(Next[First][now])
		{
			printf(" %d",Next[First][now]);
			First=Next[First][now];
			now++;
		}
		printf("\n%d\n",ans);
	}
}
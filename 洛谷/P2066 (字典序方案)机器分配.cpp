#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,v[20][20],dp[20][20],pre[20][20];
struct Node
{
	int w,c;
	Node(int w,int c):w(w),c(c){}
};
vector<Node>vec[15];
int main()
{
	int cnt=0;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&v[i][j]);
			vec[i].push_back(Node(j,v[i][j]));
		}
	}
	for(int i=N,ii=1;i>=1;i--,ii++)
		for(int k=0;k<=M;k++)
		{
			dp[ii][k]=dp[ii-1][k];
			for(int j=vec[i].size()-1;j>=0;j--)
			{
				Node e=vec[i][j];
				if(k>=e.w&&dp[ii][k]<=dp[ii-1][k-e.w]+e.c)
				{
					dp[ii][k]=dp[ii-1][k-e.w]+e.c;
					pre[i][k]=e.w;
				}
			}
			if(dp[ii][k]<=dp[ii-1][k])
			{
				dp[ii][k]=dp[ii-1][k];
				pre[i][k]=0;
			}
		}
	printf("%d\n",dp[N][M]);
	for(int i=1,j=M;i<=N;i++)
	{
		printf("%d %d\n",i,pre[i][j]);
		j-=pre[i][j];
	}
//	system("pause");
}
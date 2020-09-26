#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=55;
int N,dp[maxn][maxn][maxn][maxn],d[22],Map[maxn][5];
int dfs(int *now,int k)
{
	int &ans=dp[now[1]][now[2]][now[3]][now[4]];
	if(ans) return ans;
	if(k>=5) return ans=0;
	for(int i=1;i<=4;i++)
	{
		if(now[i]+1>N||k+1>5) continue;
		int Next=Map[now[i]+1][i],Add1=-1,Add2=1;
		if(d[Next]==0) Add1=1,Add2=0;
		d[Next]^=1;now[i]++;
		ans=max(ans,dfs(now,k+Add1)+Add2);
		d[Next]^=1;now[i]--;
	}
	return ans;
}
int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		memset(dp,0,sizeof dp);
		memset(d,0,sizeof d);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&Map[i][j]);
		int now[5]={0};
		printf("%d\n",dfs(now,0));
	}
//	system("pause");
}
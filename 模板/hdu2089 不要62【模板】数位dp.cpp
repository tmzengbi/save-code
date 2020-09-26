#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
int dp[20][2],dig[20];
int dfs(int now,int pre,bool limit)
{
	if(now==-1) return 1;
	if(!limit&&dp[now][pre]!=-1) return dp[now][pre];
	int up=limit?dig[now]:9,sum=0;
	for(int i=0;i<=up;i++)
	{
		if(pre&&i==2) continue;
		if(i==4) continue;
		sum+=dfs(now-1,i==6,limit&&i==up);
	}
	if(!limit) dp[now][pre]=sum;
	return sum;
}
int solve(int n)
{
	if(n==-1) return 0;
	int cnt=0,ans=0;
	while(n)
	{
		dig[cnt++]=n%10;
		n/=10;
	}
	/*
	for(int i=0;i<dig[cnt-1];i++)
		ans+=dfs(cnt-1,i,false);
	ans+=dfs(cnt-1,dig[cnt-1],true);
	*/
	ans=dfs(cnt-1,0,true);
	return ans;
}
int main()
{
	int n,m;
	memset(dp,-1,sizeof dp);
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
		if(n>m) swap(n,m);
		printf("%d\n",solve(m)-solve(n-1));
	}
}
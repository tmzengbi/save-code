#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[32][2][2];int dig[2][32];
/*
ll dfs(int now1,int now2,int limit1,int limit2,int *d1,int *d2)
{
//	printf("%d %d\n",now1,now2);
//	system("pause");
	if(now1==-1&&now2==-1) return 1;
	if(dp[now1][now2][limit1][limit2]!=-1) return dp[now1][now2][limit1][limit2];
	ll sum=0;
	if(now1>now2)
	{
		int up=limit1?d1[now1]:1;
		for(int i=0;i<=up;i++)
			sum+=dfs(now1-1,now2,limit1&&i==up,limit2,d1,d2);
		dp[now1][now2][limit1][limit2]=sum;
		return sum;
	}
	else if(now1<now2)
	{
		int up=limit2?d2[now2]:1;
		for(int i=0;i<=up;i++)
			sum+=dfs(now1,now2-1,limit1,limit2&&i==up,d1,d2);
		dp[now1][now2][limit1][limit2]=sum;
		return sum;
	}
	else
	{
		int up1=limit1?d1[now1]:1,up2=limit2?d2[now2]:1;
		for(int i=0;i<=up1;i++)
			for(int j=0;j<=up2;j++)
				if(!(i&j)) sum+=dfs(now1-1,now2-1,limit1&&i==up1,limit2&&j==up2,d1,d2);
		dp[now1][now2][limit1][limit2]=sum;
		return sum;
	}
}
*/
ll dfs(int now,int lim1,int lim2,int *d1,int *d2)
{
	if(now==-1) return 1;
//	if(!lim1&&!lim2&&dp[now]!=-1) return dp[now];
	if(dp[now][lim1][lim2]!=-1) return dp[now][lim1][lim2];
	ll sum=0;
	int up1=lim1?d1[now]:1,up2=lim2?d2[now]:1;
	for(int i=0;i<=up1;i++)
		for(int j=0;j<=up2;j++)
			if(!(i&j)) sum+=dfs(now-1,lim1&&i==up1,lim2&&j==up2,d1,d2);
	dp[now][lim1][lim2]=sum;
	return sum;
}
ll solve(int a,int b)
{
	memset(dp,-1,sizeof dp);
	int cnt1=0,cnt2=0;ll sum=0;
	if(a>b) swap(a,b);
	for(int i=0;i<=30;i++)
	{
		int d=1<<i;
		dig[0][i]=(a&d)?1:0;
		dig[1][i]=(b&d)?1:0;
	}
	sum=dfs(30,1,1,dig[0],dig[1]);
	return sum;
}
int main()
{
	int a,b,t;
//	memset(dp,-1,sizeof dp);
	scanf("%d",&t);
	while(scanf("%d%d",&a,&b)==2&&t--)
	{
		if(a)printf("%lld\n",solve(b,b)-2*solve(a-1,b)+solve(a-1,a-1));
		else printf("%lld\n",solve(b,b));
	}
	
}
/*
8
1 4
323 323
1 1000000
*/
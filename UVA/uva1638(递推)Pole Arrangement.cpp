#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
ll dp[22][22][22];
ll dfs(int n,int l,int r)
{
	if(n<l||n<r) return 0;
	if(n==1)
	{
		if(l==1&&r==1) return 1;
		else return 0;
	}
	if(dp[n][l][r]!=-1) return dp[n][l][r];
	ll sum=0;
	sum=dfs(n-1,l-1,r)+dfs(n-1,l,r-1)+dfs(n-1,l,r)*(n-2);
	return dp[n][l][r]=sum;
}
int n,t,l,r;
int main()
{
	scanf("%d",&t);
	memset(dp,-1,sizeof dp);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		printf("%lld\n",dfs(n,l,r));
	}
//	system("pause");
}
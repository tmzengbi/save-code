#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
int N;
ull K,dp[110][110];
ull dfs(int n,int k)//n个球 试k次
{
	if(dp[n][k]) return dp[n][k];
	if(k>63) return -1;
	if(k==1) return 1;
	if(n==1) return k;
	dp[n][k]=dfs(n-1,k-1)+1+dfs(n,k-1);
	return dp[n][k];
}
int main()
{
	while(scanf("%d%lld",&N,&K)==2)
	{
		if(N==0) break;
		int l=1,r=64;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(dfs(N,mid)<K) l=mid+1;
			else r=mid;
		}
		if(l==64) printf("More than 63 trials needed.\n");
		else printf("%d\n",l);
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<int>prime;
int notprime[2010];
void sieve()
{
	for(int i=2;i<=1120;i++) if(!notprime[i])
	{
		prime.push_back(i);
		for(int j=i*i;j<=1120;j+=i)
			notprime[j]=1;
	}
}
int n,k,dp[2020][15];
int main()
{
	sieve();
	while(scanf("%d%d",&n,&k)==2&&n)
	{
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		auto to=upper_bound(prime.begin(),prime.end(),n);
		for(auto it=prime.begin();it!=to;++it)
		{
			for(int i=k;i;i--)
				for(int j=0;j<=n;j++)
					if(j>=*it) dp[j][i]+=dp[j-*it][i-1];
		}
		printf("%d\n",dp[n][k]);
	}
}
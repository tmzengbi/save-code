#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int mu[maxn],minprime[maxn];
ll sum[maxn];
int prime[maxn],cnt=0;
void presolve(int x)
{
	mu[1]=1;
	for(int i=2;i<=x;i++)
	{
		if(!minprime[i])
		{
			minprime[i]=i;
			mu[i]=-1;
			prime[cnt++]=i;
		}
		for(int j=0;j<cnt;j++)
		{
			int p=prime[j];
			if(i*p>x) break;
			minprime[i*p]=p;
			if(i%p) mu[i*p]=-mu[i];
			else
			{
				mu[i*p]=0;
				break;
			}
		}
	}
	for(int i=1;i<=x;i++)
		sum[i]+=sum[i-1]+mu[i];
}
ll solve(int x,int y,int k)
{
	ll ans=0;
	for(int l=1,r;l*k<=min(x,y);l=r+1)
	{
		int now=l*k;
		r=min(x/(x/now),y/(y/now))/k;
		ans+=(ll)(sum[r]-sum[l-1])*(x/now)*(y/now);
	}
	return ans;
}
int t,a,b,c,d,k;
int main()
{
	presolve(maxn-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
//		printf("%lld %lld %lld %lld\n",solve(b,d,k),solve(b,c-1,k),solve(a-1,d,k),solve(a-1,c-1,k));
		printf("%lld\n",solve(b,d,k)-solve(b,c-1,k)-solve(a-1,d,k)+solve(a-1,c-1,k));
	}
}
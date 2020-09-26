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
#include<unordered_map>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=0x7fffffff;
const int preready=1630293+100;
unordered_map<int,ll>mp1,mp2;
ll sum1[preready],sum2[preready],mu[preready],auler[preready];
int prime[preready],cnt,minprime[preready];
void presolve()
{
	mu[1]=1;auler[1]=1;
	for(int i=2;i<=preready;i++)
	{
		if(!minprime[i])
		{
			minprime[i]=i;mu[i]=-1;
			prime[cnt++]=i;
			auler[i]=i-1;
		}
		for(int j=0;j<cnt;j++)
		{
			int p=prime[j];
			if(p*i>preready) break;
			minprime[i*p]=p;
			if(i%p)
			{
				mu[i*p]=-mu[i];
				auler[i*p]=auler[i]*(p-1);
			}
			else
			{
				mu[i*p]=0;
				auler[i*p]=auler[i]*p;
				break;
			}
		}
	}
	for(int i=1;i<=preready;i++)
	{
		sum1[i]+=sum1[i-1]+mu[i];
		sum2[i]+=sum2[i-1]+auler[i];
	}
}
const int limit=preready;
ll calc1(ll n)
{
	if(n<=limit) return sum1[n];
	if(mp1.count(n)) return mp1[n];
	ll sum=0;
	for(ll l=limit+1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		sum+=(r-l+1)*calc1(n/l);
	}
	return mp1[n]=1LL-sum;
}
ll calc2(ll n)
{
	if(n<=limit) return sum2[n];
	if(mp2.count(n)) return mp2[n];
	ll sum=0;
	for(ll l=limit+1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		sum+=(r-l+1)*calc2(n/l);
	}
	return mp2[n]=n*(n+1)/2-sum;
}
int n,t;
int main()
{
	presolve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld %lld\n",calc2(n),calc1(n));
	}
}
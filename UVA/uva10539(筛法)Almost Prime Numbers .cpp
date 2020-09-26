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
const int maxn=1e6;
vector<int>prime;
int notprime[maxn+10];
void sieve()
{
	int to=sqrt(maxn+0.5);
	for(int i=2;i<=to;i++) if(!notprime[i])
		for(int j=i*i;j<=maxn;j+=i)
			notprime[j]=1;
	for(int i=2;i<=maxn;i++)
		if(!notprime[i]) prime.push_back(i);
}
ll Pow(ll a,ll b)
{
	ll sum=1;
	for(;b;b>>=1)
	{
		if(b&1) sum=sum*a;
		if(b) a=a*a;
	}
	return sum;
}
int main()
{
	sieve();
	ll l,r;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i:prime)
			for(int j=2;;j++)
			{
				ll s=Pow(i,j);
				if(s>r) break;
				if(s>=l) ans++;
			}
		printf("%lld\n",ans);
	}
}
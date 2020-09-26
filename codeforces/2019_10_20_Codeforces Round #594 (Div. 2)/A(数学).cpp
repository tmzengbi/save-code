#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t,p[100010],q[100010],n;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		ll js[2]={0},os[2]={0};
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&p[i]);
			if(p[i]%2) js[0]++;
			else os[0]++;
		}
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&q[i]);
			if(q[i]%2) js[1]++;
			else os[1]++;
		}
		ll ans=os[1]*os[0]+js[1]*js[0];
		printf("%lld\n",ans);
	}
	
}
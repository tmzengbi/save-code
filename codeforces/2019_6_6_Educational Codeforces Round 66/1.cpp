#include<iostream>
#include<cstdio>
typedef long long ll;
ll t,n,k;
using namespace std;
int main()
{
	scanf("%lld",&t);
	while(t-->0)
	{
		scanf("%lld%lld",&n,&k);
		ll ans=0;
		while(n>=1)
		{
			ll temp=n;
			if(n%k==0)
			{	
				n=n/k;
				ans++;
			}
			else 
			{
				temp=(n/k)*k;
				ans+=n-temp;
				n=temp;
			}
		}
		printf("%lld\n",ans);
	}
} 

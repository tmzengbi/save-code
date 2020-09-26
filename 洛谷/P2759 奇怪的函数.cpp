#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
bool check(ll x)
{
	ll k=log10(x)*x;
	if(k+1>=n)	return true;
	return false;
}
int main()
{
	scanf("%lld",&n);
	ll l=1,r=n;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))	r=mid;
		else	l=mid+1;
//		cout<<l<<" "<<r<<endl;
	}
	printf("%lld\n",l);

//	while(1);
}
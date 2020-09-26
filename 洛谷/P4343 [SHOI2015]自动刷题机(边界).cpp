#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll L,K,a[100010],ansl,ansr,sum=0;
ll check(ll k)
{
	ll s=0;ll t=0;
	for(ll i=1;i<=L;i++)
	{
		s+=a[i];
		if(s<0)	s=0;
		if(s>=k) {t++;s=0;}
	}
	return t;
}
int main()
{
	scanf("%lld%lld",&L,&K);
	ll tmpsum=0;
	for(ll i=1;i<=L;i++)
	{
		scanf("%lld",&a[i]);
		tmpsum+=a[i];
		if(tmpsum<0)	tmpsum=0;
		sum=max(sum,tmpsum);
	}
	ll l=1,r=sum+1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)<=K)	r=mid;
		else l=mid+1;
	}
	ansl=l;
	l=ansl,r=sum+1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)<K)	r=mid;
		else l=mid+1;
	}
	ansr=l-1;
	if(ansl>ansr)
		printf("-1\n");
	else
		printf("%lld %lld\n",ansl,ansr);


//	while(1);
}
/*
4 2
2
5
-3
9
*/
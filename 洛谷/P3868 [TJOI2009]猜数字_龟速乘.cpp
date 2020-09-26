#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,a[15],b[15];
void exgcd(ll A,ll B,ll &x,ll &y,ll &d)
{
	if(!B){x=1;y=0;d=A;return;}
	exgcd(B,A%B,x,y,d);
	ll t=x;x=y;y=t-(A/B)*y;
}
ll gsc(ll A,ll B,ll mod)
{
	ll ans=0;
	for(;B;B>>=1)
	{
		if(B&1) ans=(ans+A)%mod;
		if(B)	A=(A<<1)%mod;
	}
	return ans;
}
ll china()
{
	ll mul=1;
	for(int i=1;i<=n;i++)
		mul*=b[i];
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll x,y,d;
		exgcd(mul/b[i],b[i],x,y,d);
//		cout<<x<<" "<<y<<" "<<d<<endl;
		x=(x%b[i]+b[i])%b[i];
		a[i]=(a[i]%b[i]+b[i])%b[i];
//		ans+=a[i]*mul/b[i]*x;
		ans+=gsc(gsc(a[i],mul/b[i],mul),x,mul);
	}
	return ans%mul;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	ll ans=china();
	printf("%lld\n",ans);
//	system("pause");

}
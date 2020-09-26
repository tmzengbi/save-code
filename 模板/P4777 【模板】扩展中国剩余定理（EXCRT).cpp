#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll maxn=100010;
ll a[maxn],b[maxn],N;
void exgcd(ll m,ll n,ll &x,ll &y,ll &d)
{
	if(n==0){x=1;y=0;d=m;return;}
	exgcd(n,m%n,x,y,d);
	ll t=x;x=y;y=t-(m/n)*y;
}
ll mul(ll m,ll n,ll mod)
{
	ll s=0;n=(n%mod+mod)%mod;
	for(;n;n>>=1)
	{
		if(n&1)	s=(s+m)%mod;
		if(n)	m=(m*2)%mod;
	}
	return s;
}
int main()
{
	scanf("%lld",&N);
	for(ll i=1;i<=N;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	ll a1=a[1],b1=b[1];
	for(ll i=2;i<=N;i++)
	{
		ll a2=a[i],b2=b[i];
		ll x,y,r,d;d=b2-b1;
		exgcd(a1,a2,x,y,r);
		if(d%r!=0){printf("-1\n");break;}
		ll mod=a2/r,r2;
		exgcd(a1/r,mod,x,y,r2);
		x=(x%mod+mod)%mod;
		ll k1=mul(x,d/r,mod);
		mod=(a1/r)*a2;
//		b1=((k1*a1+b1)%mod+mod)%mod;
		b1=(mul(k1,a1,mod)+b1%mod+mod)%mod;
		a1=mod;
	}
//	cout<<b1<<endl;
	printf("%lld\n",b1);
//	system("pause");
}
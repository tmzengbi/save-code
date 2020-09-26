#include<iostream>
using namespace std;
typedef long long ll;
ll n;
ll mi(ll b,ll p)
{
	ll ans=1;
	for(;p>=1;p>>=1)
	{
		if(p&1)ans=ans*b%n;
		if(p>1) b=b*b%n;
	}
	return ans%n;
}
int main()
{
	ll b,p;
	cin>>b>>p>>n;
	cout<<b<<'^'<<p<<" mod "<<n<<'='<<mi(b,p);
}

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
ll n;
vector<pll>v;
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	while(scanf("%lld",&n)==1&&n)
	{
		bool f=1;
		if(n<0) n=-n,f=0;
		v.clear();
		ll to=sqrt(n+0.5);
		for(int i=2;i<=to;i++)
			if(n%i==0)
			{
				v.push_back(make_pair(i,0));
				while(n%i==0)
				{
					v.back().second++;
					n/=i;
				}	
			}
		if(n>1) v.push_back(make_pair(n,1));
		ll ans=v[0].second;
		for(int i=1;i<v.size();i++)
			ans=gcd(ans,v[i].second);
		if(f) printf("%lld\n",ans);
		else
		{
			while(ans%2==0) ans/=2;
			printf("%lld\n",ans);
		}
	}
}
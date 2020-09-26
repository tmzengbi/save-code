#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
ll n;
vector<pii>p;
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
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	while(scanf("%lld",&n)==1&&n)
	{
		static int cas=0;
		printf("Case %d: ",++cas);
		if(n==1){printf("2\n");continue;}
		p.clear();
		for(ll i=2;i*i<=n;i++)
		{
			if(n%i==0) p.push_back(make_pair(i,0));
			while(n%i==0) p.back().second++,n/=i;
		}
		if(n>1) p.push_back(make_pair(n,1));
		if(p.size()==1)
			printf("%lld\n",Pow(p[0].first,p[0].second)+1);
		else
		{
			ll ans=0;
			for(auto k:p) ans+=Pow(k.first,k.second);
			printf("%lld\n",ans);
		}
	}
//	system("pause");
}
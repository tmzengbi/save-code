#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,n,k;
ll solve()
{
	if(k>n||k&1) return -1;
	if(n&1)return n*(n-1)/2-k/2;
	return n*(n-1)/2-(n-k)/2;
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		ll ans=solve();
		if(ans==-1) printf("renrendoushijwj\n");
		else printf("%lld\n",ans);
	}

//	while(1);
}

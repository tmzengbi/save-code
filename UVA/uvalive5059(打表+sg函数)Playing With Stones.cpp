/*
	规律：对于单堆nim游戏，如果一次不能拿走超过1/n的石子
	有
	if x%n==0 sg(x)=x/n;
	else sg(x)=sg(x-x/n-1);
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
ll sg(ll x)
{
	return x%2==0?x/2:(sg(x/2));
}
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			ll k;scanf("%lld",&k);
			sum^=sg(k);
		}
		if(sum) puts("YES");
		else puts("NO");
	}
}
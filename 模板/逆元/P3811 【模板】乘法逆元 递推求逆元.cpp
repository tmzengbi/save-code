#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ans[3000010];
int main()
{
	ll n,p;
	cin>>n>>p;
	ans[1]=1;
	printf("1\n");
	for(ll i=2;i<=n;i++)
	{
		ans[i]=(p-p/i)*ans[p%i]%p;
		printf("%lld\n",ans[i]);
	}
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ll sum1=0,sum2=0;
	for(int i=1;i<=n/2;i++)
		sum1+=a[i];
	for(int i=n/2+1;i<=n;i++)
		sum2+=a[i];
	ll ans=sum1*sum1+sum2*sum2;
	printf("%lld\n",ans);

}
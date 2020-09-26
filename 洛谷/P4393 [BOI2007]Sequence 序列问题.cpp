#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int n,a[1000010];
ll ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(a[1]>a[2])	ans+=a[1];
	if(a[n-1]<=a[n])	ans+=a[n];
	for(int i=2;i<=n-1;i++)
	{
		if(a[i-1]<=a[i])	ans+=a[i];
		if(a[i]>a[i+1])	ans+=a[i];
	}
	printf("%lld\n",ans);


//	while(1);
}
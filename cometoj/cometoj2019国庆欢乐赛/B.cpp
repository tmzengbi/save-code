#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[6],last=0;
int main()
{
	for(int i=1;i<=5;i++)
	{
		scanf("%lld",&a[i]);
		last+=a[i];
	}
	sort(a+1,a+6);
	last-=a[5];
	if(last<a[5]) printf("%lld\n",last);
	else printf("%lld\n",(last+a[5])/2);

//	while(1);
}
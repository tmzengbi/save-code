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
using namespace std;
typedef long long ll;
const int maxn=40000;
int auler[maxn+10],n,m;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	auler[1]=1;
	for(int i=2;i<=maxn;i++) if(!auler[i])
		for(int j=i;j<=maxn;j+=i)
		{
			if(!auler[j]) auler[j]=j;
			auler[j]=auler[j]/i*(i-1);
		}
    scanf("%d",&n);
	if(n==1){printf("0\n");return 0;}
    ll ans=0; 
	for(int i=1;i<n;i++) ans+=auler[i];
	printf("%lld\n",ans*2+1);
//	system("pause");
}
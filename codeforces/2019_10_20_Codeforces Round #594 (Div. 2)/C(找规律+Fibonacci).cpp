#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int P=1e9+7;
int n,m;
ll fib[100010],ans;
int main()
{
	scanf("%d%d",&n,&m);
	fib[0]=fib[1]=1;
	for(int i=2;i<=100000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%P;
	ans=((fib[m]+fib[n])*2-2)%P;
	printf("%lld\n",ans);
}
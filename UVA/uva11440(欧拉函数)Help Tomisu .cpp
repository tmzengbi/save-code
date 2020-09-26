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
const int maxprime=1e7;
const int P=1e8+7;
int notprime[maxprime+10];
void sieve()
{
	int to=sqrt(maxprime+0.5);
	for(int i=2;i<=to;i++) if(!notprime[i])
		for(int j=i*i;j<=maxprime;j+=i)
			notprime[j]=1;
}
int n,m,facauler[maxprime+10];
int main()
{
	sieve();
	facauler[1]=facauler[2]=1;
	for(int i=3;i<=maxprime;i++)
		facauler[i]=(ll)facauler[i-1]*(notprime[i]?i:(i-1))%P;
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		ll ans=facauler[m];
		for(int i=m+1;i<=n;i++) ans=ans*i%P;
		printf("%lld\n",(ans-1+P)%P);
	}
//	system("pause");
}
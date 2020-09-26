#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
int mu[maxn],minprime[maxn];
vector<int>prime;
void presolve(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!minprime[i])
		{
			minprime[i]=i;
			prime.push_back(i);
			mu[i]=-1;
		}
		for(int p:prime)
		{
			if(p*i>n) break;
			minprime[p*i]=p;
			if(i%p) mu[i*p]=-mu[i];
			else
			{
				mu[i*p]=0;
				break;
			}
		}
	}
}
int n,m;
int main()
{
	presolve(2000);
	for(int i=1;i<=100;i++)
		printf("%d %d\n",i,mu[i]);
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		ll ans=4;
		for(int i=1;i<=min(n,m);i++)
			ans+=(ll)mu[i]*(n/i)*(m/i)*4;
		ll fm=(ll)(n*2+1)*(m*2+1)-1;
		printf("%.7lf\n",double(ans)/fm);
	}
}
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
const int maxn=1e6+10;
int n,m,cnt=0;
int minprime[maxn];
int prime[maxn],auler[maxn];
void sieve()
{
	for(int i=2;i<=n;i++)
	{
		if(!minprime[i])
		{
			minprime[i]=i;
			prime[cnt++]=i;
			auler[i]=i-1;
		}
		for(int j=0;j<cnt;j++)
		{
			if(prime[j]*i>n) break;
			minprime[i*prime[j]]=prime[j];
			if(i%prime[j])
				auler[i*prime[j]]=auler[i]*auler[prime[j]];
			else
			{
				auler[i*prime[j]]=auler[i]*prime[j];
				break;
			}
		}
	}
}
int main()
{
//	scanf("%d",&n);
	n=100;
	sieve();
	for(int i=2;i<=100;i++)
		printf("%d %d\n",i,auler[i]);
	system("pause");
}
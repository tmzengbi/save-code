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
const int maxn=4e4+10;
int n,mu[maxn],minprime[maxn];
vector<int>prime;
void presolve()
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
int main()
{
	scanf("%d",&n);
	if(n==1){puts("0");return 0;}
	presolve();
	int ans=0;--n;
	for(int i=1;i<=n;i++)
		ans+=mu[i]*(n/i)*(n/i);
	printf("%d\n",ans+2);
//	system("pause");
}
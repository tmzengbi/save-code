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
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<int>prime;
const int maxn=10000;
int notprime[10010];
void sieve()
{
	for(int i=2;i<=maxn;i++) if(!notprime[i])
	{
		prime.push_back(i);
		for(int j=i*i;j<=maxn;j+=i)
			notprime[j]=1;
	}
}
int main()
{
	int n;
	sieve();
	while(scanf("%d",&n)==1&&n)
	{
		if(n==2){printf("%d\n",1);continue;}
		auto l=prime.begin(),r=l;
		int ans=0,sum=2;
		while(r!=prime.end())
		{
			++r;
			sum+=*r;
			if(sum>n)
			while(sum>n&&l!=r)
			{
				sum-=*l;
				++l;
			}
			if(sum==n) ans++;
		}
		printf("%d\n",ans);
	}
}
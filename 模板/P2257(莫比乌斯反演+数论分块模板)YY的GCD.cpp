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
const int maxn=1e7+10;
int mu[maxn],minprime[maxn],sum[maxn];
ll suffixsum[maxn];
int prime[maxn],cnt=0;
void presolve(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!minprime[i])
		{
			minprime[i]=i;
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt;j++)
		{
			int p=prime[j];
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
	for(int i=0;i<cnt;i++)
	{
		int p=prime[i];
		for(int j=1;j*p<=n;j++)
			sum[j*p]+=mu[j];
	}
	for(int i=1;i<=n;i++)
		suffixsum[i]+=suffixsum[i-1]+sum[i];
}
int n,m,t;
inline int read()
{
	int shu=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu;
	
}
int main()
{
	presolve(maxn-10);
//	scanf("%d",&t);
	t=read();
//	for(int i=1;i<=10;i++)
//		printf("%d %d\n",sum[i],suffixsum[i]);
	while(t--)
	{
//		scanf("%d%d",&n,&m);
		n=read();m=read();
		ll ans=0;
//		for(int i=1;i<=min(n,m);i++)
//			printf("%d %lld\n",i,(ll)(n/i)*(m/i)*sum[i]);
		for(int l=1,r;l<=min(n,m);l=r+1)
		{
			r=min(n/(n/l),m/(m/l));
			ans+=(ll)(suffixsum[r]-suffixsum[l-1])*(n/l)*(m/l);
		}
		printf("%lld\n",ans);
	}
}
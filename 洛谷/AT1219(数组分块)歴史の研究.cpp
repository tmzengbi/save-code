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
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int Block=510;
map<int,int>M;
int n,m,belong[maxn],le[Block],ri[Block],a[maxn];
int f[Block][Block],cnt[Block][maxn],bk,c[maxn],pre[maxn];
int sta[maxn],Index=0;
ll solve(int l,int r)
{
	ll ans=f[belong[l]+1][belong[r]-1];
	ans=(ll)pre[ans]*(cnt[belong[r]-1][ans]-cnt[belong[l]][ans]);
	for(int i=l;i<=min(r,ri[belong[l]]);i++)
	{
		int k=cnt[belong[r]-1][a[i]]-cnt[belong[l]][a[i]];if(k<0) k=0;
		if(!c[a[i]]) sta[Index++]=a[i];
		c[a[i]]++;
		k+=c[a[i]];
		ll sum=(ll)pre[a[i]]*k;
		ans=max(sum,ans);
	}
	if(belong[l]!=belong[r])
	{
		for(int i=le[belong[r]];i<=r;i++)
		{
			int k=cnt[belong[r]-1][a[i]]-cnt[belong[l]][a[i]];if(k<0) k=0;
			if(!c[a[i]]) sta[Index++]=a[i];
			c[a[i]]++;
			k+=c[a[i]];
			ll sum=(ll)pre[a[i]]*k;
			ans=max(sum,ans);
		}
	}
	while(Index) c[sta[--Index]]=0;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(!M.count(a[i])) M[a[i]]=++tmp,pre[tmp]=a[i];
		a[i]=M[a[i]];
		cnt[belong[i]][a[i]]++;
	}
	for(int i=1;i<=belong[n];i++)
		for(int j=1;j<=tmp;j++)
			cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=belong[n];i++)
	{
		ll sum=0;int mk=0;
		memset(c,0,sizeof c);
		for(int j=le[i];j<=n;j++)
		{
			c[a[j]]++;
			if(sum<(ll)c[a[j]]*pre[a[j]])
			{sum=(ll)c[a[j]]*pre[a[j]];mk=a[j];}
			f[i][belong[j]]=mk;
		}
	}
	memset(c,0,sizeof c);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);if(l>r) swap(l,r);
		printf("%lld\n",solve(l,r));
	}
//	system("pause");
}
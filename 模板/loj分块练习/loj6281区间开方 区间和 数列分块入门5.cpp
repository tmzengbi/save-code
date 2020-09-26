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
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=50010;
const int Block=510;
int n,bk,numofblock,a[maxn],belong[maxn],le[Block],ri[Block],cnt[Block],siz[Block];
ll sumv[Block];
void maintain(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(cnt[belong[i]]==siz[belong[i]]) i=ri[belong[i]];
		else if(a[i]>1)
		{
			sumv[belong[i]]-=a[i];
			a[i]=(int)sqrt(a[i]);
			sumv[belong[i]]+=a[i];
			if(a[i]==1) cnt[belong[i]]++;
		}
	}
}
int query(int l,int r)
{
	int ans=0;
	for(int i=l;i<=min(r,ri[belong[l]]);i++) ans+=a[i];
	if(belong[l]!=belong[r])
		for(int i=le[belong[r]];i<=r;i++) ans+=a[i];
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
		ans+=sumv[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bk=(int)sqrt(n);numofblock=n/bk;
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/bk+1;
		siz[belong[i]]++;
		sumv[belong[i]]+=a[i];
	}
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;
	}
	for(int i=1;i<=n;i++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt==0) maintain(l,r);
		else printf("%d\n",query(l,r));
	}
//	system("pause");
}
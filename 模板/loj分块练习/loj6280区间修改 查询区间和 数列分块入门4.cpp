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
int n,bk,numofblock,a[maxn],belong[maxn],le[Block],ri[Block],tag[Block];
ll sumv[Block];
void addto(int l,int r,int c)
{
	for(int i=l;i<=min(r,ri[belong[l]]);i++){a[i]+=c;sumv[belong[i]]+=c;}
	if(belong[l]!=belong[r])
		for(int i=le[belong[r]];i<=r;i++){a[i]+=c;sumv[belong[i]]+=c;}
	for(int i=belong[l]+1;i<=belong[r]-1;i++){tag[i]+=c;sumv[i]+=c*bk;}
}
int query(int l,int r,int c)
{
	ll ans=0;
	for(int i=l;i<=min(r,ri[belong[l]]);i++) ans+=a[i]+tag[belong[i]];
	if(belong[l]!=belong[r])
		for(int i=le[belong[r]];i<=r;i++) ans+=a[i]+tag[belong[i]];
	for(int i=belong[l]+1;i<=belong[r]-1;i++) ans+=sumv[i];
	ans%=(c+1);
	return (int)ans;
}
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	bk=(int)sqrt(n);
	numofblock=n/bk;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/bk+1;
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
		if(opt==0) addto(l,r,c);
		else printf("%d\n",query(l,r,c));
	}
//	system("pause");
}
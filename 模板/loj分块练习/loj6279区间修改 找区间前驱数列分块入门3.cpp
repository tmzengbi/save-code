#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=100010;
const int Block=550;
int a[maxn],belong[maxn],le[Block],ri[Block],b[Block][Block],tag[Block];
int numofblock,bk,n;
inline void maintain(int *s,int block)
{
	for(int i=le[block],j=1;i<=ri[block];i++,j++) s[j]=a[i];
	sort(s+1,s+bk+1);
}
void addto(int l,int r,int c)
{
	for(int i=l;i<=min(r,ri[belong[l]]);i++) a[i]+=c;
	if(belong[l]<=numofblock) maintain(b[belong[l]],belong[l]);
	if(belong[l]!=belong[r])
	{
		for(int i=le[belong[r]];i<=r;i++) a[i]+=c;
		if(belong[r]<=numofblock) maintain(b[belong[r]],belong[r]);
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++) tag[i]+=c;
}
int query(int l,int r,int c)
{
	int ans=(-1)<<31;
	bool ok=0;
	for(int i=l;i<=min(r,ri[belong[l]]);i++)
		if(a[i]+tag[belong[i]]<c) ans=max(ans,a[i]+tag[belong[i]]),ok=1;
	if(belong[l]!=belong[r])
	{
		for(int i=le[belong[r]];i<=r;i++)
			if(a[i]+tag[belong[i]]<c) ans=max(ans,a[i]+tag[belong[i]]),ok=1;
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
	{
		int x=c-tag[i];
		int t=lower_bound(b[i]+1,b[i]+bk+1,x)-b[i]-1;
		if(t>0) ans=max(ans,b[i][t]+tag[i]),ok=1;
	}
	if(ok) return ans;
	return -1;
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
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;
	}
	for(int i=1;i<=n;i++)
		b[belong[i]][i-ri[belong[i]-1]]=a[i];
	for(int i=1;i<=numofblock;i++)
		sort(b[i]+1,b[i]+bk+1);
	for(int i=1;i<=n;i++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt==0) addto(l,r,c);
		else printf("%d\n",query(l,r,c));
	}
//	system("pause");
}
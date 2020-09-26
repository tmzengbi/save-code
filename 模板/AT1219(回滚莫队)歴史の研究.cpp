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
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<double,double>pdd;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int Block=510;
int n,m,a[maxn],belong[maxn],le[Block],ri[Block],bk;
int val[maxn],cnt[maxn];
map<int,int>mp;
struct Node
{
	int l,r,id;
}q[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):rhs1.r<rhs2.r;
}
ll sum=0,ans[maxn];
inline void del(int x)
{
	cnt[a[x]]--;	
}
inline void add(int x,ll &s)
{
	cnt[a[x]]++;
	s=max(s,(ll)cnt[a[x]]*val[a[x]]);
}
int main()
{
	scanf("%d%d",&n,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++)  belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
		le[i]=(i-1)*bk+1,ri[i]=i*bk;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!mp.count(a[i])) mp[a[i]]=++id,val[id]=a[i];
		a[i]=mp[a[i]];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		if(q[i].l>q[i].r) swap(q[i].l,q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0,now=0;
	for(int i=1;i<=m;i++)
	{
		if(now!=belong[q[i].l])
		{
			memset(cnt,0,sizeof cnt);
			now=belong[q[i].l];
			l=ri[belong[q[i].l]]+1;r=l-1;
			sum=0;
		}
		if(belong[q[i].l]==belong[q[i].r])
		{
			ll s=0;
			for(int j=q[i].l;j<=q[i].r;j++)
			{
				cnt[a[j]]++;
				s=max(s,(ll)cnt[a[j]]*val[a[j]]);
			}
			for(int j=q[i].l;j<=q[i].r;j++) cnt[a[j]]--;
			ans[q[i].id]=s;
			continue;
		}
		while(r<q[i].r) add(++r,sum);
		ll tmp=sum;
		while(l>q[i].l) add(--l,tmp);
		while(l<ri[now]+1) del(l++);
		ans[q[i].id]=tmp;
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
//	system("pause");
}
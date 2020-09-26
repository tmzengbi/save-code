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
int n,bk,a[maxn],belong[maxn],le[Block],ri[Block],val[maxn],ans[maxn];
map<int,int>mp;
struct Node
{
	int l,r,id;
}q[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?belong[rhs1.l]<belong[rhs2.l]:rhs1.r<rhs2.r;
}
int sum=0,mk,cnt[maxn];
inline void add(int x,int &sum,int &mk)
{
	cnt[a[x]]++;
	if(cnt[a[x]]>sum||cnt[a[x]]==sum&&mk>val[a[x]])
		sum=cnt[a[x]],mk=val[a[x]];
}
inline void del(int x)
{
	cnt[a[x]]--;
}
int main()
{
	scanf("%d",&n);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
		le[i]=(i-1)*bk+1,ri[i]=i*bk;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!mp.count(a[i])) mp[a[i]]=++id,val[id]=a[i];
		a[i]=mp[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+n+1,cmp);
	int l=1,r=0,now=0;
	for(int i=1;i<=n;i++)
	{
		if(now!=belong[q[i].l])
		{
			now=belong[q[i].l];
			l=le[now+1],r=l-1;
			memset(cnt,0,sizeof cnt);
			sum=0;
		}
		if(belong[q[i].l]==belong[q[i].r])
		{
			int tt=0;
			for(int j=q[i].l;j<=q[i].r;j++)
			{
				cnt[a[j]]++;
				if(cnt[a[j]]>tt||cnt[a[j]]==tt&&mk>val[a[j]])
					tt=cnt[a[j]],mk=val[a[j]];
			}
			for(int j=q[i].l;j<=q[i].r;j++)
				cnt[a[j]]--;
			ans[q[i].id]=mk;
			continue;
		}
		while(r<q[i].r) add(++r,sum,mk);
		int tmps=sum,tmpmk=mk;
		while(l>q[i].l) add(--l,tmps,tmpmk);
		while(l<le[now+1]) del(l++);
		ans[q[i].id]=tmpmk;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
//	system("pause");
}
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
const int maxn=2e5+10;
const int Block=510;
int n,m,a[maxn],bk,belong[maxn];
int cnt[maxn],c[maxn],ans[maxn];
map<int,int>mp;
struct Node
{
	int l,r,id;
}q[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.l]&1)?rhs1.r<rhs2.r:rhs1.r>rhs2.r);
}
int sum=0;
inline void add(int x)
{
	c[cnt[a[x]]]--;
	cnt[a[x]]++;
	c[cnt[a[x]]]++;
	if(c[sum+1]) sum++;
}
inline void del(int x)
{
	c[cnt[a[x]]]--;
	cnt[a[x]]--;
	c[cnt[a[x]]]++;
	if(!c[sum]) sum--;
}
int main()
{
	scanf("%d%d",&n,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bk+1;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!mp.count(a[i])) mp[a[i]]=++id;
		a[i]=mp[a[i]];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;c[0]+=id;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",-ans[i]);	
//	system("pause");
}
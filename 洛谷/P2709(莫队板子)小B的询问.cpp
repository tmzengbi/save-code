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
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=5e4+10;
int a[maxn],belong[maxn],bk,cnt[maxn];
ll sum=0;
struct Node
{
	int l,r,id;
}q[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.l]&1)?(rhs1.r<rhs2.r):(rhs1.r>rhs2.r));
}
inline void add(int x)
{
	int &t=cnt[a[x]];
	sum-=(ll)t*t;
	t++;
	sum+=(ll)t*t;
}
inline void del(int x)
{
	int &t=cnt[a[x]];
	sum-=(ll)t*t;
	t--;
	sum+=(ll)t*t;
}
int n,m,k;
ll ans[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
//	system("pause");
}
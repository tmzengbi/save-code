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
const int maxn=3e4+10;
const int Maxnum=1e6+10;
const int Maxquery=2e5+10;
int n,a[maxn],cnt[Maxnum],belong[maxn],ans[Maxquery],bk,m;
struct Query
{
	int l,r,id;
}q[Maxquery];
bool cmp(const Query&rhs1,const Query&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?belong[rhs1.l]<belong[rhs2.l]:((belong[rhs1.l]&1)?(rhs1.r<rhs2.r):(rhs1.r>rhs2.r));
}
inline void del(int x,int &s)
{
	cnt[a[x]]--;
	if(!cnt[a[x]]) s--;
}
inline void add(int x,int &s)
{
	if(!cnt[a[x]]) s++;
	cnt[a[x]]++;
}
int main()
{
	scanf("%d",&n);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r) add(++r,sum);
		while(r>q[i].r) del(r--,sum);
		while(l<q[i].l) del(l++,sum);
		while(l>q[i].l) add(--l,sum);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
//	system("pause");
}
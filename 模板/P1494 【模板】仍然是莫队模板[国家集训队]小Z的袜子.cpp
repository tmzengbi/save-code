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
typedef pair<ll,ll>pii;
const int maxn=5e4+10;
int n,a[maxn],cnt[maxn],belong[maxn],bk,m;
ll sum=0;
struct Node
{
	int l,r,id;
}q[maxn];
pii ans[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.l]&1)?rhs1.r<rhs2.r:rhs1.r>rhs2.r);
}
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
void simplify(ll &x,ll &y)
{
	if(x==0) y=1;
	ll r=gcd(x,y);
	x/=r;y/=r;
}
inline void add(int x)
{
	int &t=cnt[a[x]];
	t++;
	if(t>=2) sum+=(ll)t*(t-1)/2-(ll)(t-1)*(t-2)/2;
}
inline void del(int x)
{
	int &t=cnt[a[x]];
	if(t>=2) sum-=(ll)t*(t-1)/2-(ll)(t-1)*(t-2)/2;
	t--;
}
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("a11.out","w",stdout);
	scanf("%d%d",&n,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
		if(q[i].l==q[i].r) ans[i]=make_pair(0,1);
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		if(ans[q[i].id].second) continue;
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		ll x=sum,y=(ll)(r-l+1)*(r-l)/2;
		simplify(x,y);
		ans[q[i].id]=make_pair(x,y);
	}
	for(int i=1;i<=m;i++)
		printf("%lld/%lld\n",ans[i].first,ans[i].second);
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=5e4+10;
const int maxnum=1000010;
const int maxque=200010;
ll sum[maxn<<2];
void pushup(int o)
{
	sum[o]=sum[o<<1]+sum[o<<1|1];
}
void build(int o,int l,int r)
{
	sum[o]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void update(int o,int l,int r,int q,int v)
{
	if(l==r){sum[o]+=v;return;}
	int mid=l+r>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return sum[o];
	int mid=l+r>>1;
	ll ans=0;
	if(ql<=mid) ans+=query(o<<1,l,mid,ql,qr);
	if(mid<qr) ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int t,n,m,a[maxn],pre[maxnum];
ll ans[maxque];
struct Que
{
	int l,r,id;
}q[maxque];
bool cmp(const Que&rhs1,const Que&rhs2)
{
	return rhs1.r<rhs2.r;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(pre,0,sizeof pre);
		scanf("%d",&n);build(1,1,n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
		sort(q+1,q+m+1,cmp);
		int r=0;
		for(int i=1;i<=m;i++)
		{
			while(r<q[i].r)
			{
				r++;
				if(pre[a[r]]) update(1,1,n,pre[a[r]],-a[r]);
				update(1,1,n,r,a[r]);
				pre[a[r]]=r;
			}
			ans[q[i].id]=query(1,1,n,q[i].l,q[i].r);
		}
		for(int i=1;i<=m;i++)
			printf("%lld\n",ans[i]);
	}
//	system("pause");
}
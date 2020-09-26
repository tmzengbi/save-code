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
const int maxn=1e5+10;
ll sum[maxn<<2];
int a[maxn],val[maxn],t,n,m;
void build(int o,int l,int r)
{
	sum[o]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void pushup(int o)
{
	sum[o]=sum[o<<1]+sum[o<<1|1];
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
	int mid=l+r>>1;ll ans=0;
	if(ql<=mid) ans+=query(o<<1,l,mid,ql,qr);
	if(mid<qr) ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
//debug
void pushall(int o,int l,int r)
{
	if(l==r){printf("%d ",sum[o]);return;}
	int mid=l+r>>1;
	pushall(o<<1,l,mid);pushall(o<<1|1,mid+1,r);
}
void print()
{
	pushall(1,1,n);
	puts("");
}

struct Que
{
	int l,r,h,id;
}q[maxn];
bool cmp(const Que&rhs1,const Que&rhs2)
{
	return rhs1.h<rhs2.h;
}
int b[maxn],kk;
int getindex(int x)
{
	return lower_bound(b+1,b+kk+1,x)-b;
}
vector<int>num[maxn];
int ans[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			num[i].clear();
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		kk=unique(b+1,b+n+1)-b-1;
		for(int i=1;i<=n;i++)
		{
			a[i]=getindex(a[i]);
			num[a[i]].push_back(i);
		}
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].h),q[i].id=i;
		sort(q+1,q+m+1,cmp);
		int now=0;
		for(int i=1;i<=m;i++)
		{
			int to=upper_bound(b+1,b+kk+1,q[i].h)-b-1;
			while(now<to)
			{
				now++;
				for(int k:num[now]) update(1,1,n,k,1);
			}
			q[i].l++;q[i].r++;
//			printf("%d %d %d\n",q[i].l,q[i].r,q[i].id);
//			print();
			ans[q[i].id]=query(1,1,n,q[i].l,q[i].r);
		}
		static int cas=0;
		printf("Case %d:\n",++cas);
		for(int i=1;i<=m;i++)
			printf("%d\n",ans[i]);
	}
//	system("pause");
}
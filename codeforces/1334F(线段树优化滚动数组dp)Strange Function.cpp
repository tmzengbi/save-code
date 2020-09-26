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
const int maxn=5e5+10;
ll tag[maxn<<2],t[maxn<<2];
int n,m,a[maxn],p[maxn],b[maxn];
void build(int o,int l,int r)
{
	tag[o]=0;t[o]=1LL<<60;
	if(l==r)
	{
		if(l==0) t[o]=0;
		return;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void tagg(int o,ll v)
{
	tag[o]+=v;
	t[o]+=v;
}
void pushdown(int o)
{
	if(tag[o])
	{
		tagg(o<<1,tag[o]);
		tagg(o<<1|1,tag[o]);
		tag[o]=0;
	}
}
void update(int o,int l,int r,int ql,int qr,ll v)
{
	if(ql>qr) return;
	if(ql<=l&&r<=qr){tagg(o,v);return;}
	pushdown(o);
	int mid=l+r>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
}
ll query(int o,int l,int r,int q)
{
	if(l==r) return t[o];
	int mid=l+r>>1;
	pushdown(o);
	if(q<=mid) return query(o<<1,l,mid,q);
	else return query(o<<1|1,mid+1,r,q);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
//	b[m+1]=1<<30;
	build(1,0,m);
	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(b+1,b+m+1,a[i])-b;
		if(a[i]==b[j])
		{
			update(1,0,m,j+1,m,min(0,p[i]));
			ll tmp=query(1,0,m,j);
//			printf("%lld\n",tmp);
			ll x=query(1,0,m,j-1),y=tmp+min(0,p[i]);
			update(1,0,m,j,j,min(x,y)-tmp);
			update(1,0,m,0,j-1,p[i]);
		}
		else
		{
			update(1,0,m,0,j-1,p[i]);
			update(1,0,m,j,m,min(0,p[i]));
		}
	}
	ll ans=query(1,0,m,m);
	if(ans>=(1LL<<55)) printf("NO\n");
	else printf("YES\n%lld\n",ans);	
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
const int maxn=5e5+10;
ll tag[maxn<<2],t[maxn<<2];
int n,m,a[maxn],p[maxn],b[maxn];
void build(int o,int l,int r)
{
	tag[o]=0;t[o]=1LL<<60;
	if(l==r)
	{
		if(l==0) t[o]=0;
		return;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void tagg(int o,ll v)
{
	tag[o]+=v;
	t[o]+=v;
}
void pushdown(int o)
{
	if(tag[o])
	{
		tagg(o<<1,tag[o]);
		tagg(o<<1|1,tag[o]);
		tag[o]=0;
	}
}
void update(int o,int l,int r,int ql,int qr,ll v)
{
	if(ql>qr) return;
	if(ql<=l&&r<=qr){tagg(o,v);return;}
	pushdown(o);
	int mid=l+r>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
}
ll query(int o,int l,int r,int q)
{
	if(l==r) return t[o];
	int mid=l+r>>1;
	pushdown(o);
	if(q<=mid) return query(o<<1,l,mid,q);
	else return query(o<<1|1,mid+1,r,q);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
//	b[m+1]=1<<30;
	build(1,0,m);
	for(int i=1;i<=n;i++)
	{
		int j=lower_bound(b+1,b+m+1,a[i])-b;
		if(a[i]==b[j])
		{
			update(1,0,m,j+1,m,min(0,p[i]));
			ll tmp=query(1,0,m,j);
//			printf("%lld\n",tmp);
			ll x=query(1,0,m,j-1),y=tmp+min(0,p[i]);
			update(1,0,m,j,j,min(x,y)-tmp);
			update(1,0,m,0,j-1,p[i]);
		}
		else
		{
			update(1,0,m,0,j-1,p[i]);
			update(1,0,m,j,m,min(0,p[i]));
		}
	}
	ll ans=query(1,0,m,m);
	if(ans>=(1LL<<55)) printf("NO\n");
	else printf("YES\n%lld\n",ans);	system("pause");
}system("pause");
}
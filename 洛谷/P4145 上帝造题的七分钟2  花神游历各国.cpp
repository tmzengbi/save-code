#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
using namespace std;
typedef long long ll;
const ll maxn=100010;
ll n,m;
ll a[maxn],segtree[maxn<<2],tag[maxn<<2];
inline ll read()
{
	char ch=getchar();
	ll shu=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
void pushup(ll o)
{
	segtree[o]=segtree[o<<1]+segtree[o<<1|1];
	tag[o]=tag[o<<1]&tag[o<<1|1];
}
void build(ll o,ll l,ll r)
{
	if(l==r){segtree[o]=a[l];return;}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void change(ll o,ll l,ll r,ll ql,ll qr)
{
	if(tag[o])	return;
	if(l==r)
	{
		segtree[o]=(ll)sqrt(segtree[o]);
		if(segtree[o]==0||segtree[o]==1)	tag[o]=1;
		return;
	}
	ll mid=(l+r)>>1;
	if(ql<=mid)	change(o<<1,l,mid,ql,qr);
	if(mid<qr)	change(o<<1|1,mid+1,r,ql,qr);
	pushup(o);
}
ll query(ll o,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr){return segtree[o];}
	ll mid=(l+r)>>1,ans=0;
	if(ql<=mid)	ans+=query(o<<1,l,mid,ql,qr);
	if(mid<qr)	ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main()
{
	memset(tag,0,sizeof tag);
	n=read();
	for(ll i=1;i<=n;i++)
		a[i]=read();
	m=read();
	build(1,1,n);
	for(ll i=1;i<=m;i++)
	{
		ll k,l,r;
		k=read();l=read();r=read();
		if(l>r)	swap(l,r);
		ll ans;
		if(k==0)	change(1,1,n,l,r);
		else if(k==1)
		{
			ans=query(1,1,n,l,r);
			printf("%lld\n",ans);
		}
	}
}


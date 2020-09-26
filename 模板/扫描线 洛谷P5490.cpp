#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=100010;
struct Wid
{
	ll h,l,r,dir;
	Wid():h(0){}
}w[maxn<<1];
ll X[maxn<<1],n;
ll sumtag[maxn<<4],lenth[maxn<<4],ans=0;
ll Find(ll l)
{
	return lower_bound(X+1,X+n*2+1,l)-X;
}
bool cmp(Wid w1,Wid w2)
{
	return w1.h<w2.h;
}
inline ll read()
{
	ll shu=0,f=1;char ch=getchar();
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
void pushup(ll o,ll l,ll r)
{
	if(sumtag[o])	lenth[o]=X[r+1]-X[l];
	else lenth[o]=lenth[o<<1]+lenth[o<<1|1];
}
void update(ll o,ll l,ll r,ll ql,ll qr,ll v)
{
	if(ql<=l&&r<=qr){sumtag[o]+=v;pushup(o,l,r);return;}
	ll mid=(l+r)>>1;
	if(ql<=mid)	update(o<<1,l,mid,ql,qr,v);
	if(qr>mid)	update(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o,l,r);
}
void build(ll o,ll l,ll r)
{
	lenth[o]=sumtag[o]=0;
	if(l==r){return;}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
//	pushup(o,l,r);
}
int main()
{
//	freopen("testdata.in","r",stdin);
//	freopen("11.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read();
		if(x1>x2)	swap(x1,x2);
		if(y1>y2)	swap(y1,y2);
		w[(i<<1)-1].h=y1;w[(i<<1)-1].l=x1;w[(i<<1)-1].r=x2;w[(i<<1)-1].dir=1;
		w[i<<1].h=y2;w[i<<1].l=x1;w[i<<1].r=x2;w[i<<1].dir=-1;
		X[(i<<1)-1]=x1;X[i<<1]=x2;
	}
	sort(X+1,X+2*n+1);
	sort(w+1,w+2*n+1,cmp);
	ll tot=unique(X+1,X+n*2+1)-X-1;
	build(1,1,tot-1);
	for(ll i=1;i<n*2;i++)
	{
		ll nh=w[i+1].h;
		ll l=Find(w[i].l),r=Find(w[i].r);
		update(1,1,n<<1,l,r-1,w[i].dir);
		ans+=lenth[1]*(nh-w[i].h);
	}
	cout<<ans;
}

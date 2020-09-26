#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=100010;
ll N,M;
ll a[maxn],sumv[maxn<<2],ltag[maxn<<2];
void pushup(int o)
{
	sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
void build(int o,int l,int r)
{
	ltag[o]=0;
	if(l==r){sumv[o]=a[l];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void puttag(int o,int l,int r,int v)
{
	ltag[o]+=v;sumv[o]+=(r-l+1)*v;
}
void pushdown(int o,int l,int r)
{
	if(ltag[o]==0)	return;
	ltag[o<<1]+=ltag[o];
	ltag[o<<1|1]+=ltag[o];
	int mid=(l+r)>>1;
	sumv[o<<1]+=ltag[o]*(mid-l+1);
	sumv[o<<1|1]+=ltag[o]*(r-mid);
	ltag[o]=0;
}
void addv(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){puttag(o,l,r,v);return;}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)	addv(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	addv(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){return sumv[o];}
	pushdown(o,l,r);
	ll mid=(l+r)>>1,ans=0;
	if(ql<=mid)	ans+=query(o<<1,l,mid,ql,qr);
	if(mid<qr)	ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main()
{
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	build(1,1,N);
	while(M--)
	{
		int c;
		ll x,y,k;
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%lld%lld%lld",&x,&y,&k);
			addv(1,1,N,x,y,k);
		} 
		else if(c==2)
		{
			scanf("%lld%lld",&x,&y);
			ll ans=query(1,1,N,x,y);
			cout<<ans<<endl;
		}
/*		for(int i=1;i<=20;i++)
			cout<<sumv[i]<<" ";
		cout<<endl;
		for(int i=1;i<=20;i++)
			cout<<ltag[i]<<" ";
		cout<<endl<<endl;
		*/
	}
}

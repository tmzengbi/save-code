#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn=100010;
ll N,M,P;
ll sumv[maxn<<2],addv[maxn<<2],mulv[maxn<<2],a[maxn];
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
void pushup(ll o)
{
	sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%P;
}
void build(ll o,ll l,ll r)
{
	addv[o]=0;
	mulv[o]=1;
	if(l==r){sumv[o]=a[l];return;}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void pushdown(ll o,ll l,ll r)
{
	if(addv[o]==0&&mulv[o]==1)	return;
	addv[o<<1]=(addv[o<<1]*mulv[o]+addv[o])%P;
	mulv[o<<1]=mulv[o<<1]*mulv[o]%P;
	addv[o<<1|1]=(addv[o<<1|1]*mulv[o]+addv[o])%P;
	mulv[o<<1|1]=(mulv[o<<1|1]*mulv[o])%P;
	ll mid=(l+r)>>1;
	sumv[o<<1]=(sumv[o<<1]*mulv[o]+addv[o]*(mid-l+1))%P;
	sumv[o<<1|1]=(sumv[o<<1|1]*mulv[o]+addv[o]*(r-mid))%P;
	addv[o]=0;
	mulv[o]=1;
}
void puttagsum(ll o,ll l,ll r,ll v)
{
	addv[o]+=v;sumv[o]=(sumv[o]+v*(r-l+1))%P;
}
void puttagmul(ll o,ll l,ll r,ll v)
{
	mulv[o]=mulv[o]*v%P;sumv[o]=sumv[o]*v%P;
	addv[o]=addv[o]*v%P; 
}
void add(ll o,ll l,ll r,ll ql,ll qr,ll v)
{
	if(ql<=l&&r<=qr){puttagsum(o,l,r,v);return;}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid)	add(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	add(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
void mult(ll o,ll l,ll r,ll ql,ll qr,ll v)
{
	if(ql<=l&&r<=qr){puttagmul(o,l,r,v);return;}
	pushdown(o,l,r);
	ll mid=(r+l)>>1;
	if(ql<=mid)	mult(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	mult(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
ll query(ll o,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr){return sumv[o];}
	pushdown(o,l,r);
	ll mid=(r+l)>>1,ans=0;
	if(ql<=mid)	ans+=query(o<<1,l,mid,ql,qr);
	if(mid<qr)	ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main()
{
    N=read();M=read();P=read();
    for(ll i=1;i<=N;i++)
        a[i]=read();
    build(1,1,N);
    while(M--)
    {
        ll mod,x,y,k;
        mod=read();x=read();y=read();
        if(mod==1)
        {
            k=read();
            mult(1,1,N,x,y,k);
        }
        else if(mod==2)
        {
            k=read();
            add(1,1,N,x,y,k);
        }
        else if(mod==3)
        {
            cout<<query(1,1,N,x,y)%P<<endl;
        }
        
    }
} 

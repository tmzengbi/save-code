#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000010;
int minv[maxn<<2],maxv[maxn<<2],tag[maxn<<2],m[maxn<<2],a[maxn];
int N,Q,W;
inline int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){shu=shu*10+ch-'0';ch=getchar();}
	return shu*f;
}
void pushup(int o)
{
	m[o]=m[o<<1]+m[o<<1|1];
	minv[o]=min(minv[o<<1],minv[o<<1|1]);
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}
void build(int o,int l,int r)
{
	tag[o]=0;
	if(l==r){m[o]=1;maxv[o]=minv[o]=a[l];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
void puttag(int o,int l,int r,int v)
{
	tag[o]+=v;
	minv[o]+=v;
	maxv[o]+=v;
}
void pushdown(int o,int l,int r)
{
	if(tag[o]==0)	return;
	tag[o<<1]+=tag[o];
	maxv[o<<1]+=tag[o];minv[o<<1]+=tag[o];
	tag[o<<1|1]+=tag[o];
	maxv[o<<1|1]+=tag[o];minv[o<<1|1]+=tag[o];
	tag[o]=0;
}
void addtag(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){puttag(o,l,r,v);return;}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)	addtag(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	addtag(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr)
	{
		if(maxv[o]<c)	return 0;
		if(minv[o]>=c)	return m[o];
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1,ans=0;
	if(ql<=mid)	ans+=query(o<<1,l,mid,ql,qr,c);
	if(mid<qr)	ans+=query(o<<1|1,mid+1,r,ql,qr,c);
	return ans;
}
int main()
{
//	N=read();Q=read();
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	build(1,1,N);
	while(Q--)
	{
		char ch;
		cin>>ch;
		int l,r,h;
		scanf("%d%d%d",&l,&r,&h);
		if(ch=='A')	cout<<query(1,1,N,l,r,h)<<endl;
		if(ch=='M')	addtag(1,1,N,l,r,h);
	}
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2000010;
int setv[maxn<<2],maxv[maxn<<2],minv[maxn<<2],N,K;
void pushup(int o)
{
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
	minv[o]=min(minv[o<<1],minv[o<<1|1]);
}
void build(int o,int l,int r)
{
	setv[o]=-1;
	if(l==r){maxv[o]=minv[o]=0;return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void pushdown(int o,int l,int r)
{
	if(setv[o]==-1)	return;
	maxv[o<<1]=maxv[o<<1|1]=minv[o<<1]=minv[o<<1|1]=setv[o];
	setv[o<<1]=setv[o<<1|1]=setv[o];
	setv[o]=-1;
	pushup(o);
}
void set1(int o,int l,int r,int ql,int qr,int v)
{
	int mid=(l+r)>>1;
	if(ql<=l&&r<=qr)
	{
		if(maxv[o]<v){setv[o]=maxv[o]=minv[o]=v;return;}
		else if(minv[o]>=v)	return;
		else
		{
			set1(o<<1,l,mid,ql,qr,v);
			set1(o<<1|1,mid+1,r,ql,qr,v);
		}
	}
	pushdown(o,l,r);
	if(ql<=mid)	set1(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	set1(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
void set2(int o,int l,int r,int ql,int qr,int v)
{
	int mid=(l+r)>>1;
	if(ql<=l&&r<=qr)
	{
		if(minv[o]>v){setv[o]=maxv[o]=minv[o]=v;return;}
		else if(maxv[o]<=v)	return;
		else
		{
			set2(o<<1,l,mid,ql,qr,v);
			set2(o<<1|1,mid+1,r,ql,qr,v);
		}
	}
	pushdown(o,l,r);
	if(ql<=mid)	set2(o<<1,l,mid,ql,qr,v);
	if(mid<qr)	set2(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
void pushall(int o,int l,int r)
{
	int mid=(l+r)>>1;
	if(l==r){printf("%d\n",maxv[o]);return;}
	pushdown(o,l,r);
	pushall(o<<1,l,mid);
	pushall(o<<1|1,mid+1,r);
}
int main()
{
	scanf("%d%d",&N,&K);
	build(1,1,N);
	while(K--)
	{
		int a,b,c,v;
		scanf("%d%d%d%d",&a,&b,&c,&v);
		b++;c++;
		if(a==1)	set1(1,1,N,b,c,v);
		if(a==2)	set2(1,1,N,b,c,v);
	}
	pushall(1,1,N);
//	system("pause");
}
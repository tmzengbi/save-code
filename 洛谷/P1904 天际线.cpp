#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int maxv[maxn<<2],ltag[maxn<<2],ans[maxn],Index=1,cnt=1;
struct Line
{
	int l,r,h;
}node[maxn];
inline int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10-ch-'0';
		ch=getchar();
	}
	return shu*f;
}
void build(int o,int l,int r)
{
	maxv[o]=0;ltag[o]=-1;
	if(l==r)	return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void pushup(int o)
{
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]); 
}
void puttag(int o,int v)
{
	if(ltag[o]<v)
	{
		ltag[o]=v;
		maxv[o]=max(ltag[o],maxv[o]);
	}
}
void pushdown(int o)
{
	if(ltag[o]==-1)	return;
	ltag[o<<1]=max(ltag[o],ltag[o<<1]);
	if(maxv[o<<1]<ltag[o<<1])maxv[o<<1]=ltag[o<<1];
	ltag[o<<1|1]=max(ltag[o],ltag[o<<1|1]);
	if(maxv[o<<1|1]<ltag[o<<1|1])maxv[o<<1|1]=ltag[o<<1|1];
	ltag[o]=-1;
}
void change(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){puttag(o,v);return;}
	pushdown(o);
	int mid=(l+r)>>1;
	if(ql<=mid)change(o<<1,l,mid,ql,qr,v);
	if(mid<qr)change(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
void pushall(int o,int l,int r)
{
	if(l==r){ans[Index++]=maxv[o];return;}
	pushdown(o);
	int mid=(l+r)>>1;
	pushall(o<<1,l,mid);
	pushall(o<<1|1,mid+1,r);
}
int main()
{
	memset(ans,0,sizeof ans);
	int l,r,h;
	while(scanf("%d%d%d",&l,&h,&r)==3)
	{
		if(l==0&&h==0&&r==0)break;
		node[cnt].l=l;node[cnt].r=r;node[cnt].h=h;
		cnt++;
	}
	cnt--;
	build(1,1,10000);
	for(int i=1;i<=cnt;i++)
		change(1,1,10000,node[i].l,node[i].r-1,node[i].h);
	pushall(1,1,10000);
	for(int i=1;i<=10000;i++)
	{
		if(ans[i]!=ans[i-1])
		{
			printf("%d %d",i,ans[i]);
			printf(" ");
		}
	}
	system("pause");
}

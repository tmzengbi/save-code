#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
int L,T,O;
int a[maxn<<2],t[maxn<<2];
void pushup(int o)
{
	a[o]=a[o<<1]|a[o<<1|1];
}
void build(int o,int l,int r)
{
	a[o]=1;t[o]=0;if(l==r)return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void pushdown(int o,int l,int r)
{
	if(t[o]==0)	return;
	a[o<<1]=a[o<<1|1]=t[o];
	t[o<<1]=t[o<<1|1]=t[o];
	t[o]=0;
}
void pla(int o,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){t[o]=a[o]=1<<(c-1);return;}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)	pla(o<<1,l,mid,ql,qr,c);
	if(mid<qr)	pla(o<<1|1,mid+1,r,ql,qr,c);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return a[o];
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	int ans=0;
	if(ql<=mid) ans=ans|query(o<<1,l,mid,ql,qr);
	if(mid<qr)	ans=ans|query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
void pushall(int l,int r,int o)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	pushall(l,mid,o<<1);
	pushall(mid+1,r,o<<1|1);
	pushdown(l,r,o);
}
int main()
{
	scanf("%d%d%d",&L,&T,&O);
	build(1,1,L);
//	freopen("1.out","w",stdout);
	while(O--)
	{
		char c;int x,y;cin>>c;
		scanf("%d%d",&x,&y);
		if(x>y)	swap(x,y);
		if(c=='C'){int co;scanf("%d",&co);pla(1,1,L,x,y,co);}
		if(c=='P')
		{
			int ans=query(1,1,L,x,y),s=0;
			while(ans)
			{
				if(ans&1)s++;
				ans>>=1;
			}
			printf("%d\n",s);

		}
	}
//	system("pause");
}
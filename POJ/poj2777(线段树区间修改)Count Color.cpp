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
struct Node
{
	int v,tg;
}tr[maxn<<2];
void pushup(int o)
{
	tr[o].v=tr[o<<1].v|tr[o<<1|1].v;
}
void puttag(int o,int v)
{
	tr[o].v=v;
	tr[o].tg=v;
}
void pushdown(int o)
{
	if(tr[o].tg)
	{
		puttag(o<<1,tr[o].tg);
		puttag(o<<1|1,tr[o].tg);
		tr[o].tg=0;
	}
}
void update(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){puttag(o,v);return;}
	pushdown(o);
	int mid=l+r>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tr[o].v;
	int ans=0,mid=l+r>>1;
	pushdown(o);
	if(ql<=mid) ans=ans|query(o<<1,l,mid,ql,qr);
	if(mid<qr) ans=ans|query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
void build(int o,int l,int r)
{
	tr[o].v=1;
	if(l==r) return;
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
int n,t,m;
int main()
{
	scanf("%d%d%d",&n,&t,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		char opt[3];
		scanf("%s",opt);
		if(opt[0]=='C')
		{
			int l,r,c;scanf("%d%d%d",&l,&r,&c);
			if(l>r) swap(l,r);
			update(1,1,n,l,r,1<<c-1);
		}
		if(opt[0]=='P')
		{
			int l,r;scanf("%d%d",&l,&r);
			if(l>r) swap(l,r);
			int sum=query(1,1,n,l,r);
			int ans=0;
			while(sum)
			{
				if(sum&1)ans++;sum>>=1;
			}
			printf("%d\n",ans);
		}
	}
//	system("pause");
}
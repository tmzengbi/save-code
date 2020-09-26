#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=5e4+10;
const int inf=2147483647;
mt19937 rnd(time(NULL));
int Index=0;
struct Node
{
	int v,val,n,siz;
	Node *ch[2];
	Node(){n=siz=0;}
	int cmp(int x)
	{
		if(x==val) return -1;
		return val<x;
	}
}dizhi[32*maxn],*rt,*null;
inline void up(Node *o)
{
	o->siz=o->ch[0]->siz+o->ch[1]->siz+o->n;
}
void rotate(Node *&o,int d)
{
	Node *k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;
	up(o);up(k);o=k;
}
void insert(Node *&o,int v)
{
	if(o==null)
	{
		o=&dizhi[++Index];
		o->ch[0]=o->ch[1]=null;
		o->v=rnd();o->val=v;
		o->n=o->siz=1;
		return;
	}
	int d=o->cmp(v);
	if(d==-1){++o->n;++o->siz;return;}
	insert(o->ch[d],v);
	if(o->ch[d]->v>o->v) rotate(o,d^1);
	up(o);
}
void erase(Node *&o,int v)
{
	int d=o->cmp(v);
	if(d==-1)
	{
		if(o->n>1){--o->siz;--o->n;return;}
		else if(o->ch[0]==null) o=o->ch[1];
		else if(o->ch[1]==null) o=o->ch[0];
		else
		{
			int d2=(o->ch[0]->v>o->ch[1]->v);
			rotate(o,d2);
			erase(o->ch[d2],v);
		}
	}
	else erase(o->ch[d],v);
	if(o!=null) up(o);
}
int findrank(Node *o,int x)
{
	if(o==null) return 0;
	int d=o->cmp(x);
	if(d==-1) return o->ch[0]->siz;
	else if(d==0) return findrank(o->ch[0],x);
	else return findrank(o->ch[1],x)+o->ch[0]->siz+o->n;
}
int findpre(Node *o,int x)
{
	int sol=-inf;
	while(o!=null)
	{
		int d=o->cmp(x);
		if(d==1){sol=o->val;o=o->ch[1];}
		else o=o->ch[0];
	}
	return sol;
}
int findnext(Node *o,int x)
{
	int sol=inf;
	while(o!=null)
	{
		int d=o->cmp(x);
		if(d==0){sol=o->val;o=o->ch[0];}
		else o=o->ch[1];
	}
	return sol;
}
Node *t[maxn<<2];
int n,m,a[maxn];
void build(int o,int l,int r)
{
	t[o]=null;
	if(l==r) return;
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void update(int o,int l,int r,int q,int v)
{
	insert(t[o],v);
	if(l==r) return;
	int mid=l+r>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
}
void del(int o,int l,int r,int q,int v)
{
	erase(t[o],v);
	if(l==r) return;
	int mid=l+r>>1;
	if(q<=mid) del(o<<1,l,mid,q,v);
	else del(o<<1|1,mid+1,r,q,v);
}
int querypre(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr) return findpre(t[o],v);
	int mid=l+r>>1,ans=-inf;
	if(ql<=mid) ans=max(ans,querypre(o<<1,l,mid,ql,qr,v));
	if(mid<qr) ans=max(ans,querypre(o<<1|1,mid+1,r,ql,qr,v));
	return ans;
}
int querynext(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr) return findnext(t[o],v);
	int mid=l+r>>1,ans=inf;
	if(ql<=mid) ans=min(ans,querynext(o<<1,l,mid,ql,qr,v));
	if(mid<qr) ans=min(ans,querynext(o<<1|1,mid+1,r,ql,qr,v));
	return ans;
}
int queryrank(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr) return findrank(t[o],v);
	int mid=l+r>>1,ans=0;
	if(ql<=mid) ans+=queryrank(o<<1,l,mid,ql,qr,v);
	if(mid<qr) ans+=queryrank(o<<1|1,mid+1,r,ql,qr,v);
	return ans;
}
int querykth(int k,int ql,int qr)
{
	int l=0,r=1e8+1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(queryrank(1,1,n,ql,qr,mid)+1<=k) l=mid+1;
		else r=mid;
	}
	return querypre(1,1,n,ql,qr,l);
}
int main()
{
	rt=null=&dizhi[0];
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(1,1,n,i,a[i]);
	}
	while(m--)
	{
		int opt,l,r,x;scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",queryrank(1,1,n,l,r,x)+1);
		}
		if(opt==2)
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",querykth(x,l,r));
		}
		if(opt==3)
		{
			scanf("%d%d",&l,&x);
			del(1,1,n,l,a[l]);
			update(1,1,n,l,x);a[l]=x;
		}
		if(opt==4)
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",querypre(1,1,n,l,r,x));
		}
		if(opt==5)
		{
			scanf("%d%d%d",&l,&r,&x);
			printf("%d\n",querynext(1,1,n,l,r,x));
		}
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,m,a[maxn],tagk[maxn<<2],tagd[maxn<<2],tr[maxn<<2];
void build(int o,int l,int r)
{
	if(l==r)
	{
		tr[o]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void addtag(int o,int k,int d)
{
	tagk[o]+=k;tagd[o]+=d;
}
void pushdown(int o,int l,int r)
{
	if(tagk[o]||tagd[o])
	{
		int mid=l+r>>1;
		addtag(o<<1,tagk[o],tagd[o]);
		addtag(o<<1|1,tagk[o]+(mid-l+1)*tagd[o],tagd[o]);
		tagk[o]=tagd[o]=0;
	}
}
void update(int o,int l,int r,int ql,int qr,int k,int d)
{
	if(ql<=l&&r<=qr){addtag(o,k+(l-ql)*d,d);return;}
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(ql<=mid) update(o<<1,l,mid,ql,qr,k,d);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,k,d);
}
int query(int o,int l,int r,int q)
{
	if(l==r) return tr[o]+tagk[o];
	int mid=l+r>>1;
	pushdown(o,l,r);
	if(q<=mid) return query(o<<1,l,mid,q);
	else return query(o<<1|1,mid+1,r,q);	
}
/* DEBUG
void pushall(int o,int l,int r)
{
	if(l==r){printf("%d ",tr[o]+tagk[o]);return;}
	pushdown(o,l,r);
	int mid=l+r>>1;
	pushall(o<<1,l,mid);pushall(o<<1|1,mid+1,r);
}
void pt()
{
	pushall(1,1,n);
	puts("");
}
*/
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		int opt;scanf("%d",&opt);
		if(opt==1)
		{
			int l,r,k,d;scanf("%d%d%d%d",&l,&r,&k,&d);
			update(1,1,n,l,r,k,d);
		}
		else
		{
			int p;scanf("%d",&p);
			printf("%d\n",query(1,1,n,p));
		}
//		pt();
	}
//	system("pause");
}
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
const int maxn=2e5+10;
const int inf=2e9;
int tree[maxn<<2];
void push(int o)
{
	tree[o]=max(tree[o<<1],tree[o<<1|1]);
}
void build(int o,int l,int r)
{
	tree[o]=-inf;
	if(l==r)
	{
		if(l==0) tree[o]=0;
		return;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	push(o);
}
void update(int o,int l,int r,int q,int v)
{
	if(l==r){tree[o]=v;return;}
	int mid=l+r>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
	push(o);
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return tree[o];
	int mid=l+r>>1,ans=-inf;
	if(ql<=mid) ans=max(ans,query(o<<1,l,mid,ql,qr));
	if(mid<qr) ans=max(ans,query(o<<1|1,mid+1,r,ql,qr));
	return ans;
}
int n,l,r,a[maxn];
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	build(1,0,n);
	for(int i=0;i<=n;i++) scanf("%d",&a[i]);
	for(int i=l;i<=n;i++)
	{
		int le=max(0,i-r),ri=i-l;
		int x=query(1,0,n,le,ri);
		if(x!=-inf) update(1,0,n,i,x+a[i]);
	}
	printf("%d\n",query(1,0,n,n+1-r,n));
//	system("pause");
}
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll maxn=100010;
struct Node
{
	Node *ls,*rs;
	ll sum,lazy;
}tree[maxn<<1],*root=&tree[0];
ll a[maxn],N,M,t=1;
void pushup(Node *root)
{
	root->sum=root->ls->sum+root->rs->sum;
}
void build(Node *root,ll l,ll r)
{
	root->lazy=0;
	if(l==r){root->ls=NULL;root->rs=NULL;root->sum=a[l];return;}
	ll mid=(l+r)>>1;
	root->ls=&tree[t++];
	root->rs=&tree[t++];
	build(root->ls,l,mid);
	build(root->rs,mid+1,r);
	pushup(root);
}
void pushdown(Node *root,ll l,ll r)
{
	if(root->lazy==0)	return;
	ll mid=(l+r)>>1;
	root->ls->lazy+=root->lazy;
	root->ls->sum+=root->lazy*(mid-l+1); 
	root->rs->lazy+=root->lazy;
	root->rs->sum+=root->lazy*(r-mid);
	root->lazy=0;
}
void add(Node *root,ll l,ll r,ll ql,ll qr,ll v)
{
	if(ql<=l&&r<=qr){root->lazy+=v;root->sum+=v*(r-l+1);return;}
	ll mid=(l+r)>>1;
	pushdown(root,l,r);
	if(ql<=mid)	add(root->ls,l,mid,ql,qr,v);
	if(mid<qr)	add(root->rs,mid+1,r,ql,qr,v);
	pushup(root); 
}
ll query(Node *root,ll l,ll r,ll ql,ll qr)
{
	if(ql<=l&&r<=qr)	return root->sum;
	pushdown(root,l,r);
	ll mid=(l+r)>>1;
	ll ans=0;
	if(ql<=mid)	ans+=query(root->ls,l,mid,ql,qr);
	if(mid<qr)	ans+=query(root->rs,mid+1,r,ql,qr);
	return ans;
}
int main()
{
	scanf("%lld%lld",&N,&M);
	for(ll i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	build(root,1,N);
	while(M--)
	{
		ll m,x,y,v;
		scanf("%lld",&m);
		if(m==1)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			add(root,1,N,x,y,v);
		}
		if(m==2)
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(root,1,N,x,y));
		}
	}
}

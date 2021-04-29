#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int t,n,a[maxn],x,m,qq,b[maxn],c[maxn],d[maxn];
int tr[maxn<<2],tag[maxn<<2];
#define ls (o<<1)
#define rs (o<<1|1)
void up(int o) {
	tr[o]=tr[ls]+tr[rs];
}
void build(int o,int l,int r) {
	tag[o]=-1;
	if(l==r) {
		tr[o]=(a[l]>x);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	up(o);
}
void addtag(int o,int l,int r,int v) {
	tr[o]=v*(r-l+1);
	tag[o]=v;
}
void pushdown(int o,int l,int r) {
	if(tag[o]==-1) return;
	int mid=(l+r)>>1;
	addtag(ls,l,mid,tag[o]);
	addtag(rs,mid+1,r,tag[o]);
	tag[o]=-1;
}
void update(int o,int l,int r,int ql,int qr,int v) {
	if(ql<=l&&r<=qr) {
		addtag(o,l,r,v);
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) update(ls,l,mid,ql,qr,v);
	if(mid<qr) update(rs,mid+1,r,ql,qr,v);
	up(o);
}
int queryin(int o,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) return tr[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid) res+=queryin(ls,l,mid,ql,qr);
	if(mid<qr) res+=queryin(rs,mid+1,r,ql,qr);
	return res;
}
int query(int o,int l,int r,int q) {
	if(l==r) return tr[o];
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(q<=mid) return query(ls,l,mid,q);
	return query(rs,mid+1,r,q);
}
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) {
		scanf("%d%d%d",&b[i],&c[i],&d[i]);
	}
	scanf("%d",&qq);
	int l=0,r=n+1;
	while(l<r) {
		x=(l+r)>>1;
		build(1,1,n);
		for(int i=1;i<=m;++i) {
			int tot1=queryin(1,1,n,c[i],d[i]),tot0=d[i]-c[i]+1-tot1;
			if(tot1==0||tot1==d[i]-c[i]+1) continue;
			if(b[i]==1) {
				update(1,1,n,c[i],c[i]+tot1-1,1);
				update(1,1,n,c[i]+tot1,d[i],0);
			} else {
				update(1,1,n,c[i],c[i]+tot0-1,0);
				update(1,1,n,c[i]+tot0,d[i],1);
			}
		}
		int res=query(1,1,n,qq);
		if(res==0) {
			r=x;
		} else {
			l=x+1;
		}
	}
	printf("%d\n",l);
}
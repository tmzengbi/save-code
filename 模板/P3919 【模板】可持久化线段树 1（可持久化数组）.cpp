#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
int n,m,a[maxn];
struct Tree{
	int lson,rson;
	int cur;
}tr[maxn*21];
int head[maxn];
int cnt=0;
#define ls (tr[o].lson)
#define rs (tr[o].rson)
#define pls (tr[p].lson)
#define prs (tr[p].rson)
void build(int &o,int l,int r) {
	o=cnt++;
	if(l==r) {
		tr[o].cur=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);build(rs,mid+1,r);
}
void update(int &o,int p,int l,int r,int q,int v) {
	o=cnt++;
	if(l==r) {
		tr[o].cur=v;
		return;
	}
	tr[o]=tr[p];
	int mid=(l+r)>>1;
	if(q<=mid) update(ls,pls,l,mid,q,v);
	else update(rs,prs,mid+1,r,q,v);
}
int query(int o,int l,int r,int q) {
	if(l==r) return tr[o].cur;
	int mid=(l+r)>>1;
	if(q<=mid) return query(ls,l,mid,q);
	return query(rs,mid+1,r,q);
}
// void print(int o,int l,int r) {
// 	if(l==r) {
// 		printf("%d ",tr[o].cur);
// 		return;
// 	}
// 	int mid=(l+r)>>1;
// 	print(ls,l,mid);print(rs,mid+1,r);
// }
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(head[0],1,n);
	for(int i=1;i<=m;++i) {
		int v,opt,loc,val;
		scanf("%d%d",&v,&opt);
		if(opt==1) {
			scanf("%d%d",&loc,&val);
			update(head[i],head[v],1,n,loc,val);
		} else {
			scanf("%d",&loc);
			head[i]=head[v];
			int res=query(head[v],1,n,loc);
			printf("%d\n",res);
		}
	}
	
}
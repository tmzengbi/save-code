#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int head[maxn];
int n,m;
struct Tree {
	int ls,rs;
	ll sum;
}tr[maxn*25];
int cnt=1;
inline void up(int o) {
	tr[o].sum=tr[tr[o].ls].sum+tr[tr[o].rs].sum;
}
void update(int &o,int l,int r,int q,int v) {
	if(!o) o=cnt++;
	if(l==r) {
		tr[o].sum+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid) update(tr[o].ls,l,mid,q,v);
	else update(tr[o].rs,mid+1,r,q,v);
	up(o);
}
void merge(int &o,int &p,int l,int r) { // p->o
	if(!p) return;
	if(!o) {
		swap(o,p);
		return;
	}
	if(l==r) {
		tr[o].sum+=tr[p].sum;
		p=0;
		return;
	}
	int mid=(l+r)>>1;
	merge(tr[o].ls,tr[p].ls,l,mid);
	merge(tr[o].rs,tr[p].rs,mid+1,r);
	p=0;
	up(o);
}
void split(int &o,int &p,int l,int r,int ql,int qr) {
	if(!p) return;
	if(!o) o=cnt++;
	if(ql<=l&&r<=qr) {
		merge(o,p,l,r);
		assert(!p);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) split(tr[o].ls,tr[p].ls,l,mid,ql,qr);
	if(mid<qr) split(tr[o].rs,tr[p].rs,mid+1,r,ql,qr);
	up(o);up(p);
}
ll query(int o,int l,int r,int ql,int qr) {
	if(!o) return 0;
	if(ql<=l&&r<=qr) return tr[o].sum;
	int mid=(l+r)>>1;
	ll res=0;
	if(ql<=mid) res+=query(tr[o].ls,l,mid,ql,qr);
	if(mid<qr) res+=query(tr[o].rs,mid+1,r,ql,qr);
	return res;
}
ll query_kth(int o,int l,int r,int q) {
	if(l==r) return l;
	int ls=tr[o].ls,mid=(l+r)>>1;
	if(tr[ls].sum>=q) return query_kth(ls,l,mid,q);
	return query_kth(tr[o].rs,mid+1,r,q-tr[ls].sum);
}
// void print(int o,int l,int r) {
// 	if(!o) {
// 		for(int i=l;i<=r;++i)
// 			printf("0 ");
// 		return;
// 	}
// 	if(l==r){
// 		printf("%lld ",tr[o].sum);
// 		return;
// 	}
// 	int mid=(l+r)>>1;
// 	print(tr[o].ls,l,mid);
// 	print(tr[o].rs,mid+1,r);
// }
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	const int Mx=200000;
	int cur=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		int x;scanf("%d",&x);
		update(head[cur],1,Mx,i,x);
	}
	while(m--) {
		int opt,p,x,y;scanf("%d",&opt);
		if(opt==0) {
			scanf("%d%d%d",&p,&x,&y);
			split(head[++cur],head[p],1,Mx,x,y);
		} else if(opt==1) {
			scanf("%d%d",&p,&x);
			merge(head[p],head[x],1,Mx);
		} else if(opt==2) {
			scanf("%d%d%d",&p,&x,&y);
			update(head[p],1,Mx,y,x);
		} else if(opt==3) {
			scanf("%d%d%d",&p,&x,&y);
			ll res=query(head[p],1,Mx,x,y);
			printf("%lld\n",res);
		} else if(opt==4) {
			scanf("%d%d",&p,&x);
			ll res;
			if(x>tr[head[p]].sum) res=-1;
			else res=query_kth(head[p],1,Mx,x);
			printf("%lld\n",res);
		}
		// for(int i=1;i<=cur;++i) {
		// 	printf("seg %d is\n",i);
		// 	print(head[i],1,Mx);
		// 	puts("");
		// }
	}
}
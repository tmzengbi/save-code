#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
struct Node{
	int lc,rc;
	int sum;
	static int cnt;
}tr[maxn*32];
int Node::cnt=0;
int rt=0;
#define lson tr[o].lc
#define rson tr[o].rc
int &idx=Node::cnt;
void up(int o) {
	tr[o].sum=tr[lson].sum+tr[rson].sum;
}
void update(int &o,int l,int r,int q,int v) {
	if(!o) o=++idx;
	if(l==r) {
		tr[o].sum+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid) update(lson,l,mid,q,v);
	else update(rson,mid+1,r,q,v);
	up(o);
}
int query(int o,int l,int r,int ql,int qr) {
	if(!o) return 0;
	if(ql<=l&&r<=qr)
		return tr[o].sum;
	int mid=(l+r)>>1,res=0;
	if(ql<=mid) res+=query(lson,l,mid,ql,qr);
	if(mid<qr) res+=query(rson,mid+1,r,ql,qr);
	return res;
}
int n;
long long res=0;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		int t;scanf("%d",&t);
		res+=query(rt,0,1000000000,t+1,1000000000);
		update(rt,0,1000000000,t,1);
	}
	printf("%lld\n",res);
}
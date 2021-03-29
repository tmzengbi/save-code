#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int a[maxn],maxv[maxn<<2],maxv2[maxn<<2],tot[maxn<<2],tag[maxn<<2];
ll sum[maxn<<2];
inline void up(int o) {
	sum[o]=sum[o<<1]+sum[o<<1|1];
	if(maxv[o<<1]==maxv[o<<1|1]) {
		maxv[o]=maxv[o<<1];
		tot[o]=tot[o<<1]+tot[o<<1|1];
		maxv2[o]=max(maxv2[o<<1],maxv2[o<<1|1]);
	} else if(maxv[o<<1]>maxv[o<<1|1]){
		maxv[o]=maxv[o<<1];
		tot[o]=tot[o<<1];
		maxv2[o]=max(maxv2[o<<1],maxv[o<<1|1]);
	} else {
		maxv[o]=maxv[o<<1|1];
		tot[o]=tot[o<<1|1];
		maxv2[o]=max(maxv2[o<<1|1],maxv[o<<1]);
	}
}
void addtag(int o,int v){
	if(maxv[o]<=v) return;
	else if(maxv2[o]<v) {
		sum[o]-=1LL*(maxv[o]-v)*tot[o];
		maxv[o]=v;
		tag[o]=v;
		return;
	} else {
		addtag(o<<1,v);
		addtag(o<<1|1,v);
		up(o);
	}
}
inline void down(int o) {
	if(tag[o]==-1) return;
	addtag(o<<1,tag[o]);
	addtag(o<<1|1,tag[o]);
	tag[o]=-1;
}
void build(int o,int l,int r) {
	tag[o]=-1;
	if(l==r) {
		maxv[o]=sum[o]=a[l];
		tot[o]=1;
		maxv2[o]=-1;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	up(o);
}
void update(int o,int l,int r,int ql,int qr,int v) {
	if(ql<=l&&r<=qr) {
		addtag(o,v);
		return;
	}
	int mid=(l+r)>>1;
	down(o);
	if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
	up(o);
}
ll queryMax(int o,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) return maxv[o];
	int mid=(l+r)>>1;
	ll res=0;
	down(o);
	if(ql<=mid) res=max(res,queryMax(o<<1,l,mid,ql,qr));
	if(mid<qr) res=max(res,queryMax(o<<1|1,mid+1,r,ql,qr));
	return res;
}
ll querySum(int o,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) return sum[o];
	int mid=(l+r)>>1;
	ll res=0;
	down(o);
	if(ql<=mid) res+=querySum(o<<1,l,mid,ql,qr);
	if(mid<qr) res+=querySum(o<<1|1,mid+1,r,ql,qr);
	return res;
}
#define printall print(1,1,n);puts("");
void print(int o,int l,int r) {
	if(l==r) {
		printf("%d ",sum[o]);
		return;
	}
	int mid=(l+r)>>1;
	down(o);
	print(o<<1,l,mid);print(o<<1|1,mid+1,r);
}
int t,n,m;
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		build(1,1,n);
		while(m--) {
			int opt,x,y;
			scanf("%d%d%d",&opt,&x,&y);
			if(opt==0) {
				int xx;scanf("%d",&xx);
				update(1,1,n,x,y,xx);
				// printall
				// for(int i=1;i<=20;++i)
				// 	printf("%d ",maxv[i]);
				// puts("");
			} else if(opt==1){
				printf("%lld\n",queryMax(1,1,n,x,y));
			} else {
				printf("%lld\n",querySum(1,1,n,x,y));
			}
		}
	}
}
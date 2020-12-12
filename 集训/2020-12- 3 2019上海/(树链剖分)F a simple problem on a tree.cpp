#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=1e9+7;
const int maxn=1e5+10;
int f[maxn],dep[maxn],a[maxn],belong[maxn],fst[maxn],tp[maxn],son[maxn],siz[maxn],cnt;
vector<vector<int> >edges;
void dfs1(int u,int fa){
	siz[u]=1;
	for(int v:edges[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void dfs2(int u,int top){
	belong[++cnt]=u;
	fst[u]=cnt;
	tp[u]=top;
	if(son[u]) dfs2(son[u],top);
	for(int v:edges[u]){
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
inline int pow2(int x){
	return 1LL*x*x%P;
}
inline int pow3(int x){
	return 1LL*x*x%P*x%P;
}
struct Node{
	ll sumv[3],tag1,tag2,tag3;
}tr[maxn<<2];
inline void up(int o){
	for(int i=0;i<3;++i)
		tr[o].sumv[i]=(tr[o<<1].sumv[i]+tr[o<<1|1].sumv[i])%P;
}
void build(int o,int l,int r){
	tr[o].tag1=-1;
	tr[o].tag2=0;
	tr[o].tag3=1;
	if(l==r){
		tr[o].sumv[0]=a[belong[l]];
		tr[o].sumv[1]=pow2(a[belong[l]]);
		tr[o].sumv[2]=pow3(a[belong[l]]);
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	up(o);
}
inline void down(int o,int l,int r){
	if(tr[o].tag1!=-1){
		int mid=(l+r)>>1;
		tr[o<<1].tag1=tr[o].tag1;
		tr[o<<1|1].tag1=tr[o].tag1;
		tr[o<<1].tag2=tr[o<<1|1].tag2=0;
		tr[o<<1].tag3=tr[o<<1|1].tag3=1;

		tr[o<<1].sumv[0]=1LL*(mid-l+1)*tr[o].tag1%P;
		tr[o<<1].sumv[1]=1LL*(mid-l+1)*pow2(tr[o].tag1)%P;
		tr[o<<1].sumv[2]=1LL*(mid-l+1)*pow3(tr[o].tag1)%P;
		tr[o<<1|1].sumv[0]=1LL*(r-mid)*tr[o].tag1%P;
		tr[o<<1|1].sumv[1]=1LL*(r-mid)*pow2(tr[o].tag1)%P;
		tr[o<<1|1].sumv[2]=1LL*(r-mid)*pow3(tr[o].tag1)%P;
		tr[o].tag1=-1;
	}
	if(tr[o].tag2||tr[o].tag3!=1){
		ll mid=(l+r)>>1;
		tr[o<<1].tag2=(tr[o].tag3*tr[o<<1].tag2%P+tr[o].tag2)%P;
		tr[o<<1].tag3=tr[o].tag3*tr[o<<1].tag3%P;
		tr[o<<1|1].tag2=(tr[o].tag3*tr[o<<1|1].tag2%P+tr[o].tag2)%P;
		tr[o<<1|1].tag3=tr[o].tag3*tr[o<<1|1].tag3%P;

		ll B=tr[o].tag2,A=tr[o].tag3;
		tr[o<<1].sumv[2]=(tr[o<<1].sumv[2]*pow3(A)%P+3LL*B%P*pow2(A)%P*tr[o<<1].sumv[1]%P+3LL*pow2(B)%P*A%P*tr[o<<1].sumv[0]%P+(mid-l+1)*pow3(B)%P)%P;
		tr[o<<1].sumv[1]=(tr[o<<1].sumv[1]*pow2(A)%P+2LL*A*B%P*tr[o<<1].sumv[0]%P+pow2(B)*(mid-l+1)%P)%P;
		tr[o<<1].sumv[0]=(tr[o<<1].sumv[0]*A%P+(mid-l+1)*B%P)%P;
		
		tr[o<<1|1].sumv[2]=(tr[o<<1|1].sumv[2]*pow3(A)%P+3LL*B%P*pow2(A)%P*tr[o<<1|1].sumv[1]%P+3LL*pow2(B)%P*A%P*tr[o<<1|1].sumv[0]%P+(r-mid)*pow3(B)%P)%P;
		tr[o<<1|1].sumv[1]=(tr[o<<1|1].sumv[1]*pow2(A)%P+2LL*A*B%P*tr[o<<1|1].sumv[0]%P+pow2(B)*(r-mid)%P)%P;
		tr[o<<1|1].sumv[0]=(tr[o<<1|1].sumv[0]*A%P+(r-mid)*B%P)%P;
		tr[o].tag2=0;
		tr[o].tag3=1;
	}
}
void updatex(int o,int l,int r,int ql,int qr,int v){//set
	if(ql<=l&&r<=qr){
		tr[o].sumv[0]=1LL*(r-l+1)*v%P;
		tr[o].sumv[1]=1LL*(r-l+1)*pow2(v)%P;
		tr[o].sumv[2]=1LL*(r-l+1)*pow3(v)%P;
		tr[o].tag1=v;
		tr[o].tag2=0;
		tr[o].tag3=1;
		return;
	}
	int mid=(l+r)>>1;
	down(o,l,r);
	if(ql<=mid) updatex(o<<1,l,mid,ql,qr,v);
	if(mid<qr) updatex(o<<1|1,mid+1,r,ql,qr,v);
	up(o);
}
void updatey(int o,int l,int r,int ql,int qr,int v){//add
	if(ql<=l&&r<=qr){
		tr[o].sumv[2]=(tr[o].sumv[2]+3LL*v*tr[o].sumv[1]%P+3LL*pow2(v)*tr[o].sumv[0]%P+1LL*(r-l+1)*pow3(v)%P)%P;
		tr[o].sumv[1]=(tr[o].sumv[1]+2LL*v*tr[o].sumv[0]%P+1LL*(r-l+1)*pow2(v)%P)%P;
		tr[o].sumv[0]=(tr[o].sumv[0]+1LL*(r-l+1)*v%P)%P;
		tr[o].tag2=(v+tr[o].tag2)%P;
		return;
	}
	int mid=(l+r)>>1;
	down(o,l,r);
	if(ql<=mid) updatey(o<<1,l,mid,ql,qr,v);
	if(mid<qr) updatey(o<<1|1,mid+1,r,ql,qr,v);
	up(o);
}
void updatez(int o,int l,int r,int ql,int qr,int v){//time
	if(ql<=l&&r<=qr){
		tr[o].sumv[2]=tr[o].sumv[2]*pow3(v)%P;
		tr[o].sumv[1]=tr[o].sumv[1]*pow2(v)%P;
		tr[o].sumv[0]=tr[o].sumv[0]*v%P;
		tr[o].tag3=tr[o].tag3*v%P;
		tr[o].tag2=tr[o].tag2*v%P;
		return;
	}
	int mid=(l+r)>>1;
	down(o,l,r);
	if(ql<=mid) updatez(o<<1,l,mid,ql,qr,v);
	if(mid<qr) updatez(o<<1|1,mid+1,r,ql,qr,v);
	up(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tr[o].sumv[2];
	ll res=0,mid=(l+r)>>1;
	down(o,l,r);
	if(ql<=mid) res+=query(o<<1,l,mid,ql,qr);
	if(mid<qr) res+=query(o<<1|1,mid+1,r,ql,qr);
	res%=P;
	return res;
}
void pushall(int o,int l,int r){
	if(l==r) {
		return;
	}
	down(o,l,r);
	int mid=(l+r)>>1;
	pushall(o<<1,l,mid);
	pushall(o<<1|1,mid+1,r);
}
int t,n,q;
void init(){
	edges.clear();
	edges.resize(n+1);
	memset(son,0,sizeof son);
	cnt=0;
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("wa.out","w",stdout);
	int cas=0;
	scanf("%d",&t);
	while(t--){
		printf("Case #%d:\n",++cas);
		scanf("%d",&n);
		init();
		for(int i=1;i<n;++i){
			int u,v;scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		dfs1(1,1);
		dfs2(1,1);
		build(1,1,n);
		scanf("%d",&q);
		while(q--){
//			pushall(1,1,n);
//			puts("");
			int opt;scanf("%d",&opt);
			int u,v,w;
			if(opt==4){
				scanf("%d%d",&u,&v);
				ll res=0;
				while(tp[u]!=tp[v]){
					if(dep[tp[u]]>dep[tp[v]]) swap(u,v);
					res=(res+query(1,1,n,fst[tp[v]],fst[v]))%P;
					v=f[tp[v]];
				}
				if(dep[u]>dep[v]) swap(u,v);
				res=(res+query(1,1,n,fst[u],fst[v]))%P;
				assert(res>=0);
				printf("%lld\n",res);
			} else {
				scanf("%d%d%d",&u,&v,&w);
				while(tp[u]!=tp[v]){
					if(dep[tp[u]]>dep[tp[v]]) swap(u,v);
					if(opt==1) updatex(1,1,n,fst[tp[v]],fst[v],w);
					if(opt==2) updatey(1,1,n,fst[tp[v]],fst[v],w);
					if(opt==3) updatez(1,1,n,fst[tp[v]],fst[v],w);
					v=f[tp[v]];
				}
				if(dep[u]>dep[v]) swap(u,v);
				if(opt==1) updatex(1,1,n,fst[u],fst[v],w);
				if(opt==2) updatey(1,1,n,fst[u],fst[v],w);
				if(opt==3) updatez(1,1,n,fst[u],fst[v],w);
			}
		}
	}
}
/*
1
5
2 1
1 3
5 3
4 3
1 2 3 4 5
6
4 2 4
1 5 4 2
2 2 4 3
3 2 3 4
4 5 4
4 2 4
*/
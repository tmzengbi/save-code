#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,k,w[maxn],dep[maxn],siz[maxn],son[maxn];
vector<vector<int> >edges;
ll res=0;
struct Node{
	int lc,rc,sum;
}node[3000010];
int top[maxn];
int idx=0;
void update(int &tp,int l,int r,int q,int v){
	if(!tp) tp=++idx;
	node[tp].sum+=v;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(q<=mid) update(node[tp].lc,l,mid,q,v);
	else update(node[tp].rc,mid+1,r,q,v);
}
void dfs1(int u){
	siz[u]=1;
	for(int v:edges[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
			son[u]=v;
	}
}
ll query(int tp,int l,int r,int ql,int qr){
	if(!tp) return 0;
	if(ql<=l&&r<=qr) return node[tp].sum;
	int mid=(l+r)>>1;
	ll res=0;
	if(ql<=mid) res+=query(node[tp].lc,l,mid,ql,qr);
	if(mid<qr) res+=query(node[tp].rc,mid+1,r,ql,qr);
	return res;
}
void upd(int u,int val){
	update(top[w[u]],1,n,dep[u],val);
	for(int v:edges[u]){
		upd(v,val);
	}
}
void count(int u,int tp){
	int cal=w[tp]*2-w[u];
	int d=min(k+dep[tp]*2-dep[u],n);
	if(cal>=0&&cal<=n&&d>=1)
		res+=query(top[cal],1,n,1,d);
	for(int v:edges[u]){
		count(v,tp);
	}
}
/*
void dfs(int u,int kp){
	for(int v:edges[u]){
		if(v==son[u]) continue;
		dfs(v,0);
	}
	if(son[u]) dfs(son[u],1);
	for(int v:edges[u]){
		if(v==son[u]) continue;
		count(v,u);upd(v,1);
	}
	update(top[w[u]],1,n,dep[u],1);
	if(!kp) upd(u,-1);
}*/
void dfs(int u){
	for(int v:edges[u]){
		if(v==son[u]) continue;
		dfs(v);upd(v,-1);
	}
	if(son[u]) dfs(son[u]);
	for(int v:edges[u]){
		if(v==son[u]) continue;
		count(v,u),upd(v,1);
	}
	update(top[w[u]],1,n,dep[u],1);
}
int main(){
	#ifdef DEBUG
		freopen("a.in","r",stdin);
		freopen("wa.out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	edges.resize(n+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	for(int i=2;i<=n;++i){
		int f;scanf("%d",&f);
		edges[f].push_back(i);
	}
	dep[1]=1;
	dfs1(1);
	dfs(1);
	printf("%lld\n",res*2);
//	cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}
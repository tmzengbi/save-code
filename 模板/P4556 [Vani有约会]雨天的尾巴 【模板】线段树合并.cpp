#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,m;
const int tot=100000;
int f[20][maxn],dep[maxn];
vector<int>edges[maxn];
void dfs(int u,int fa) {
	for(int v:edges[u]) {
		if(v==fa) continue;
		f[0][v]=u;
		for(int i=1;i<20;++i)
			f[i][v]=f[i-1][f[i-1][v]];
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
int getlca(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;--i)
		if(dep[u]-(1<<i)>=dep[v]) u=f[i][u];
	if(u==v) return u;
	for(int i=19;i>=0;--i)
		if(f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
	return f[0][u];
}
struct Tree{
	int ls,rs;
	int mx,id;
}tr[maxn*20];
int cnt=0;
inline void up(int o) {
	int ls=tr[o].ls,rs=tr[o].rs;
	if(tr[ls].mx>=tr[rs].mx) {
		tr[o].mx=tr[ls].mx;
		tr[o].id=tr[ls].id;
	} else {
		tr[o].mx=tr[rs].mx;
		tr[o].id=tr[rs].id;
	}
}
void update(int &o,int l,int r,int q,int v) {
	if(!o) o=cnt++;
	if(l==r) {
		tr[o].mx+=v;
		tr[o].id=l;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid) update(tr[o].ls,l,mid,q,v);
	else update(tr[o].rs,mid+1,r,q,v);
	up(o);
}
int merge(int a,int b,int l,int r) {
	if(!a) return b;
	if(!b) return a;
	if(l==r) {
		if(l==r) tr[a].mx+=tr[b].mx;
		return a;
	}
	int mid=(l+r)>>1;
	tr[a].ls=merge(tr[a].ls,tr[b].ls,l,mid);
	tr[a].rs=merge(tr[a].rs,tr[b].rs,mid+1,r);
	up(a);
	return a;
}
int res[maxn],head[maxn];
vector<pii>r[maxn];
void dfs2(int u) {
	for(int v:edges[u]) {
		if(v==f[0][u]) continue;
		dfs2(v);
		head[u]=merge(head[u],head[v],1,tot);
	}
	for(auto &x:r[u])
		update(head[u],1,tot,x.first,x.second);
	// cout<<u<<" "<<tr[head[u]].id<<" "<<tr[head[u]].mx<<endl;
	res[u]=tr[head[u]].mx?tr[head[u]].id:0;
}
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i) {
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		head[i]=i;
	cnt=n+1;
	dfs(1,1);
	for(int i=1;i<=m;++i) {
		int u,v,z;scanf("%d%d%d",&u,&v,&z);
		int lca=getlca(u,v);
		r[u].push_back({z,1});
		r[v].push_back({z,1});
		r[lca].push_back({z,-1});
		r[f[0][lca]].push_back({z,-1});
	}
	dfs2(1);
	for(int i=1;i<=n;++i)
		printf("%d\n",res[i]);
}
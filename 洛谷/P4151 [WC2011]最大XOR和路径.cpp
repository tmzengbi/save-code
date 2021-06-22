#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int maxn=5e4+10;
const int maxm=1e5+10;
int n,m;
struct Edge{
	int u,v,ok;
	ll d;
	bool operator < (const Edge & rhs) const {
		return d<rhs.d;
	}
}p[maxm];
vector<pil>edges[maxn];
int f[maxn];
int find(int x) {
	return x==f[x]?x:(f[x]=find(f[x]));
}
ll d[maxn];
void dfs(int u,int fa) {
	for(auto &to:edges[u]) {
		int v=to.first;
		if(v==fa) continue;
		d[v]=d[u]^to.second;
		dfs(v,u);
	}
}
ll a[66];
void insert(ll x) {
	for(int i=63;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(a[i]) x^=a[i];
		else {
			a[i]=x;
			break;
		}
	}
}
ll solve(ll x) {
	ll res=x;
	for(int i=63;i>=0;--i)
		if((res^a[i])>res) res^=a[i];
	return res;
}
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) {
		scanf("%d%d%lld",&p[i].u,&p[i].v,&p[i].d);
		p[i].ok=0;
	}
	for(int i=1;i<=m;++i) {
		if(find(p[i].u)==find(p[i].v)) continue;
		edges[p[i].u].push_back({p[i].v,p[i].d});
		edges[p[i].v].push_back({p[i].u,p[i].d});
		f[find(p[i].u)]=find(p[i].v);
		p[i].ok=1;
	}
	dfs(1,1);
	for(int i=1;i<=m;++i) {
		if(!p[i].ok) {
			int u=p[i].u,v=p[i].v;
			insert(d[u]^d[v]^p[i].d);
		}
	}
	ll res=solve(d[n]);
	printf("%lld\n",res);
}
// 0001111110011111
// 0001111111011111
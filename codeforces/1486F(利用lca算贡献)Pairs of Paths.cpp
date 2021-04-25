#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3e5+10;
int n,m;
int tr[maxn];
int dfn[maxn];
map<int,int>mp;
inline void update(int o,int x) {
	for(;o<=n;o+=(o&-o))
		tr[o]+=x;
}
inline ll query(int o) {
	ll res=0;
	for(;o>0;o-=(o&-o))
		res+=tr[o];
	return res;
}
vector<int>edges[maxn];
int st[maxn],ed[maxn],cnt=0,f[20][maxn],dep[maxn];
struct Edge{
	int x,y,a,b,lca;
    bool operator < (const Edge & rhs) const {
        return a<rhs.a;
    }
}p[maxn];
void pre(int u,int fa){
	st[u]=++cnt;
    dfn[cnt]=u;
	for(int v:edges[u]) {
		if(v==fa) continue;
		f[0][v]=u;
		dep[v]=dep[u]+1;
		for(int i=1;i<20;++i)
			f[i][v]=f[i-1][f[i-1][v]];
		pre(v,u);
	}
	ed[u]=cnt;
}
int getlca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;--i)
		if(dep[x]-(1<<i)>=dep[y]) x=f[i][x];
	if(x==y) return x;
	for(int i=19;i>=0;--i) {
		if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	}
	return f[0][x];
}
vector<Edge> c[maxn];
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
	scanf("%d",&n);
	for(int i=1;i<n;++i) {
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	scanf("%d",&m);
	pre(1,1);
	for(int i=1;i<=m;++i) {
		int x,y;scanf("%d%d",&x,&y);
		p[i].x=x;p[i].y=y;
		p[i].lca=getlca(p[i].x,p[i].y);
		if(p[i].lca==x) {
			p[i].a=-1;
		} else {
			int tmp=x;
			for(int j=19;j>=0;--j)
				if(dep[tmp]-(1<<j)>dep[p[i].lca]) tmp=f[j][tmp];
			p[i].a=tmp;
		}
		if(p[i].lca==y) {
			p[i].b=-1;
		} else {
			int tmp=y;
			for(int j=19;j>=0;--j)
				if(dep[tmp]-(1<<j)>dep[p[i].lca]) tmp=f[j][tmp];
			p[i].b=tmp;
		}
		if(p[i].a>p[i].b) {
            swap(p[i].a,p[i].b);
            swap(p[i].x,p[i].y);
        }
        c[p[i].lca].push_back(p[i]);
	}
	ll resA=0,resB=0;
	for(int i=1;i<=n;++i) {
        sort(c[i].begin(),c[i].end());
        mp.clear();
        int siz=c[i].size(),l=0;
        for(int j=0;j<siz;++j) {
            if(j==siz-1||c[i][j].a==-1||c[i][j].a!=c[i][j+1].a) {
                resA+=1LL*l*(j-l+1);
                for(int kk=l;kk<=j;++kk) {
                    if(c[i][kk].b!=-1) resA-=mp[c[i][kk].b];
                    if(c[i][kk].a!=-1) resA-=mp[c[i][kk].a];
                }
                for(int kk=l;kk<=j;++kk)
                    if(c[i][kk].b!=-1)
                        ++mp[c[i][kk].b];
                l=j+1;
            }
        }
    }
    for(int i=1;i<=n;++i) {
        int u=dfn[i];
        for(auto &cur:c[u]) {
            resB+=query(ed[cur.lca])-query(st[cur.lca]-1);
            if(cur.a!=-1) resB-=query(ed[cur.a])-query(st[cur.a]-1);
            if(cur.b!=-1) resB-=query(ed[cur.b])-query(st[cur.b]-1);
        }
        for(auto &cur:c[u]) {
            if(cur.a!=-1) update(st[cur.x],1);
            if(cur.b!=-1) update(st[cur.y],1);
        }
    }
    printf("%lld\n",resA+resB);
}
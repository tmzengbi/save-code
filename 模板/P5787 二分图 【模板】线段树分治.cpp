#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
vector<int>tr[maxn<<2];
const int maxm=2e5+10;
pii p[maxm];
#define mid ((l+r)>>1)
#define ls (o<<1)
#define rs (o<<1|1)
int res[maxn];
int f[maxn<<1],siz[maxn<<1];
int find(int x) {
    return x==f[x]?x:find(f[x]);
}
int ok=1;
int n,m,k;
void run(int o,int l,int r) {
    vector<pii>pp;
    int tmp=ok;
    for(auto &x:tr[o]) {
        auto &e=p[x];
        int u=find(e.first+n),v=find(e.second);
        if(u!=v) {
            if(siz[u]>siz[v]) swap(u,v);
            f[u]=v;
            siz[v]+=siz[u];
            pp.push_back({u,v});
        }
        u=find(e.first),v=find(e.second+n);
        if(u!=v) {
            if(siz[u]>siz[v]) swap(u,v);
            f[u]=v;
            siz[v]+=siz[u];
            pp.push_back({u,v});
        }
        if(find(e.first)==find(e.second)||find(e.first+n)==find(e.second+n)) ok=0;
    }
    if(l==r) {
        res[l]=ok;
    } else {
        run(ls,l,mid);run(rs,mid+1,r);
    }
    for(auto &x:pp) {
        siz[x.second]-=siz[x.first];
        f[x.first]=x.first;
    }
    ok=tmp;
}
void update(int o,int l,int r,int ql,int qr,int v) {
    if(ql<=l&&r<=qr) {
        tr[o].push_back(v);
        return;
    }
    if(ql<=mid) update(ls,l,mid,ql,qr,v);
    if(mid<qr) update(rs,mid+1,r,ql,qr,v);
}
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n*2;++i) {
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;++i) {
        int u,v,l,r;scanf("%d%d%d%d",&u,&v,&l,&r);
        if(l!=r)
            update(1,1,k,l+1,r,i);
        p[i]={u,v};
    }
    run(1,1,k);
    for(int i=1;i<=k;++i)
        puts(res[i]?"Yes":"No");
}
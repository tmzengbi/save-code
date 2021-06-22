#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
vector<int>tr[maxn<<2];
int n,m,k;
const int maxm=maxn<<1;
pii p[maxm];
vector<int>c[maxm];
#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
void update(int o,int l,int r,int ql,int qr,int v) {
    if(ql<=l&&r<=qr) {
        tr[o].push_back(v);
        return;
    }
    if(ql<=mid) update(ls,l,mid,ql,qr,v);
    if(mid<qr) update(rs,mid+1,r,ql,qr,v);
}
int res[maxn];
int f[maxn],siz[maxn];
int find(int x) {
    return f[x]==x?x:find(f[x]);
}
int ok=0;
void run(int o,int l,int r) {
    vector<pii>cc;
    int tmp=ok;
    for(auto x:tr[o]) {
        auto &e=p[x];
        int u=find(e.first),v=find(e.second);
        if(u!=v) {
            ++ok;
            if(siz[u]>siz[v]) swap(u,v);
            siz[v]+=siz[u];
            f[u]=v;
            cc.push_back({u,v});
        }
    }
    if(l==r) {
        res[l]=(ok==n-1);
    } else {
        run(ls,l,mid);
        run(rs,mid+1,r);
    }
    for(auto &x:cc) {
        siz[x.second]-=siz[x.first];
        f[x.first]=x.first;
    }
    ok=tmp;
}
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) 
        scanf("%d%d",&p[i].first,&p[i].second);
    scanf("%d",&k);
    for(int i=1;i<=n;++i) {
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;++i)
        c[i].push_back(0);
    for(int i=1;i<=k;++i) {
        int x;scanf("%d",&x);
        while(x--) {
            int kk;scanf("%d",&kk);
            c[kk].push_back(i);
        }
    }
    for(int i=1;i<=m;++i) {
        c[i].push_back(k+1);
        int siz=c[i].size();
        for(int j=1;j<siz;++j) {
            int l=c[i][j-1]+1,r=c[i][j]-1;
            if(l<=r)
                update(1,1,k,l,r,i);
        }
    }
    run(1,1,k);
    for(int i=1;i<=k;++i)
        puts(res[i]?"Connected":"Disconnected");
}
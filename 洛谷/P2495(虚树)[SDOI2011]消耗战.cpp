#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll>pii;
const int maxn=5e5+10;
int n,m;
vector<pii>edges[maxn],ee[maxn];
int ok[maxn],k[maxn],f[20][maxn],dep[maxn],dfn[maxn],idx;
ll dis[20][maxn];
int s[maxn],id;
int mk[maxn],idd;
ll getlca(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;--i)
        if(dep[x]-(1<<i)>=dep[y]) x=f[i][x];
    if(x==y) return x;
    for(int i=19;i>=0;--i)
        if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
    return f[0][x];
}
ll get(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    ll res=2e9;
    for(int i=19;i>=0;--i)
        if(dep[x]-(1<<i)>=dep[y]) {
            res=min(res,dis[i][x]);
            x=f[i][x];
        }
    return res;
}
void dfs(int u,int fa) {
    dfn[u]=++idx;
    for(auto &to:edges[u]) {
        int v=to.first;
        if(v==fa) continue;
        f[0][v]=u;
        dis[0][v]=to.second;
        for(int i=1;i<20;++i) {
            f[i][v]=f[i-1][f[i-1][v]];
            dis[i][v]=min(dis[i-1][f[i-1][v]],dis[i-1][v]);
        }
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
ll solve(int u,int fa) {
    ll res=0,dist2fa=get(u,fa);
    if(ok[u]) return dist2fa;
    for(auto v:ee[u]) {
        if(v.first==fa) continue;
        res+=solve(v.first,u);
    }
    return min(res,dist2fa);
}
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
    scanf("%d",&n);
    for(int i=1;i<n;++i) {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        edges[u].push_back({v,d});
        edges[v].push_back({u,d});
    }
    dfs(1,1);
    scanf("%d",&m);
    while(m--) {
        int kk;scanf("%d",&kk);
        for(int i=1;i<=kk;++i) {
            scanf("%d",&k[i]);
            ok[k[i]]=1;
        }
        sort(k+1,k+kk+1,[](const int lhs,const int rhs){
            return dfn[lhs]<dfn[rhs];
        });
        // for(int i=1;i<=kk;++i)
        //     cout<<k[i]<<" ";
        // cout<<endl;
        // for(int i=1;i<=kk;++i)
        //     cout<<dfn[k[i]]<<" ";
        // cout<<endl;
        s[id=1]=1;
        for(int i=1;i<=kk;++i) {
            int lca=getlca(s[id],k[i]);
            if(!id||lca==s[id]) {
                s[++id]=k[i];
            } else {
                while(dfn[s[id]]>dfn[lca]) {
                    mk[++idd]=s[id];
                    ll d=get(s[id],s[id-1]);
                    int pre=s[id-1];
                    if(dfn[pre]<dfn[lca]) pre=lca;
                    ee[s[id]].push_back({pre,d});
                    ee[pre].push_back({s[id],d});
                    --id;
                }
                if(s[id]!=lca) s[++id]=lca;
                s[++id]=k[i];
            }
        }
        while(id>1) {
            mk[++idd]=s[id];
            int pre=s[id-1],d=get(pre,s[id]);
            ee[s[id]].push_back({pre,d});
            ee[pre].push_back({s[id],d});
            --id;
        }
        mk[++idd]=1;
        ll res=0;
        for(auto &x:ee[1])
            res+=solve(x.first,1);
        printf("%lld\n",res);
        while(idd) ee[mk[idd--]].clear();
        for(int i=1;i<=kk;++i) ok[k[i]]=0;
    }
}
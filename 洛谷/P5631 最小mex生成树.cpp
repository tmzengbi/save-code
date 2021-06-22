#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e6+10;
const int maxm=2e6+10;
int n,m;
template<typename T>
void read(T &x) {
    x=0;
    int f=0;
    char ch=getchar();
    while(!isdigit(ch)) {
        if(ch=='-') f=1;
        ch=getchar();
    }
    while(isdigit(ch)) {
        x=x*10+ch-'0';
        ch=getchar();
    }
    if(f) x=-x;
}
const int N=1e5+10;
vector<int>tr[N<<2];
pii p[maxm];
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
int cur=0;
int f[maxn],siz[maxn],res=0x3f3f3f3f;
int find(int x) {
    return x==f[x]?x:find(f[x]);
}
void run(int o,int l,int r) {
    vector<pii>cc;
    int tmp=cur;
    for(int x:tr[o]) {
        auto &e=p[x];
        int a=find(e.first),b=find(e.second);
        if(a!=b) {
            if(siz[a]>siz[b]) swap(a,b);
            f[a]=b;
            siz[b]+=siz[a];
            ++cur;
            cc.push_back({a,b});
        }
    }
    if(l==r) {
        if(cur==n-1)
            res=min(res,l);
    } else {
        run(ls,l,mid);
        run(rs,mid+1,r);
    }
    for(auto &x:cc) {
        siz[x.second]-=siz[x.first];
        f[x.first]=x.first;
    }
    cur=tmp;
}
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
    read(n);read(m);
    for(int i=1;i<=n;++i) {
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;++i) {
        int d;
        read(p[i].first);read(p[i].second);read(d);        
        if(d!=0) update(1,0,100000,0,d-1,i);
        if(d!=100000) update(1,0,100000,d+1,100000,i);
    }
    run(1,0,100000);
    printf("%d\n",res);
}
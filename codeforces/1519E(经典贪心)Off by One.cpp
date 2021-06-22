#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
const int maxn=2*(2e5+10);
struct Node{
    int a,b,c,d;
}p[maxn];
struct Edge{
    int v,id,use;
    Edge(int v,int id):v(v),id(id),use(0){}
};
vector<Edge>edges[maxn];
int cur;
map<pll,int>mp;
ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}
void simp(pll & x) {
    ll tmp=gcd(x.first,x.second);
    x.first/=tmp;
    x.second/=tmp;
}
int dep[maxn];
vector<int>son[maxn];
vector<pii>res;
void dfs(int u,Edge *pre) {
    queue<int>q;
    for(auto &to:edges[u]) {
        int v=to.v;
        if(!dep[v]) {
            dep[v]=dep[u]+1;
            dfs(v,&to);
            if(!to.use) q.push(to.id);
        } else if(dep[v]>dep[u]) {
            q.push(to.id);
        }
    }
    if((q.size()&1)&&pre!=nullptr) {
        q.push(pre->id);
        pre->use=1;
    }
    while(q.size()>=2) {
        int a=q.front();q.pop();
        int b=q.front();q.pop();
        res.push_back({a,b});
    }
}
int main() {
    #ifdef DEBUG
    freopen("a.in","r",stdin);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d%d%d%d",&p[i].a,&p[i].b,&p[i].c,&p[i].d);
    }
    for(int i=1;i<=n;++i) {
        pll tmp;
        tmp={1LL*p[i].c*p[i].b,1LL*p[i].d*(p[i].a+p[i].b)};
        simp(tmp);
        if(!mp.count(tmp))
            mp[tmp]=++cur;
        int u=mp[tmp];
        tmp={1LL*(p[i].c+p[i].d)*p[i].b,1LL*p[i].d*p[i].a};
        simp(tmp);
        if(!mp.count(tmp))
            mp[tmp]=++cur;
        int v=mp[tmp];
        edges[u].push_back(Edge(v,i));
        edges[v].push_back(Edge(u,i));
    }
    for(int i=1;i<=cur;++i) {
        if(!dep[i]) {
            dep[i]=1;
            dfs(i,nullptr);
        }
    }
    int tot=res.size();
    printf("%d\n",tot);
    for(auto &x:res) {
        printf("%d %d\n",x.first,x.second);
    }
}
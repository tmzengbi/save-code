#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e4+10;
typedef long long ll;
int n,m;
struct Node{
	int v,d;
	Node(int v,int d):v(v),d(d){}
};
int p[maxn];
vector<Node>edges[maxn];
int f[17][maxn],dep[maxn];
ll d[17][maxn];
void prework(int u,int fa){
	for(auto to:edges[u]){
		if(to.v==fa) continue;
		dep[to.v]=dep[u]+1;
		f[0][to.v]=u;
		d[0][to.v]=to.d;
		for(int i=1;(1<<i)<=dep[to.v];++i){
			f[i][to.v]=f[i-1][f[i-1][to.v]];
			d[i][to.v]=d[i-1][f[i-1][to.v]]+d[i-1][to.v];
		}
		prework(to.v,u);
	}
}
bool vis[maxn],need[maxn];
typedef pair<ll,int>pli;
vector<pli>c;
vector<ll>qwq,qaq;
bool dfs(int u){
	if(vis[u]) return true;
	bool havechild=0;
	for(auto to:edges[u]){
		if(dep[to.v]<dep[u]) continue;
		havechild=1;
		if(!dfs(to.v)) return false;
	}
	if(!havechild) return false;
	return true;
}
bool check(ll x){
	memset(vis,0,sizeof vis);
	memset(need,0,sizeof need);
	c.clear();qwq.clear();qaq.clear();
	for(int i=1;i<=m;++i){
		ll cnt=0;int now=p[i];
		for(int j=15;j>=0;--j)
			if(f[j][now]>1&&cnt+d[j][now]<=x){
				cnt+=d[j][now];
				now=f[j][now];
			}
		if(dep[now]==1&&cnt+d[0][now]<=x){
			c.push_back(make_pair(x-cnt-d[0][now],now));
		} else {
			vis[now]=1;
		}
	}
	for(auto to:edges[1])
		need[to.v]=!dfs(to.v);
	for(auto k:c){
		if(need[k.second]&&k.first<=d[0][k.second]){
			need[k.second]=0;
		} else {
			qaq.push_back(k.first);
		}
	}
	for(auto to:edges[1]){
		if(need[to.v]) qwq.push_back(d[0][to.v]);
	}
	if(qaq.size()<qwq.size()) return false;
	int i=0,j=0;
	sort(qwq.begin(),qwq.end());
	sort(qaq.begin(),qaq.end());
	while(i<qaq.size()&&j<qwq.size()){
		if(qaq[i]>=qwq[j]){
			++i;++j;
		} else {
			++i;
		}
	}
	if(j==qwq.size()) return true;
	return false;
}
int main(){
	#ifdef DEBUG
		freopen("a2.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		edges[u].push_back(Node(v,d));
		edges[v].push_back(Node(u,d));
	}
	prework(1,1);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&p[i]);
	ll l=0,r=1LL<<60;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}
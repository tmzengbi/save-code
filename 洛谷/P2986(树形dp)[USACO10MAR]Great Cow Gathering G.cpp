#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,c[maxn];
vector<pair<int,int> >edges[maxn];
int siz[maxn];
ll sum[maxn],ans[maxn],tot;
void dfs1(int u,int fa){
	siz[u]=c[u];
	for(auto e:edges[u]){
		if(fa==e.first) continue;
		dfs1(e.first,u);
		siz[u]+=siz[e.first];
		sum[u]+=sum[e.first]+1LL*siz[e.first]*e.second;
	}
}
void dfs2(int u,int fa){
	for(auto e:edges[u]){
		if(e.first==fa) continue;
		ans[e.first]=ans[u]-1LL*e.second*siz[e.first]+1LL*e.second*(tot-siz[e.first]);
		dfs2(e.first,u);
	}
}
ll solve(){
	dfs1(1,1);
	ans[1]=sum[1];
	dfs2(1,1);
	ll res=1LL<<60;
	for(int i=1;i<=n;++i){
		res=min(res,ans[i]);
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		tot+=c[i];
	}
	for(int i=1;i<n;++i){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		edges[u].push_back(make_pair(v,d));
		edges[v].push_back(make_pair(u,d));
	}
	printf("%lld\n",solve());
}
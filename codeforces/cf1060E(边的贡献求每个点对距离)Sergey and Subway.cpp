#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n,dep[maxn],siz[maxn],cnt[2];
ll ans=0;
vector<int>edges[maxn];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:edges[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	for(int v:edges[u]){
		if(v==fa) continue;
		ans+=1LL*siz[v]*(n-siz[v]);
	}
	++cnt[dep[u]&1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,1);
	ll add=0;
	for(int i=1;i<=n;++i) add+=cnt[(dep[i]&1)^1];
	printf("%lld\n",(ans+add/2)/2);
}
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<stack>
#include<map>
#include<cmath>
using namespace std;
const int maxn=1e3+10;
int r,c,n,g[maxn],ok[maxn],vis[maxn],viss[2][maxn];
vector<int>edges[maxn];
bool match(int u){
	for(int v:edges[u]){
		if(vis[v]) continue;
		vis[v]=1;
		if(!g[v]||match(g[v])){
			g[v]=u;ok[u]=v;
			return true;
		}
	}
	return false;
}
void dfs(int u,int opt){
	if(viss[opt][u]) return;
	viss[opt][u]=1;
	if(opt&&g[u]){
		dfs(g[u],0);
	} else {
		for(int v:edges[u])
			dfs(v,1);
	}
}
int main(){
	while(scanf("%d%d%d",&r,&c,&n)==3&&r){
		memset(ok,0,sizeof ok);
		memset(g,0,sizeof g);
		for(int i=0;i<=r;++i)
			edges[i].clear();
		for(int i=1;i<=n;++i){
			int u,v;scanf("%d%d",&u,&v);
			edges[u].push_back(v);
		}
		int ans=0;
		for(int i=1;i<=r;++i){
			memset(vis,0,sizeof vis);
			if(match(i)) ++ans;
		}
		printf("%d",ans);
		memset(viss,0,sizeof viss);
		for(int i=1;i<=r;++i)
			if(!ok[i]) dfs(i,0);
		for(int i=1;i<=r;++i)
			if(!viss[0][i]) printf(" r%d",i);
		for(int i=1;i<=c;++i)
			if(viss[1][i]) printf(" c%d",i);
		puts("");
	}
}
/*
4 4 3 1 1 1 4 3 2
4 4 2 1 1 2 2
0 0 0
*/
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
int n,m,k,g[maxn],vis[maxn];
vector<int>edges[maxn];
bool match(int u){
	for(int v:edges[u]){
		if(vis[v]) continue;
		vis[v]=1;
		if(g[v]==-1||match(g[v])){
			g[v]=u;
			return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d",&n)==1&&n){
		scanf("%d%d",&m,&k);
		memset(g,-1,sizeof g);
		for(int i=1;i<n;++i)
			edges[i].clear();
		for(int i=1;i<=k;i++){
			int useless,u,v;scanf("%d%d%d",&useless,&u,&v);
			if(u&&v) edges[u].push_back(v);
		}
		int ans=0;
		for(int i=1;i<n;++i){
			memset(vis,0,sizeof vis);
			if(match(i)) ++ans;
		}
		printf("%d\n",ans);
	}
}
/*
4 4 3 1 1 1 4 3 2
4 4 2 1 1 2 2
0 0 0
*/
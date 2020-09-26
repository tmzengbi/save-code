#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int maxn=2e2+10;
int t,n,mp[maxn][maxn],vis[maxn],g[maxn];
bool match(int u){
	for(int v=1;v<=n;++v){
		if(mp[u][v]&&!vis[v]){
			vis[v]=1;
			if(!g[v]||match(g[v])){
				g[v]=u;
				return true;
			}
		}
	}
	return false;
}
bool work(){
	memset(g,0,sizeof g);
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof vis);
		if(!match(i)) return false;
	}
	return true;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				scanf("%d",&mp[i][j]);
			}
		if(work()) puts("Yes");
		else puts("No");
	}
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int t,n,m;
int mp[maxn][maxn],vis[maxn],g[maxn];
bool match(int x){
	for(int i=1;i<=n;++i){
		if(mp[x][i]&&!vis[i]){
			vis[i]=1;
			if(!g[i]||match(g[i])){
				g[i]=x;return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(g,0,sizeof g);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mp[i][j]=0;
		for(int i=1;i<=m;++i){
			int u,v;scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					mp[i][j]=mp[i][j]||(mp[i][k]&&mp[k][j]);
		int res=n;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof vis);
			res-=match(i);
		}
		printf("%d\n",res);
	}
}
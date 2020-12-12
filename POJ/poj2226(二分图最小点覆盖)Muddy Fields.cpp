#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=55*55;
char mp[55][55];
int g[maxn],vis[maxn];
int col[55][55],row[55][55];
vector<vector<int> >edges;
int n,m,cnt,cntt;
bool match(int x){
	for(int i=0;i<edges[x].size();++i){
		int v=edges[x][i];
		if(vis[v]) continue;
		vis[v]=1;
		if(!g[v]||match(g[v])){
			g[v]=x;
			return true;
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		edges.clear();
		memset(g,0,sizeof g);
		for(int i=1;i<=n;++i)
			scanf("%s",mp[i]+1);
		cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mp[i][j]=='*') col[i][j]=(mp[i][j-1]=='*'?col[i][j-1]:++cnt);
		edges.resize(cnt+1);
		cntt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mp[i][j]=='*') row[i][j]=(mp[i-1][j]=='*'?row[i-1][j]:++cntt);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mp[i][j]=='*'){
					edges[col[i][j]].push_back(row[i][j]);
				}
		int res=0;
		for(int i=1;i<=cnt;++i){
			memset(vis,0,sizeof vis);
			res+=match(i);
		}
		printf("%d\n",res);
	}
}
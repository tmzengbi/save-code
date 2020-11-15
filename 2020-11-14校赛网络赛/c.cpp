#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int maxn=55;
int n,vis[maxn][maxn];
char mp[maxn][maxn];
queue<pii>q;
inline bool out(int x,int y){
	return x<0||y<0||x>n+1||y>n+1;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		while(!q.empty()) q.pop();
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;++i){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=n;++j){
				if(mp[i][j]=='#') {
					vis[i][j]=1;
				}
			}
		}
		q.push(make_pair(0,0));
		while(!q.empty()){
			auto x=q.front();q.pop();
			for(int i=0;i<4;++i){
				int nx=x.first+dx[i],ny=x.second+dy[i];
				if(out(nx,ny)) continue;
				if(!vis[nx][ny]){
					vis[nx][ny]=1;
					q.push(make_pair(nx,ny));
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(mp[i][j]=='O'&&!vis[i][j]) ++ans;
		printf("%d\n",ans);
	}
	
}
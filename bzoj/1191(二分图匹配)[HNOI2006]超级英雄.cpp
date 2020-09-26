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
const int maxn=1e3+10;
int g[maxn],n,m,vis[maxn],s[maxn];
vector<int>edges[maxn];
bool match(int u){
	for(int v:edges[u]){
		if(vis[v]) continue;
		vis[v]=1;
		if(g[v]==-1||match(g[v])){
			g[v]=u;s[u]=v;
			return true;
		}
	}
	return false;
}
int main(){
	memset(g,-1,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;scanf("%d%d",&a,&b);
		edges[i].push_back(a);
		edges[i].push_back(b);
	}
	int ans=0;
	for(int i=0;i<m;++i){
		memset(vis,0,sizeof vis);
		if(!match(i)){
			break;
		}
		++ans;
	}
	printf("%d\n",ans);
	for(int i=0;i<ans;++i){
		printf("%d\n",s[i]);
	}
}
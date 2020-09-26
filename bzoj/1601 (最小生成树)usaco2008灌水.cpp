#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e2+10;
int n,mp[maxn][maxn],w[maxn],start=1;
struct Node{
	int v,d;
	Node(int v,int d):v(v),d(d){};
	bool operator<(const Node&rhs)const{
		return d>rhs.d;
	}
};
bool vis[maxn];
priority_queue<Node>q;
void solve(){
	ll ans=0;
	q.push(Node(start,w[start]));
	int cnt=0;
	while(cnt<n){
		auto now=q.top();q.pop();
		int u=now.v;
		if(vis[u]) continue;
		vis[u]=1;
		++cnt;
		ans+=now.d;
		for(int v=1;v<=n;++v){
			if(!vis[v]){
				q.push(Node(v,min(mp[u][v],w[v])));
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	#ifdef DEBUG
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&w[i]);
		if(w[i]<w[start]) start=i;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;+ +j)
			scanf("%d",&mp[i][j]);
	solve();
}
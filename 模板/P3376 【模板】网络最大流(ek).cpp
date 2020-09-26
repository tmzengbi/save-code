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
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int maxn=210;
ll ans=0;
struct Flow{
	int u,v,cap,now;
	Flow(int u,int v,int cap,int now):
		u(u),v(v),cap(cap),now(now){}
};
vector<Flow>G;
vector<int>edges[maxn];
int from,to,n,m,vis[maxn],pre[maxn];
const int inf=0x7fffffff;
queue<int>q;
bool bfs(){
	while(!q.empty()) q.pop();
	q.push(from);
	vis[from]=inf;
	while(!q.empty()){
		auto u=q.front();q.pop();
		for(int v:edges[u]){
			auto &e=G[v];
			if(!vis[e.v]&&e.cap-e.now>0){
				vis[e.v]=min(vis[u],e.cap-e.now);
				pre[e.v]=v;
				q.push(e.v);
			}
		}
		if(vis[to]) return true;
	}
	return vis[to];
}
void ek(){
	while(bfs()){
		int f=vis[to],tmp=to;
		ans+=f;
		while(true){
			auto &now=G[pre[tmp]],&rnow=G[pre[tmp]^1];
			now.now+=f;rnow.now-=f;
			if(now.u==from) break;
			tmp=now.u;
		}
		memset(vis,0,sizeof vis);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&from,&to);
	for(int i=1;i<=m;++i){
		int u,v,f;
		scanf("%d%d%d",&u,&v,&f);
		G.push_back(Flow(u,v,f,0));
		edges[u].push_back(G.size()-1);
		G.push_back(Flow(v,u,f,f));
		edges[v].push_back(G.size()-1);
	}
	ek();
	printf("%lld\n",ans);
}
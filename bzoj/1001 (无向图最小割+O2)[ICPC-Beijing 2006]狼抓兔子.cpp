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
const int maxn=1e3+5;
class Max_flow{
	private:
	struct Flow{
		int u,v,cap,now;
		Flow(int u,int v,int cap,int now):
			u(u),v(v),cap(cap),now(now){}
	};
	const int inf=0x7fffffff;
	vector<Flow>G;
	vector<int>edges[maxn*maxn];
	int from,to,dep[maxn*maxn],cur[maxn*maxn];
	queue<int>q;
	bool bfs(){
		memset(dep,0,sizeof dep);
		q.push(from);
		dep[from]=1;
		while(!q.empty()){
			auto u=q.front();q.pop();
			for(int v:edges[u]){
				auto &e=G[v];
				if(!dep[e.v]&&e.cap-e.now>0){
					dep[e.v]=dep[u]+1;
					q.push(e.v);
				}
			}
		}
		return dep[to];
	}
	int dfs(int u,int a){
		ll sum=0;
		if(u==to||a==0) return a;
		for(int &i=cur[u];i<edges[u].size();++i){
			auto &e=G[edges[u][i]];
			int f;
			if(dep[e.v]==dep[u]+1&&(f=dfs(e.v,min(a,e.cap-e.now)))>0){
				auto &re=G[edges[u][i]^1];
				e.now+=f;re.now-=f;
				a-=f;sum+=f;
				if(a==0) break;
			}
		}
		return sum;
	}
	public:
	void set(int from,int to){
		this->from=from;
		this->to=to;
	}
	void addedge(int u,int v,int f){
		G.push_back(Flow(u,v,f,0));
		edges[u].push_back(G.size()-1);
		G.push_back(Flow(v,u,f,0));
		edges[v].push_back(G.size()-1);
	}
	ll dinic(){
		ll sum=0;
		while(bfs()){
			memset(cur,0,sizeof cur);
			sum+=dfs(from,inf);
		}
		return sum;
	}
	void print(){
		queue<int>q;
		bool vis[maxn]={0};
		q.push(1);
		vis[1]=1;
		while(!q.empty()){
			auto u=q.front();q.pop();
			for(auto to:edges[u]){
				auto &now=G[to];
				if(!vis[now.v]&&now.now<now.cap){
					q.push(now.v);
					vis[now.v]=1;
				}
			}
		}
		for(int i=1;i<=to;++i)
			if(vis[i]) printf("%d ",i);
		puts("");
	}
}flow;
int from,to,n,m;
int mp[maxn][maxn];
void init(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			mp[i][j]=j+(i-1)*m;
}
int main(){
	#ifdef DEBUG
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	flow.set(1,n*m);
	init();
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j){
			int d;scanf("%d",&d);
			flow.addedge(mp[i][j],mp[i][j]+1,d);
		}
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j){
			int d;scanf("%d",&d);
			flow.addedge(mp[i][j],mp[i+1][j],d);
		}
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j){
			int d;scanf("%d",&d);
			flow.addedge(mp[i][j],mp[i+1][j+1],d);
		}
	printf("%lld\n",flow.dinic());
//	flow.print();
}
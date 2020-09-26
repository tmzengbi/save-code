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
class Max_flow{
	private:
	struct Flow{
		int u,v,cap,now;
		Flow(int u,int v,int cap,int now):
			u(u),v(v),cap(cap),now(now){}
	};
	const int inf=0x7fffffff;
	vector<Flow>G;
	vector<int>edges[maxn];
	int from,to,dep[maxn],cur[maxn];
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
		G.push_back(Flow(v,u,f,f));
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
}flow;
int from,to,n,m;
int main(){
	scanf("%d%d%d%d",&n,&m,&from,&to);
	flow.set(from,to);
	for(int i=1;i<=m;++i){
		int u,v,f;
		scanf("%d%d%d",&u,&v,&f);
		flow.addedge(u,v,f);
	}
	printf("%lld\n",flow.dinic());
}
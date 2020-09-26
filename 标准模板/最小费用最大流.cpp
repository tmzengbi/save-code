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
const int maxn=5050;
class MCMF{
	const int inf=0x3f3f3f3f;
	private:
	struct Flow{
		int u,v,cap,now,cost;
		Flow(int u,int v,int cap,int now,int cost)
			:u(u),v(v),cap(cap),now(now),cost(cost){}
	};
	vector<Flow>G;
	vector<int>edges[maxn];
	int from,to,n;
	queue<int>q;
	int c[maxn],pre[maxn],inq[maxn],a[maxn];
	bool spfa(){
		while(!q.empty())q.pop();
		for(int i=1;i<=n;++i) c[i]=inf;
		q.push(from);
		inq[from]=1;
		c[from]=0;
		a[from]=inf;
		while(!q.empty()){
			auto u=q.front();q.pop();
			inq[u]=0;
			for(int v:edges[u]){
				auto &e=G[v];
				if(e.cap>e.now&&c[e.v]>c[u]+e.cost){
					c[e.v]=c[u]+e.cost;
					a[e.v]=min(a[u],e.cap-e.now);
					pre[e.v]=v;
					if(!inq[e.v]){
						q.push(e.v);
						inq[e.v]=1;
					}
				}
			}
		}
		if(c[to]==inf) return false;
		int tmp=to;
		Max_flow+=a[to];
		Max_cost+=1LL*c[to]*a[to];
		while(true){
			auto &e=G[pre[tmp]],&re=G[pre[tmp]^1];
			e.now+=a[to];re.now-=a[to];
			if(e.u==from) break;
			tmp=e.u;
		}
		return true;
	}
	public:
	ll Max_flow,Max_cost;
	void init(){
		G.clear();
		for(int i=1;i<=n;++i)
			edges[i].clear();
	}
	void set(int from,int to,int n){
		this->from=from;
		this->to=to;
		this->n=n;
	}
	void addedge(int u,int v,int cap,int cost){
		G.push_back(Flow(u,v,cap,0,cost));
		edges[u].push_back(G.size()-1);
		G.push_back(Flow(v,u,cap,cap,-cost));
		edges[v].push_back(G.size()-1);
	}
	void flow(){
		Max_flow=0;Max_cost=0;
		while(spfa());
	}
}ff;
int n,m,from,to;
int main(){
	scanf("%d%d%d%d",&n,&m,&from,&to);
	ff.set(from,to,n);
	for(int i=1;i<=m;++i){
		int u,v,cap,cost;
		scanf("%d%d%d%d",&u,&v,&cap,&cost);
		ff.addedge(u,v,cap,cost);
	}
	ff.flow();
	printf("%lld %lld\n",ff.Max_flow,ff.Max_cost);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e4+10;
int T,n,m,t[210][55];
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
		for(int i=0;i<=n;++i) c[i]=inf;
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
		Min_cost+=1LL*c[to]*a[to];
		int x=G[pre[to]].u;
		if(cnt[x]<::m) {
			int j=x-m-(cnt[x]-1)*::n;
			addedge(x+::n,n,1,0);
			cnt[x+::n]=cnt[x]+1;
			for(int i=1;i<=::m;++i)
				addedge(i,x+::n,1,cnt[x+::n]*t[i][j]);
		}
		while(true){
			auto &e=G[pre[tmp]],&re=G[pre[tmp]^1];
			e.now+=a[to];re.now-=a[to];
			if(e.u==from) break;
			tmp=e.u;
		}
		return true;
	}
	int cnt[maxn];
	void expand(int i){
		for(int j=1;j<=::n;++j){
			addedge(::m+(i-1)*::n+j,::m+::m*::n+1,1,0);
			for(int k=1;k<=::m;++k)
				addedge(k,::m+(i-1)*::n+j,1,i*t[k][j]);
		}
	}
	public:
	ll Max_flow,Min_cost;
	void init(){
		for(int i=0;i<=n;++i)
			cnt[i]=1;
		G.clear();
		for(int i=0;i<=n;++i)
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
		expand(1);
		Max_flow=0;Min_cost=0;
		while(spfa());
	}
}ff;
int main() {
	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ff.set(0,m+m*n+1,m+m*n+1);
		ff.init();
		for(int i=1;i<=m;++i)
			ff.addedge(0,i,1,0);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&t[i][j]);
		ff.flow();
		printf("%lld\n",ff.Min_cost);
	}
}
/*
1
5 7
1 2 3 4 5
2 1 3 4 5
2 3 1 4 5
2 3 4 1 5
2 3 4 5 1
2 2 2 2 2
2 2 2 2 2
*/
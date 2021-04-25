#include <bits/stdc++.h>
using namespace std;
const int maxn=2e2+10;
typedef long long ll;
int n,m;
int mp[maxn][maxn],r[maxn][maxn];
int cnt;
const int fx[8]={-2,-2,-1,-1,1,1,2,2},fy[8]={1,-1,2,-2,2,-2,1,-1};
bool check(int x,int y){
	return x<=n&&y<=n&&x>=1&&y>=1;
}
class Max_flow{
    typedef long long ll;
    const static int maxn=4e4+10;
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
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		mp[a][b]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(mp[i][j]) continue;
			r[i][j]=++cnt;
		}
    flow.set(0,cnt+1);
    const int inf=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) {
            if(!r[i][j]) continue;
            if((i+j)&1) {
                flow.addedge(0,r[i][j],1);
                for(int k=0;k<8;++k){
					int x=i+fx[k],y=j+fy[k];
					if(!check(x,y)||!r[x][y]) continue;
					flow.addedge(r[i][j],r[x][y],1);
				}
            } else {
                flow.addedge(r[i][j],cnt+1,1);
            }
        }
	ll res=flow.dinic();
	printf("%lld\n",cnt-res);
}
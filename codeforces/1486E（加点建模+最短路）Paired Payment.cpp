#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m;
struct Edge{
	int v,d;
	Edge(int v,int d):v(v),d(d){}
};
vector<Edge>edges[maxn];
void addedge(int u,int v,int d){
	edges[u].push_back(Edge(v,d));
}
struct Node{
	int u,v,d;
}p[maxn];
int mp[100010][51];
struct XX{
	int u,d;
	XX(int u,int d):u(u),d(d){}
	bool operator < (const XX &rhs) const {
		return d>rhs.d;
	}
};
priority_queue<XX>q;
int vis[maxn],d[maxn];
const int inf=0x3f3f3f3f;
void dijkstra(int n) {
	for(int i=1;i<=n;++i) d[i]=inf;
	d[1]=0;
	q.push(XX(1,0));
	while(!q.empty()) {
		auto x=q.top();q.pop();
		if(vis[x.u]) continue;
		vis[x.u]=1;
		for(auto e:edges[x.u]) {
			if(d[e.v]>d[x.u]+e.d) {
				d[e.v]=d[x.u]+e.d;
				q.push(XX(e.v,d[e.v]));
			}
		}
	}
}
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	int cnt=n;	
	for(int i=1;i<=m;++i) {
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		p[i]=(Node){u,v,d};
		if(!mp[v][d]) mp[v][d]=++cnt;
		if(!mp[u][d]) mp[u][d]=++cnt;
		addedge(v,mp[u][d],0);
		addedge(u,mp[v][d],0);
	}
	for(int i=1;i<=m;++i) {
		int u=p[i].u,v=p[i].v,d=p[i].d;
		for(int j=1;j<=50;++j) {
			int xx=j+d;
			xx*=xx;
			if(!mp[u][j]) continue;
			addedge(mp[u][j],v,xx);
		}
		for(int j=1;j<=50;++j) {
			int xx=j+d;
			xx*=xx;
			if(!mp[v][j]) continue;
			addedge(mp[v][j],u,xx);
		}
	}
	dijkstra(cnt);
	for(int i=1;i<=n;++i) {
		if(d[i]==inf) d[i]=-1;
		printf("%d ",d[i]);
	}
}
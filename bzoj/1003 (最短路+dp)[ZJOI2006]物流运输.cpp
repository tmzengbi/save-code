#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<random>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
const ll inf=1LL<<60;
int n,m,k,e;
struct Node{
	int v,d;
	Node(int v,int d):v(v),d(d){}
};
vector<Node>G;
vector<int>edges[21];
vector<int>invalid[maxn];
ll f[maxn],d[21];
int inq[21],vis[21];
queue<int>q;
ll spfa(){
	for(int i=2;i<=m;++i)
		d[i]=1LL<<60;
	while(!q.empty())q.pop();
	q.push(1);
	inq[1]=1;d[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int to:edges[u]){
			Node &e=G[to];
			if(!vis[e.v]&&d[e.v]>d[u]+e.d){
				d[e.v]=d[u]+e.d;
				if(!inq[e.v]){
					q.push(e.v);
					inq[e.v]=1;
				}
			}
		}
	}
	return d[m];
}
ll cost[maxn][maxn];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&e);
	for(int i=1;i<=e;++i){
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		G.push_back(Node(v,d));
		edges[u].push_back(G.size()-1);
		G.push_back(Node(u,d));
		edges[v].push_back(G.size()-1);
	}
	int t;scanf("%d",&t);
	for(int i=1;i<=t;++i){
		int p,a,b;scanf("%d%d%d",&p,&a,&b);
		for(int j=a;j<=b;++j)
			invalid[j].push_back(p);
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			memset(vis,0,sizeof vis);
			for(int k=i;k<=j;++k){
				for(int s:invalid[k])
					vis[s]=1;
			}
			cost[i][j]=spfa();
		}
	f[0]=-k;
	for(int i=1;i<=n;++i){
		f[i]=1LL<<60;
		for(int j=1;j<=i;++j){
			if(cost[j][i]>=inf) continue;
			f[i]=min(f[i],f[j-1]+(i-j+1LL)*cost[j][i]+k);
		}
	}
	printf("%lld\n",f[n]);
}
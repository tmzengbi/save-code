#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int P=1e9+7;
int cnt,rt1,rt2;
struct rt
{
	int o,ch[2];
}tr[maxn<<3];
struct Edge
{
	int u,v,d;
	Edge(int u,int v,int d):u(u),v(v),d(d){}
};
vector<Edge>G;
vector<int>edges[maxn<<3];
void buildin(int &o,int l,int r)
{
	if(l==r){o=l;return;}
	o=++cnt;
	int mid=(l+r)>>1;
	buildin(tr[o].ch[0],l,mid);
	buildin(tr[o].ch[1],mid+1,r);
	G.push_back(Edge(o,tr[o].ch[0],0));
	edges[o].push_back(G.size()-1);
	G.push_back(Edge(o,tr[o].ch[1],0));
	edges[o].push_back(G.size()-1);
}
void buildout(int &o,int l,int r)
{
	if(l==r){o=l;return;}
	o=++cnt;
	int mid=(l+r)>>1;
	buildout(tr[o].ch[0],l,mid);
	buildout(tr[o].ch[1],mid+1,r);
	G.push_back(Edge(tr[o].ch[0],o,0));
	edges[tr[o].ch[0]].push_back(G.size()-1);
	G.push_back(Edge(tr[o].ch[1],o,0));
	edges[tr[o].ch[1]].push_back(G.size()-1);
}
void update(int o,int l,int r,int ql,int qr,int v,int f,int opt)
{
	if(ql<=l&&r<=qr)
	{
		if(opt==2)
		{
			G.push_back(Edge(f,o,v));
			edges[f].push_back(G.size()-1);
		}
		else
		{
			G.push_back(Edge(o,f,v));
			edges[o].push_back(G.size()-1);
		}
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(tr[o].ch[0],l,mid,ql,qr,v,f,opt);
	if(mid<qr) update(tr[o].ch[1],mid+1,r,ql,qr,v,f,opt);
}
int n,m,s;
const ll inf=2e18L;
ll dist[maxn<<3];
bool vis[maxn<<3];
struct Node
{
	int u;ll dist;
	Node(int u,ll dist):u(u),dist(dist){}
	bool operator<(const Node&rhs)const
	{
		return dist>rhs.dist;
	}
};
priority_queue<Node>q;
void dij()
{
	for(int i=1;i<=n*3;i++) dist[i]=inf;
	dist[s]=0;
	q.push(Node(s,0));
	while(!q.empty())
	{
		auto now=q.top();q.pop();
		int u=now.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ee:edges[u])
		{
			auto e=G[ee];
			if(dist[u]+e.d<dist[e.v])
			{
				dist[e.v]=dist[u]+e.d;
				q.push(Node(e.v,dist[e.v]));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);cnt=n;
	buildin(rt1,1,n);buildout(rt2,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,u,l,r,d;scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d",&u,&l,&d);
			G.push_back(Edge(u,l,d));
			edges[u].push_back(G.size()-1);
		}
		else
		{
			scanf("%d%d%d%d",&u,&l,&r,&d);
			if(opt==2) update(rt1,1,n,l,r,d,u,opt);
			else update(rt2,1,n,l,r,d,u,opt);
		}
	}
	dij();
	for(int i=1;i<=n;i++)
		printf("%lld ",(dist[i]==inf)?-1:dist[i]);
}
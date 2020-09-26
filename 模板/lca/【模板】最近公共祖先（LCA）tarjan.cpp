#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500010;
struct Pair
{
	int u,v,id;
	bool vis;
}Q[maxn];
int N,M,S,pre[maxn],ans[maxn];
bool vis[maxn];
vector<int>edges[maxn];
vector<Pair>G;
vector<int>q[maxn];

int findroot(int root)
{
	return root==pre[root]?root:(pre[root]=findroot(pre[root]));
}
void merge(int r1,int r2)
{
	r1=findroot(r1);r2=findroot(r2);
	if(r1!=r2) pre[r1]=r2;
}
void lca(int u,int fa)
{
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		lca(v,u);
		merge(v,u);
		vis[v]=true;
	}
	for(int i=0;i<q[u].size();i++)
	{
		Pair P=G[q[u][i]];
		int v=P.v;if(v==u) v=P.u;
		if(vis[v]&&!P.vis)
		{
			G[q[u][i]].vis=true; 
			ans[P.id]=findroot(v);
		}
	}
}
int main()
{
	scanf("%d%d%d",&N,&M,&S);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d",&Q[i].u,&Q[i].v);Q[i].id=i;Q[i].vis=false;
		G.push_back(Q[i]);
		int u=Q[i].u,v=Q[i].v;
		q[u].push_back(i-1);
		q[v].push_back(i-1);
	}
	for(int i=1;i<=N;i++) pre[i]=i;
	lca(S,S);
	for(int i=1;i<=M;i++)
		printf("%d\n",ans[i]);

	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int N,d[10010],k[10010],ans,kk=2e8;
bool vis[10010];
vector<int> G[10010];
void dfs(int u,int fa)
{
	d[u]=1;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)	continue;
		dfs(v,u);
		d[u]+=d[v];
		k[u]=max(d[v],k[u]);
	}
	k[u]=max(k[u],N-d[u]);
	if(kk>k[u]){kk=k[u];ans=u;}
}
int main()
{
	memset(vis,0,sizeof vis);
	memset(d,0,sizeof d);
	memset(k,0,sizeof k);
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=N;i++)
		printf("%d ",d[i]);
	cout<<endl;
	for(int i=1;i<=N;i++)
		printf("%d ",k[i]);
	cout<<endl;
	printf("%d\n",ans);
	while(1);
}

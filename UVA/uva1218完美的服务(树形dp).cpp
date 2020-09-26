#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10010;
int N,dp[maxn][3];
vector<int>edges[maxn];
int dfs(int u,int fa,int mod)
{
	if(dp[u][mod]!=-1) return dp[u][mod];
	int sum[3]={1,0,0};sum[2]=1e5;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		sum[0]+=min(dfs(v,u,1),dfs(v,u,0));
		sum[1]+=dfs(v,u,2);
	}
	dp[u][0]=sum[0];dp[u][1]=sum[1];
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		sum[2]=min(sum[1]-dfs(v,u,2)+dfs(v,u,0),sum[2]);
	}
//	if(sum[2]==1e8) sum[2]=0;
	dp[u][2]=sum[2];
	return dp[u][mod];
}
int main()
{
	while(scanf("%d",&N)==1)
	{
		if(N==-1) break;
		if(N==0) continue;
		for(int i=1;i<=N;i++) edges[i].clear();
		memset(dp,-1,sizeof dp);
		for(int i=1;i<N;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int ans=min(dfs(1,1,0),dfs(1,1,2));
//		printf("%d %d\n",dfs(1,1,0),dfs(1,1,2));
		printf("%d\n",ans);
	}
}
/*
6 1 3 2 3 3 4 4 5 4 6 0 2 1 2
*/
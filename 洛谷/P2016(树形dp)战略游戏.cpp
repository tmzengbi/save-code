#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1510;
int dp[maxn][2];
vector<int>edges[maxn];
int dfs(int u,int m,int fa)
{
	if(dp[u][m]!=-1) return dp[u][m];
	dp[u][0]=0;dp[u][1]=1;
	for(auto v:edges[u])
	{
		if(v==fa) continue;
		dp[u][0]+=dfs(v,1,u);
		dp[u][1]+=min(dfs(v,1,u),dfs(v,0,u));
	}
	return dp[u][m];
}
int n;
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	memset(dp,-1,sizeof dp);
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,siz;scanf("%d%d",&u,&siz);
		for(int j=1;j<=siz;j++)
		{
			int v;scanf("%d",&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
	}
	printf("%d\n",min(dfs(0,0,0),dfs(0,1,0)));
//	for(int i=0;i<n;i++)
//		printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
//	system("pause");
}
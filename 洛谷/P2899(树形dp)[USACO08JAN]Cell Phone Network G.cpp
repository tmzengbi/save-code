#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10010;
const int inf=maxn;
int dp[maxn][3];
vector<int>edges[maxn];
int dfs(int u,int m,int fa)
{
	if(dp[u][m]!=-1) return dp[u][m];
	int s1=0,s2=inf,s3=0,sum=0;
	for(auto v:edges[u])
	{
		if(v==fa) continue;
		s1+=min(dfs(v,0,u),min(dfs(v,1,u),dfs(v,2,u)));
		s3+=dfs(v,1,u);
		sum+=min(dfs(v,0,u),dfs(v,1,u));
	}
	for(auto v:edges[u])
	{
		if(v==fa) continue;
		s2=min(s2,sum-min(dfs(v,0,u),dfs(v,1,u))+dfs(v,0,u));
	}
	dp[u][0]=s1+1;dp[u][1]=s2;dp[u][2]=s3;
	return dp[u][m];
}
int n;
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	memset(dp,-1,sizeof dp);
    scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	printf("%d\n",min(dfs(1,0,1),dfs(1,1,1)));
//	for(int i=1;i<=n;i++)
//		for(int j=0;j<3;j++)
//			printf("%d %d %d\n",i,j,dp[i][j]);
//	system("pause");
}
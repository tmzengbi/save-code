#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1010;
int N,dp[1010][2];
vector<int>edges[maxn];
int dfs(int u,int fa,int choose)
{
	if(dp[u][choose]!=-1) return dp[u][choose];
	int son=0,sum[2]={0};
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		son++;
		sum[0]+=max(dfs(v,u,0),dfs(v,u,1));
		sum[1]+=dfs(v,u,0);
	}
	if(son==0) return choose;
	dp[u][0]=sum[0];
	dp[u][1]=sum[1]+1;
	return dp[u][choose];
}
int main()
{
	scanf("%d",&N);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans=max(dfs(1,1,0),dfs(1,1,1));
	printf("%d\n",ans);
//	system("pause");
}
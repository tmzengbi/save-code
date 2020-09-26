#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=6010;
int N,dp[maxn][2],a[maxn];
vector<int>edges[maxn];
bool vis[maxn];
int dfs(int u,int fa,int choose)
{
	vis[u]=true;
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
	if(son==0) return choose?a[u]:0;
	dp[u][0]=sum[0];
	dp[u][1]=sum[1]+a[u];
	return dp[u][choose];
}
int main()
{
	scanf("%d",&N);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(u==v)break;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(!vis[i]) ans+=max(dfs(i,i,0),dfs(i,i,1));
	}
	printf("%d\n",ans);
//	system("pause");
}
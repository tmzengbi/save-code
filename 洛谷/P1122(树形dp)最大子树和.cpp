#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=16010;
const int _inf=-0x7fffffff;
vector<int>edges[maxn];
int dp[maxn],a[maxn],n,ans=_inf;
int dfs(int u,int fa)
{
	if(dp[u]!=_inf) return dp[u];
	int sum=a[u];
	for(int v:edges[u])
	{
		if(v==fa) continue;
		sum+=max(0,dfs(v,u));
	}
	ans=max(ans,sum);
	return dp[u]=sum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) dp[i]=_inf;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,1);
	printf("%d\n",ans);
//	system("pause");
}
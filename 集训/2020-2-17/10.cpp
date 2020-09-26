#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,dp[maxn],pre[maxn],maxx,maxx2,mk;
vector<int>edges[maxn];
bool col[maxn];
void dfs(int s,int fa,int dep,int &pos)
{
	pre[s]=fa;
	if(maxx<dep){maxx=dep;pos=s;}
	for(int i=0;i<edges[s].size();i++)
	{
		int v=edges[s][i];
		if(v==fa) continue;
		dfs(v,s,dep+1,pos);
	}
}
void dfs2(int u,int fa)
{
	if(col[u]) dp[u]=0;
	else dp[u]=dp[fa]+1;
	if(maxx2<dp[u]){maxx2=dp[u];mk=u;}
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans1,ans2,ans3;
	maxx=0;
	dfs(1,1,0,ans1);
	maxx=0;
	dfs(ans1,ans1,0,ans2);
	int tmp=ans2;
	while(pre[tmp]!=tmp)
	{
		col[tmp]=1;
		tmp=pre[tmp];
	}
	col[tmp]=1;
//	for(int i=1;i<=n;i++)
//		printf("%d %d\n",i,col[i]);
	maxx2=-1;
	dfs2(ans1,ans2);
	if(maxx2==0)
		for(int i=1;i<=n;i++) if(i!=ans1&&i!=ans2){mk=i;break;}
	printf("%d\n",maxx+maxx2);
	printf("%d %d %d\n",ans1,ans2,mk);
//	system("pause");
}
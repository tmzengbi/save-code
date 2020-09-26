#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=210;
int N,cnt=0,dp[maxn][2];
bool t[maxn][2];
map<string,int>M;
vector<int>edges[maxn];
int dfs(int u,int fa,int m)
{
	if(dp[u][m]>-1)return dp[u][m];
	int ans0=0,ans1=0;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		ans1+=dfs(v,u,0);
		ans0+=max(dfs(v,u,0),dfs(v,u,1));
		t[u][1]=t[u][1]||t[v][0];
		t[u][0]=t[u][0]||(dfs(v,u,0)>dfs(v,u,1)?t[v][0]:t[v][1]);
		if(dfs(v,u,0)==dfs(v,u,1)) t[u][0]=1;
	}
	dp[u][0]=ans0;dp[u][1]=ans1+1;
	return dp[u][m];
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>N&&N)
	{
		string s;cin>>s;
		M.clear();
		M[s]=0;
		for(int i=0;i<=cnt;i++) edges[i].clear();
		memset(dp,-1,sizeof dp);
		memset(t,0,sizeof t);
		cnt=0;
		for(int i=1;i<N;i++)
		{
			string s1,s2;cin>>s1>>s2;
			if(M.find(s1)==M.end()) M[s1]=++cnt;
			if(M.find(s2)==M.end()) M[s2]=++cnt;
			int u=M[s1],v=M[s2];
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int ans=0,a0=dfs(0,0,0),a1=dfs(0,0,1);
		bool db=false;
		if(a0<=a1)
		{
			ans=a1;
			db=t[0][1];
			if(a0==a1)db=true;
		}
		else
		{
			ans=a0;
			db=t[0][0];
		}
		printf("%d ",ans);
		if(db) printf("No\n");
		else printf("Yes\n");
	}
//	system("pause");
}
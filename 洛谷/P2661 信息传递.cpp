#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=200010;
int N,a[maxn],step[maxn],vis[maxn],t[maxn],ans=2e9;
void dfs(int u,int dep,int &tmp)
{
	int v=a[u];
	if(t[v]==1){t[u]=1;return;}
	step[u]=dep;
	vis[u]=true;
	if(!vis[v])
		dfs(v,dep+1,tmp);
	else if(vis[v])
		tmp=min(dep-step[v]+1,tmp);
	t[u]=1;
}
int main()
{
	memset(t,0,sizeof t);
	memset(vis,0,sizeof vis);
	memset(step,0,sizeof step);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N;i++)
	{
		int tmp=2e9;
		if(!vis[i])
			dfs(i,1,tmp);
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
//	while(1);
}
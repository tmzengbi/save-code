#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,dfn[5010],low[5010],s[5010],cnt=0,Index=0,ct=0,Max=0;
bool vis[5010];
vector<int> edges[5010];
vector<int> ans[5010];
void tarjan(int now)
{
	low[now]=dfn[now]=++cnt;
	s[++Index]=now;
	vis[now]=true;
	int len=edges[now].size();
	for(int i=0;i<len;i++)
	{
		int v=edges[now][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[now]=min(low[now],low[v]);
		}
		else if(vis[v])
			low[now]=min(low[now],dfn[v]);
	}
	int cur;
	if(dfn[now]==low[now])
	{
		ct++;
		do
		{
			cur=s[Index--];
			vis[cur]=false;
//			printf("%d ",cur);
			ans[ct].push_back(cur);
		}while(cur!=now);
		int c=ans[ct].size();
		Max=max(Max,c);
	}
}
int main()
{
	memset(vis,false,sizeof vis);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v,m;
		scanf("%d%d%d",&u,&v,&m);
		edges[u].push_back(v);
		if(m==2) edges[v].push_back(u);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	printf("%d\n",Max);
	for(int i=ct;i>=1;i--)
	{
		int c=ans[i].size();
		if(c==Max)
		{
			sort(ans[i].begin(),ans[i].end());
			for(int j=0;j<c;j++)
				printf("%d ",ans[i][j]);
		}
	}
}
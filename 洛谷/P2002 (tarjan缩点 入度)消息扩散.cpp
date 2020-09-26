#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100010;
int dfn[maxn],low[maxn],cnt=0,_cnt=0,Index=0,s[maxn],belong[maxn];
int in[maxn],out[maxn];
bool vis[maxn];
vector<int> edges[maxn];
int N,M;
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
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
	if(low[now]==dfn[now])
	{
		int cur;
		_cnt++;
		do
		{
			cur=s[Index--];
			vis[cur]=false;
			belong[cur]=_cnt;
		}while(now!=cur);
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=N;i++)
	{
		int len=edges[i].size();
		for(int j=0;j<len;j++)
		{
			int v=edges[i][j];
			if(belong[i]!=belong[v]) in[belong[v]]++;
		}
	}
	int ans=0;
	for(int i=1;i<=_cnt;i++)
		if(in[i]==0) ans++;
	printf("%d\n",ans);
}
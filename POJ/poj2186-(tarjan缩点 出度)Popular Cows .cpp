#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int dfn[50010],low[50010],ans=0,N,M,cnt=0,s[50010],num[50010],Index=0;
int _cnt=0,belong[50010];
bool vis[50010];
vector<int> edges[50010];
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	s[++Index]=now;
	vis[now]=true;
	int len=edges[now].size();
	for(int i=0;i<len;i++)
	{
		int to=edges[now][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[now]=min(low[to],low[now]);
		}
		else if(vis[now])
			low[now]=min(low[now],dfn[to]);
	}
	if(dfn[now]==low[now])
	{
		_cnt++;
		int cur;
		do
		{
			cur=s[Index--];
			vis[Index]=false;
			belong[cur]=_cnt;
			num[_cnt]++;
		}while(cur!=now);
	}
}
int main()
{
	memset(vis,false,sizeof vis);
	memset(dfn,0,sizeof dfn);
	memset(num,0,sizeof num);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	int out[50010];memset(out,0,sizeof out);
	for(int u=1;u<=N;u++)
	{
		int len=edges[u].size();
		for(int j=0;j<len;j++)
		{
			int v=edges[u][j];
			if(belong[u]!=belong[v]) out[belong[u]]++;
		}
	}
	int sum=0,mk;
	for(int i=1;i<=_cnt;i++)
		if(out[i]==0) {sum++;mk=i;}
	if(sum!=1) printf("0\n");
	else printf("%d\n",num[mk]);
}
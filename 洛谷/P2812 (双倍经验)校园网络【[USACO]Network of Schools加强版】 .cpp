#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dfn[1000010],low[1000010],cnt=0,_cnt=0,Index=0,N,s[1000010],belong[1000010];
bool vis[1000010];
vector<int> edges[1000010];
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	s[++Index]=now;vis[now]=true;
	int len=edges[now].size();
	for(int i=0;i<len;i++)
	{
		int v=edges[now][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[now]=min(low[v],low[now]);
		}
		else if(vis[v])
			low[now]=min(low[now],dfn[v]);
	}
	if(low[now]==dfn[now])
	{
		++_cnt;
		int cur;
		do
		{
			cur=s[Index--];
			vis[cur]=false;
			belong[cur]=_cnt;
		}while(cur!=now);
	}
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		while(true)
		{
			int v;scanf("%d",&v);
			if(v==0) break;
			edges[i].push_back(v);
		}
	}
	for(int i=1;i<=N;i++)
		if(!dfn[i]) tarjan(i);
	if(_cnt==1) {printf("1\n0\n");return 0;}
	int in[1000010],out[1000010];
	memset(in,0,sizeof in);
	memset(out,0,sizeof out);
	for(int i=1;i<=N;i++)
	{
		int len=edges[i].size();
		for(int j=0;j<len;j++)
		{
			int v=edges[i][j];
			if(belong[i]!=belong[v]){in[belong[v]]++;out[belong[i]]++;}
		}
	}
	int ans=0;
	for(int i=1;i<=_cnt;i++)
		if(in[i]==0) ans++;
	printf("%d\n",ans);
	int ans2=0;
	for(int i=1;i<=_cnt;i++)
		if(out[i]==0) ans2++;
	printf("%d\n",max(ans,ans2));

}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
struct Edge
{
	int u,v;
}s[1000010];
int dfn[maxn],low[maxn],cnt=0,cnt_bcc=0,a[maxn][maxn],N,M,Index=0,belong[maxn],col[maxn];
bool iscut[maxn],mk[maxn];
vector<int> edges[maxn];
vector<int> bcc[maxn];
void addedge(int u,int v)
{
	edges[u].push_back(v);
	edges[v].push_back(u);
}
bool isbipartite(int u,int C)
{
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(belong[v]!=C) continue;
		if(col[u]==col[v]) return false;
		if(!col[v])
		{	
			col[v]=3-col[u];
			if(!isbipartite(v,C)) return false;
		}
	}
	return true;
}
void init()
{
	for(int i=1;i<=N;i++) edes[i].swap(vector<int>());
//		edges[i].clear();
	memset(a,0,sizeof a);
	memset(dfn,0,sizeof dfn);
	memset(belong,0,sizeof belong);
	memset(iscut,false,sizeof iscut);
	memset(mk,false,sizeof mk);
	cnt=0;cnt_bcc=0;
}
void tarjan(int u,int fa)
{
	int child=0;
	dfn[u]=low[u]=++cnt;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			child++;
			s[++Index]=(Edge){u,v};
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				iscut[u]=true;cnt_bcc++;
				bcc[cnt_bcc].clear();
				for(Edge e;;)
				{
					e=s[Index--];
					if(belong[e.u]!=cnt_bcc){belong[e.u]=cnt_bcc;bcc[cnt_bcc].push_back(e.u);}
					if(belong[e.v]!=cnt_bcc){belong[e.v]=cnt_bcc;bcc[cnt_bcc].push_back(e.v);}
					if(e.u==u&&e.v==v) break;
				}
			}
		}
		else if(dfn[v]<dfn[u]&&fa!=v)
		{
			s[++Index]=(Edge){u,v};
			low[u]=min(low[u],dfn[v]);
		}
		if(child==1&&fa==0) iscut[u]=false;
	}
}
int main()
{
	while(true)
	{

		scanf("%d%d",&N,&M);
		if(N==0&&M==0) break;
		init();
		for(int i=1;i<=M;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			a[u][v]=1;a[v][u]=1;
		}
		for(int i=1;i<=N;i++)
			for(int j=1+i;j<=N;j++)
				if(!a[i][j]) addedge(i,j);
		for(int i=1;i<=N;i++)
			if(!dfn[i]) tarjan(i,0);
		for(int i=1;i<=cnt_bcc;i++)
		{
			memset(col,0,sizeof col);
			for(int j=0;j<bcc[i].size();j++)
				belong[bcc[i][j]]=i;
			col[bcc[i][0]]=1;
			if(!isbipartite(bcc[i][0],i))
				for(int j=0;j<bcc[i].size();j++)
					mk[bcc[i][j]]=1;
		}
		int ans=N;
		for(int i=1;i<=N;i++)
			if(mk[i]) ans--;
		printf("%d\n",ans);
	}
	return 0;
}

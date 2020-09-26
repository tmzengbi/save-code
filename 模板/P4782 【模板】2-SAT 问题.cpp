#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2000010;;
vector<int> edges[maxn];
int N,M,s[maxn],Index=0,ans[maxn],Index_ans=0;
bool mark[maxn];
void addedge(int i,int a,int j,int b)
{
	int xi=i*2+a,xj=j*2+b;
	edges[xi^1].push_back(xj);
	edges[xj^1].push_back(xi);
}
bool dfs(int u)
{
	if(mark[u^1]) return false;
	if(mark[u]) return true;
	mark[u]=true;
	s[Index++]=u;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfs(v)) return false;
	}
	return true;
}
bool solve()
{
	for(int i=0;i<N*2;i+=2)
	{
		if(!mark[i]&&!mark[i+1])
		{
			Index=0;
			if(!dfs(i))
			{
				while(Index) mark[s[--Index]]=false;
				if(!dfs(i+1)) return false;
			}
			for(int j=0;j<Index;j++)
				ans[s[j]/2]=s[j]%2;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int ii=1;ii<=M;ii++)
	{
		int i,a,j,b;
		scanf("%d%d%d%d",&i,&a,&j,&b);
		addedge(i-1,a,j-1,b);
	}
	if(solve())
	{
		printf("POSSIBLE\n");
		for(int i=0;i<N;i++)
			printf("%d ",ans[i]);
	}
	else printf("IMPOSSIBLE\n");
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2010;
vector<int> edges[maxn];
int N,M,s[maxn],Index=0;
bool mark[maxn];
void addedge(int x,int a,int y,int b)
{
	x=x*2+a;y=y*2+b;
	edges[x].push_back(y^1);
	edges[y].push_back(x^1);
}
bool dfs(int x)
{
	if(mark[x^1]) return false;
	if(mark[x]) return true;
	mark[x]=true;
	s[Index++]=x;
	for(int i=0;i<edges[x].size();i++)
	{
		int v=edges[x][i];
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
		}
	}
	return true;
}
void init()
{
	for(int i=0;i<N*2;i++)
		edges[i].clear();
	memset(mark,false,sizeof mark);
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		init();
		for(int i=1;i<=M;i++)
		{
			int x,a,y,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			addedge(x,a,y,b);
		}
		if(solve()) printf("YES\n");
		else printf("NO\n");
	}
}
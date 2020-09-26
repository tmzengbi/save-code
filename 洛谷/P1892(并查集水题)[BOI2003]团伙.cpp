#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M,pre[1010],ans;
char rel[2];
vector<int> edges[1010];
int findRoot(int root)
{
	if(root==pre[root]) return root;
	else pre[root]=findRoot(pre[root]);
	return pre[root];
}
void merge(int x,int y)
{
	int fx=findRoot(x),fy=findRoot(y);
	if(fx!=fy) 
	{
		pre[fx]=fy;
		ans--;
	}
}
int main()
{	
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) pre[i]=i;
	ans=N;
	for(int j=1;j<=M;j++)
	{
		int x,y;
		scanf("%s%d%d",rel,&x,&y);
		if(rel[0]=='E')
		{
			for(int i=0;i<edges[y].size();i++)
			{
				int e=edges[y][i];
				if(x!=e) merge(x,e);
			}
			for(int i=0;i<edges[x].size();i++)
			{
				int e=edges[x][i];
				if(y!=e) merge(y,e);
			}
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		else if(rel[0]=='F')
			merge(x,y);
	}
	printf("%d\n",ans);
}
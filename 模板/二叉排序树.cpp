#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node
{
	int v,lc,rc,w;
	Node(){v=w=lc=rc=0;}
}t[1001];
int n,a[1001],cnt=1;
void insert(int root,int v)
{
	if(!t[root].v){t[root].v=v;t[root].w++;return;}
	if(t[root].v==v){t[root].w++;return;}
	if(v<t[root].v)
	{
		if(!t[root].lc)	t[root].lc=++cnt;
		insert(t[root].lc,v);
	}
	if(v>t[root].v)
	{
		if(!t[root].rc)	t[root].rc=++cnt;
		insert(t[root].rc,v);
	}
}
void dfs(int root)
{
	if(!root)	return;
	dfs(t[root].lc);
	for(int i=1;i<=t[root].w;i++) printf("%d ",t[root].v);
	dfs(t[root].rc);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		insert(1,a[i]);
	dfs(1);
	system("pause");
}
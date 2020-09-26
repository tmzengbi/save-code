#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int pre[100010],s[100010];
int find_root(int root)
{
	return root==pre[root]?root:(pre[root]=find_root(pre[root]));
}
void addroot(int r1,int r2)
{
	if(s[r1]>s[r2])	swap(r1,r2);
	int root1=find_root(r1),root2=find_root(r2);
	pre[root1]=root2;
	s[root2]+=s[root1];
}
int main()
{
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i; 
		s[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int f1,f2;
		scanf("%d%d",&f1,&f2);
		addroot(f1,f2);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int q1,q2;
		scanf("%d%d",&q1,&q2);
		int root1=find_root(q1),root2=find_root(q2);
		if(root1==root2) printf("Yes\n");
		else  printf("No\n");
	}
//	system("pause");
} 


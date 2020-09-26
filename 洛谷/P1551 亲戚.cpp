#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pre[5010],size[5010];
int find_root(int root)
{
	int son=root;
	while(root!=pre[root])
		root=pre[root];
	while(son!=root)
	{
		int tmp=pre[son];
		pre[son]=root;
		son=pre[son];
	}
	return root;
}
void addroot(int r1,int r2)
{
	if(size[r1]>size[r2])	swap(r1,r2);
	int root1=find_root(r1),root2=find_root(r2);
	pre[root1]=root2;
	size[root2]+=size[root1];
}
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;				//³õÊ¼»¯	 
		size[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int f1,f2;
		scanf("%d%d",&f1,&f2);
		addroot(f1,f2);
	}
	for(int i=1;i<=p;i++)
	{
		int q1,q2;
		scanf("%d%d",&q1,&q2);
		int root1=find_root(q1),root2=find_root(q2);
		if(root1==root2)	cout<<"Yes"<<endl;
		else 	cout<<"No"<<endl;
	}
} 


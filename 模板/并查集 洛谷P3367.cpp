#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int pre[10005];
int ufind(int root);
void merge(int root1,int root2);
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		pre[i]=i;
	while(M-->0)
	{
		int Z,X,Y;
		scanf("%d%d%d",&Z,&X,&Y);
		if(Z==1)
		{
			int root1=ufind(X);
			int root2=ufind(Y);
			merge(root1,root2);
		}
		else if(Z==2)
		{
			int root1=ufind(X);
			int root2=ufind(Y);
			if(root1==root2)
				cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
} 
int ufind(int root)
{
/*	int son=root;
	while(root!=pre[root])
		root=pre[root];
	while(son!=root)
	{
		int temp=pre[son];						//·ÇµÝ¹é Ñ­»·Ð´·¨ 
		pre[son]=root;
		son=temp;
	}
	return root;
*/
	if(root==pre[root])	return root;
	else pre[root]=ufind(pre[root]);			//µÝ¹éÐ´·¨ 
	return pre[root];
}
void merge(int root1,int root2)
{
	pre[root1]=root2;
}

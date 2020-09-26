#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;
int N,M;
struct Tree
{
	Tree *ls, *rs;
	int m;
}tree[maxn<<5],*root[maxn];
int a[maxn],b[maxn],c[maxn];
int t=1;
/*void dfs(Tree *tr)			//µ÷ÊÔdfs 
{
	if(tr->ls!=NULL)
		dfs(tr->ls);
	if(tr->rs!=NULL)
		dfs(tr->rs);
	cout<<tr->m<<" ";
}*/
void build(Tree *root,int l,int r)
{
	root->m=0;
	if(l==r){root->ls=NULL;root->rs=NULL;return;}
	root->ls=&tree[t++];
	root->rs=&tree[t++];
	int mid=(l+r)>>1;
	build(root->ls,l,mid);
	build(root->rs,mid+1,r);
}
void in(Tree *root,Tree *proot,int l,int r,int v)
{
	if(l==r){root->m=proot->m+1;root->ls=NULL;root->rs=NULL;return;}
	*root=*proot;
	int mid=(l+r)>>1;
	if(v<=mid)
	{
		root->ls=&tree[t++];
		in(root->ls,proot->ls,l,mid,v);
	}
	else
	{
		root->rs=&tree[t++];
		in(root->rs,proot->rs,mid+1,r,v);
	}
	root->m=root->ls->m+root->rs->m;
}
int query(Tree *root,Tree *proot,int l,int r,int x)
{
	if(l==r)	return l;
	int num=root->ls->m-proot->ls->m,mid=(l+r)>>1;
	if(num>=x)	return query(root->ls,proot->ls,l,mid,x);
	else	return query(root->rs,proot->rs,mid+1,r,x-num);
	
}
struct Node
{
	int a,b,c;
}node[maxn];
int rank[maxn];
bool cmp1(Node n1,Node n2)
{
	return	n1.a<n2.a;
}
bool cmp2(Node n1,Node n2)
{
	return n1.c<n2.c;
}
int main()
{
	root[0]=&tree[0];
	memset(b,0,sizeof b);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&node[i].a);
		node[i].c=i;
	}
	sort(node+1,node+N+1,cmp1);
	node[0].a=node[1].a-1;int Index=0;
	for(int i=1;i<=N;i++)
	{
		if(node[i].a!=node[i-1].a)	node[i].b=++Index;
		else node[i].b=Index;
		rank[node[i].b]=node[i].a;
	}
	int tot=node[N].b;
	sort(node+1,node+N+1,cmp2);
/*	b[1]++;c[1]=1;int Index=1;
	for(int i=2;i<=N;i++)
	{
		if(a[i]!=a[i-1]){b[++Index]++;c[i]=c[i-1]+1;}
		else {b[Index]++;c[i]=c[i-1];}
	}
	int tot=unique(c+1,c+N+1)-c-1;
	*/
	build(root[0],1,tot);
	for(int i=1;i<=N;i++)	root[i]=&tree[t++];
	for(int i=1;i<=N;i++)
		in(root[i],root[i-1],1,tot,node[i].b);
/*	for(int i=1;i<=N;i++)
	{
		dfs(root[i]);			//µ÷ÊÔ 
		cout<<endl;
	}
	*/
	while(M--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		int tag=query(root[r],root[l-1],1,tot,k);
		printf("%d\n",rank[tag]);
	}
} 
/*
5 5
1 1 2 2 3
1 4 2 
1 3 2
1 4 2
1 5 2
2 5 1
*/

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct node_t
{
	int v,Index;
	node_t* left,* right;
	node_t():v(0),Index(0),left(NULL),right(NULL){	}
};
map<int,int> trans;
int Min,Max;
node_t* newnode();
void remove_tree(node_t* u);
void dataread(node_t* now);
void print(node_t* now);
void get_se(int& s,int& e,node_t now);
inline int read();
int main()
{
	int n,Index=1;
	node_t* root=newnode();
	while(cin>>n)
	{
		remove_tree(root);
		trans.clear();
		Min=2000000000,Max=-2000000000;
		root->v=n;trans[0]=n;
		if(n==-1)	return 0;
		dataread(root);
		printf("Case %d:\n",Index);
		for(int i=Min;i<=Max;i++)
			cout<<trans[i]<<" ";
		printf("\n\n");
		Index++;
		
	}
	
} 
inline int read()
{
	int f=1,shu=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
node_t* newnode()
{
	return new node_t();
}
void dataread(node_t* now)
{
	int l=read();
	if(l!=-1)
	{
		if(now->left==NULL)	
			now->left=newnode(); 
		node_t* vl=now->left;
		vl->Index=now->Index-1;
		vl->v=l;
		dataread(vl);
		trans[vl->Index]+=l;
		Min=min(Min,vl->Index);
	}
	int r=read();
	if(r!=-1)
	{
		if(now->right==NULL)	
			now->right=newnode();
		node_t* vr=now->right;
		vr->Index=now->Index+1;
		vr->v=r;
		dataread(vr);
		trans[vr->Index]+=r;
		Max=max(Max,vr->Index);
	}
}
void remove_tree(node_t* u)
{
	if(u==NULL)	return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}

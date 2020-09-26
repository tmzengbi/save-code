#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	bool have_value;
	int v;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){	}
};
Node *root;
vector<int> ans;
void addnode(int v,char *s);
Node *newnode();
bool bfs();
int read();
int main()
{
	char s[10005];
	root=newnode();
	while(scanf("%s",s)==1)
	{
		int Index=1,shu=0;
		while(!isalpha(s[Index])&&s[Index]!=',')
		{
			shu=shu*10+s[Index]-'0';
			Index++;
		}
		if(!strcmp(s,"()"))	break;
		addnode(shu,s+Index);
	}
	if(bfs())	
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	else cout<<"not complete";
}
int read()
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
void addnode(int v,char *s)
{
//	cout<<s<<endl;
	int len=strlen(s);
	Node* u=root;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='L')
		{
			if(u->left==NULL) u->left=newnode();
			u=u->left;
		}
		else if(s[i]=='R')
		{
			if(u->right==NULL) u->right=newnode();
			u=u->right;
		}
		else if(s[i]==')') continue;
	}
	u->v=v;
	u->have_value=true;
}
Node *newnode()
{
	return new Node();
}
bool bfs()
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()) 
	{
		Node *u=q.front();q.pop();
		if(!u->have_value) return false; 
		ans.push_back(u->v);
		if(u->left!=NULL) q.push(u->left);
		if(u->right!=NULL) q.push(u->right);
	}
	return true;
}

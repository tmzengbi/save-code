#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	Node *Next[26];
	int cnt;
	Node(){for(int i=0;i<26;i++)Next[i]=NULL;cnt=0;}
}*root;
void build(Node *root,char *s)
{
	int len=strlen(s),i=0;
	while(i<len)
	{
		int ch=s[i]-'a';
		if(root->Next[ch]==NULL)
			root->Next[ch]=new Node();
		root=root->Next[ch];
		root->cnt++;i++;
	}
}
int query(Node *root,char *s)
{
	int len=strlen(s),i=0;
	while(i<len)
	{
		int ch=s[i]-'a';
		if(root->Next[ch]==NULL) return 0;
		root=root->Next[ch];i++;
	}
	return root->cnt;
}
int main()
{
	root=new Node();
	char st[25];
	while(cin.getline(st,12))
	{
		if(strlen(st)==0||st[0]==' ')break;
		build(root,st);
	}

	char s[25];
	while(scanf("%s",s)!=EOF)
		printf("%d\n",query(root,s));
	
}
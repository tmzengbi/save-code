#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	Node* Next[26];
	bool vis;
	Node(){for(int i=0;i<=25;i++) Next[i]=NULL;vis=false;}
}*root;
int cnt=0,n;
void build(Node *root,char *s,int len,int now)
{
	if(now==len) return;
	int ch=s[now]-'a';
	if(root->Next[ch]==NULL)
		root->Next[ch]=new Node();
	build(root->Next[ch],s,len,now+1);

}
int Find(Node *root,char *s,int len,int now)
{
	if(now==len)
	{
		if(root->vis==false)
		{
			root->vis=true;
			return 1;
		}
		else return 2;
	}
	int ch=s[now]-'a';
	if(root->Next[ch]==NULL) return 3;
	return Find(root->Next[ch],s,len,now+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	root=new Node();
	for(int i=1;i<=n;i++)
	{
		char s[110];
		cin>>s;int len=strlen(s);
		build(root,s,len,0);
	}
	int m;cin>>m;
	while(m--)
	{
		char ss[110];
		cin>>ss;int len=strlen(ss);
		int res=Find(root,ss,len,0);
		if(res==1) cout<<"OK"<<endl;
		else if(res==2) cout<<"REPEAT"<<endl;
		else cout<<"WRONG"<<endl;
	}

//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ans,cnt=0;
struct Node
{
	Node* Next[26],*Fail,*last;
	int cnt;
	bool isaword;
	void init()
	{
		memset(Next,0,sizeof Next);
		isaword=false;cnt=0;
	}
	Node(){init();}
}root,dizhi[200010];
vector<Node*> v;
void build(char *s)
{
	int len=strlen(s),i;
	Node *now=&root;
	for(i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		if(!now->Next[ch]) now->Next[ch]=&dizhi[++cnt];
		now=now->Next[ch];
	}
	now->isaword=true;
	v.push_back(now);
}
void getFail()
{
	queue<Node*> q;
	q.push(&root);
	while(!q.empty())
	{
		Node *now=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(now->Next[i])
			{
				if(now==&root)
				{
					now->Next[i]->Fail=&root;
					now->last=&root;
					if(!now->Next[i]) now->Next[i]=&root;
				}
				else
				{
					Node* tmp=now;
					while(tmp->Fail!=&root&&tmp->Fail->Next[i]==NULL)
						tmp=tmp->Fail;
					now->Next[i]->Fail=tmp->Fail->Next[i];
				}
				q.push(now->Next[i]);
			}
			else 
			{
				if(now->Fail->Next)
					now->Next[i]=now->Fail->Next[i];
				else now->Next[i]=&root;
			}
			if(now!=&root)	now->last=now->Fail->isaword?now->Fail:now->Fail->last;
		}
	}
}
void AC(char* s)
{
	ans=0;root.last=&root;
	int len=strlen(s),i;
	Node* now=&root;
	for(i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		now=now->Next[ch];
		Node *tmp=now;
		while(tmp!=&root)
		{
			if(tmp->isaword) tmp->cnt++;
			tmp=tmp->last;
		}
	}
}
int main()
{
	int N;
	scanf("%d",&N);getchar();
	while(N--)
	{
		char ss[75];
		scanf("%s",ss);
		build(ss);
	}
	char s[2000010];
	scanf("%s",s);
	getFail();
	AC(s);
	for(int i=0;i<v.size();i++)
		printf("%d\n",v[i]->cnt);
//	system("pause");
}



/*
2
aba
bab
ababababac
6
beta
alpha
haha
delta
dede
tata
dedeltalphahahahototatalpha
0
*/
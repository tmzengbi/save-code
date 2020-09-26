#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
	Node *Next[26],*Fail;
	bool vis,arrive;
	int Word;
	Node()
	{
		for(int i=0;i<=25;i++) Next[i]=NULL;
		vis=arrive=false;
		Word=0;
		Fail=NULL;
	}
}root;
int n;
void build(char *s)
{
	Node *now=&root;
	int len=strlen(s),i;
	for(i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		if(now->Next[ch]==NULL)
			now->Next[ch]=new Node();
		now=now->Next[ch];
	}
	now->Word++;
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
			if(now->Next[i]==NULL) continue;
			else q.push(now->Next[i]);
			if(now==&root)
				now->Next[i]->Fail=&root;
			else
			{
				Node *tmp=now;
				while(tmp->Fail!=&root&&tmp->Fail->Next[i]==NULL)
					tmp=tmp->Fail;
				if(tmp->Fail->Next[i]==NULL)
					now->Next[i]->Fail=&root;
				else now->Next[i]->Fail=tmp->Fail->Next[i];

//				if(now->Fail->Next[i]==NULL)
//					now->Next[i]->Fail=&root;
//				else now->Next[i]->Fail=now->Fail->Next[i];
			}
		}

	}
}
int work(char *s)
{
	int cnt=0;
	Node *now=&root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		while(now->Next[ch]==NULL)
		{
			if(now==&root) break;
			now=now->Fail;
			
		}
		if(now->Next[ch]==NULL) continue;
		now=now->Next[ch];
		Node *tmp=now;
		while(tmp!=&root)
		{
			if(!tmp->vis)
			{
				cnt+=tmp->Word;
				tmp->vis=true;
			}
			else break;
			tmp=tmp->Fail;
			
		}
//		now=now->Next[ch];


	}
	return cnt;
}

int main()
{
	scanf("%d",&n);getchar();
	while(n--)
	{
		char s[1000010];
		scanf("%s",s);
		build(s);
	}
	getFail();
	char ss[1000010];
	scanf("%s",ss);
	printf("%d\n",work(ss));

//	system("pause");
}

/*
6
aa
ash
sh
shex
bcd
sha
ashashexxbdshabcd

3
asdddd
sddd
d
asdddd
*/
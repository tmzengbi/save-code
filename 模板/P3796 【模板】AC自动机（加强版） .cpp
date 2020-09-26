#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int ans,cnt=0;
struct Node
{
	Node* Next[26],*Fail;
	int cnt;
	bool isaword;
	char str[75];
	void init()
	{
		memset(Next,0,sizeof Next);
//		for(int i=0;i<25;i++)
//			Next[i]=NULL;
		isaword=false;cnt=0;
		strcpy(str,"");
	}
	Node(){init();}
}root,dizhi[20010];
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
	strcpy(now->str,s);
	now->isaword=true;
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
					now->Next[i]->Fail=&root;
				else
				{
					Node* tmp=now;
					while(tmp->Fail!=&root&&tmp->Fail->Next[i]==NULL)
						tmp=tmp->Fail;
					if(tmp->Fail->Next[i]==NULL)
						now->Next[i]->Fail=&root;
					else now->Next[i]->Fail=tmp->Fail->Next[i];
				}
				q.push(now->Next[i]);
			}
		}
	}
}
void AC(char* s)
{
	ans=0;
	int len=strlen(s),i;
	Node* now=&root;
	for(i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		while(now->Next[ch]==NULL&&now!=&root) now=now->Fail;
		if(now->Next[ch]==NULL) continue;
		now=now->Next[ch];
		Node *tmp=now;
		while(tmp!=&root)
		{
			if(tmp->isaword)
			{
				tmp->cnt++;
				if(ans<tmp->cnt)
					ans=tmp->cnt;
			}
			tmp=tmp->Fail;
		}
	}
}
int main()
{
	int N;
	while(true)
	{
		cnt=0;root.init();
		for(int i=0;i<=20000;i++)
			dizhi[i].init();
		scanf("%d",&N);getchar();
		if(N==0) return 0;
		while(N--)
		{
			char ss[75];
			scanf("%s",ss);
			build(ss);
		}
		char s[1000010];
		scanf("%s",s);
		getFail();

		AC(s);
		printf("%d\n",ans);
		for(int i=1;i<=20000;i++)
			if(dizhi[i].isaword)
			{
				if(dizhi[i].cnt==ans)
					printf("%s\n",dizhi[i].str);
			}

	}


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
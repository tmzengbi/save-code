#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	Node *Next[26];
	char trans[15];
	bool vis;
	Node(){for(int i=0;i<26;i++) Next[i]=NULL;vis=false;}
}root;
bool ischar(char ch)
{
	if(ch<'a'||ch>'z') return false;
	return true;
}
void build(char *s,char *ss)
{
	Node* now=&root;
	int len=strlen(ss),i;
	for(i=0;i<len;i++)
	{
		int ch=ss[i]-'a';
		if(now->Next[ch]==NULL)
			now->Next[ch]=new Node();
		now=now->Next[ch];	
	}
	now->vis=true;
	strcpy(now->trans,s);
}
char* Find(char *s)
{
	Node *now=&root;
	int len=strlen(s),i;
	for(i=0;i<len;i++)
	{
		int ch=s[i]-'a';
		if(now->Next[ch]==NULL)
			return s;
		now=now->Next[ch];
	}
	if(!now->vis) return s;
	return now->trans;
}
int main()
{
	char s[16];scanf("%s",s);
	while(true)
	{
		char ss[15],s0[15];
		scanf("%s",s0);
		if(s0[0]=='E') break;
		scanf("%s",ss);
		build(s0,ss);
	}
	scanf("%s",s);getchar();
	while(true)
	{
		char st[3011];
		cin.getline(st,3010);
		if(st[0]=='E') break;
		int len=strlen(st),i=0,j=0;
		while(j<len)
		{
			char ss[35];
			while(j<len&&ischar(st[j]))	ss[i++]=st[j++];
			ss[i]='\0';
			i=0;
			printf("%s",Find(ss));
			while(j<len&&!ischar(st[j]))
			{
				printf("%c",st[j]);
				j++;
			}
		}
		printf("\n");
	}

//	system("pause");
}
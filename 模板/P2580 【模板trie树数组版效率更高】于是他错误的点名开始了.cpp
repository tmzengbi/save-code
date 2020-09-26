#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdarg.h>
using namespace std;
const int maxnode=10001*50;
struct trie
{
	int Next[maxnode][26],val[maxnode];
	int cnt;
	trie(){cnt=0;memset(Next[cnt],0,sizeof Next[cnt]);}
	void insert(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'a';
			if(!Next[u][ch])
			{
				val[++cnt]=0;
				Next[u][ch]=cnt;
			}
			u=Next[u][ch];
		}
	}
	int query(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'a';
			if(!Next[u][ch]) return 0;
			u=Next[u][ch];
		}
		if(val[u]) return 2;
		val[u]=1;
		return 1;
	}
}trie;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[55];
		scanf("%s",s);
		trie.insert(s);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[55];
		scanf("%s",s);
		int ans=trie.query(s);
		if(ans==0) printf("WRONG\n");
		if(ans==1) printf("OK\n");
		if(ans==2) printf("REPEAT\n");
	}
//	system("pause");

}
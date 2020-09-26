#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdarg.h>
using namespace std;
const int maxnode=4010*100,P=20071027;
char s1[3000010],s2[110];int n;
int dp[3000010];
struct Trie
{
	int Next[maxnode][26];
	bool isword[maxnode];
	int cnt;
	Trie(){cnt=0;memset(Next[cnt],0,sizeof Next[cnt]);}
	void init()
	{
		for(int i=0;i<=cnt;i++) memset(Next[i],0,sizeof Next[i]);
		memset(isword,false,sizeof isword);
		memset(dp,0,sizeof dp);
		cnt=0;
	}
	void insert(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'0';
			if(!Next[u][ch])
			{
				cnt++;
				isword[cnt]=false;
				Next[u][ch]=cnt;
			}
			u=Next[u][ch];
		}
		isword[u]=true;
	}
	void solve(char *s)
	{
		int len=strlen(s),u=0,sz=0;
		dp[len]=1;
		for(int i=len-1;i>=0;i--)
		{
			u=0;sz=0;
			int ch=s[i]-'0';
			while(Next[u][ch]&&i+sz<len)
			{
				u=Next[u][ch];
				if(isword[u]) dp[i]=(dp[i]+dp[i+sz+1])%P;
				sz++;ch=s[i+sz]-'0';
			}
		}
	}
}trie;
int main()
{
	int tot=0;
	while(scanf("%s",s1)==1)
	{
		trie.init();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s",s2);
			trie.insert(s2);
		}
		trie.solve(s1);
		printf("Case %d: %d\n",++tot,dp[0]);
	}
	
}
/*
abcd 4 a b cd ab
*/
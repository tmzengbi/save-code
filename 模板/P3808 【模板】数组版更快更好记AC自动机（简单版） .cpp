#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxnode=1000010;
int N,ans=0;
char s[1000010];
struct Trie
{
	int cnt,Next[maxnode][26],Fail[maxnode],val[maxnode],last[maxnode],vis[maxnode];
	Trie(){cnt=0;memset(Next[0],0,sizeof Next[0]);val[0]=0;}
	void insert(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'a';
			if(!Next[u][ch])
			{
				cnt++;val[cnt]=0;
				Next[u][ch]=cnt;
			}
			u=Next[u][ch];
		}
		val[u]++;
		vis[u]=0;
	}
	void FindFail()
	{
		queue<int>q;
		for(int i=0;i<26;i++)
		{
			int u=Next[0][i];
			if(u){q.push(u);Fail[u]=last[u]=0;}
		}
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<26;i++)
			{
				int v=Next[u][i];
				if(!v){Next[u][i]=Next[Fail[u]][i];continue;}
				q.push(v);
				int r=Fail[u];
				while(r&&!Next[r][i]) r=Fail[r];
				Fail[v]=Next[r][i];
				last[v]=val[Fail[v]]?Fail[v]:last[Fail[v]];
			}
		}
	}
	void print(int u)
	{
		if(u)
		{
//			printf("%d %d %d\n",u,vis[u],val[u]);
			if(!vis[u])
			{
				ans+=val[u];
				vis[u]=1;
			}
			print(last[u]);
		}
	}
	void AC(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
//			printf("%d\n",u);
//			system("pause");
			int ch=s[i]-'a';
			u=Next[u][ch];
			if(val[u]) print(u);
			else if(last[u]) print(last[u]);
//			printf("%d %d\n",u,ans);
		}
	}
}trie;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%s",s);
		trie.insert(s);
	}
	scanf("%s",s);
	trie.FindFail();
	trie.AC(s);
	printf("%d\n",ans);
//	system("pause");

}
/*
4
abba
accab
aba
ccab
abbaccab
*/
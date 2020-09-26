#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxnode=4001*1000;
ll ans=0;
struct Trie
{
	int tot[maxnode],son[maxnode],bro[maxnode],sz;
	char ch[maxnode];
	Trie(){init();}
	void init()
	{
		sz=0;tot[sz]=son[sz]=bro[sz]=0;ans=0;
	}
	void insert(char *s)
	{
		int len=strlen(s),u=0,to;
		tot[0]++;
		for(int i=0;i<=len;i++)
		{
			for(to=son[u];to;to=bro[to])
				if(s[i]==ch[to]) break;
			if(!to)
			{
				to=++sz;
				son[to]=0;
				tot[to]=0;ch[to]=s[i];
				bro[to]=son[u];son[u]=to;
			}
			else ans+=(ll)tot[to]*2;
			tot[to]++;
			ans+=(ll)tot[u]-tot[to];
			u=to;
		}
	}
}trie;
int main()
{
	int n;char s[1010],tt=0;
	while(scanf("%d",&n)==1&&n)
	{
		trie.init();
		while(n--)
		{
			scanf("%s",s);
			trie.insert(s);
		}
		printf("Case %d: %lld\n",++tt,ans);
	}
//	system("pause");
}
/*
2 a b 4 cat hat mat sir 
*/
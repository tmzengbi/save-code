#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxnode=150*70+10;
map<string,int> M;
struct acauto
{
	int Next[maxnode][26],Fail[maxnode],cnt,val[maxnode],last[maxnode],tot[maxnode];
	void init()
	{
		cnt=0;M.clear();memset(Next[0],0,sizeof Next[0]);memset(tot,0,sizeof tot);
	}
	void insert(char *s,int id)
	{
		string ss=string(s);
		if(M.find(ss)!=M.end()) return;
		else M[ss]=id;
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'a';
			if(!Next[u][ch])
			{
				cnt++;
				memset(Next[cnt],0,sizeof Next[cnt]);
				val[cnt]=0;
				Next[u][ch]=cnt;
			}
			u=Next[u][ch];
		}
		val[u]=id;
	}
	void getFail()
	{
		queue<int>q;
		for(int i=0;i<26;i++)
		{
			if(Next[0][i])
			{
				q.push(Next[0][i]);
				Fail[Next[0][i]]=last[Next[0][i]]=0;
			}
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
	void update(int u)
	{
		if(!u) return;
		tot[val[u]]++;
		update(last[u]);
	}
	void AC(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=s[i]-'a';
			u=Next[u][ch];
			if(val[u]) update(u);
			else if(last[u]) update(last[u]);
		}
	}
}ac;
int N;char s[1000010],ss[155][77];
int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		ac.init();
		for(int i=1;i<=N;i++)
		{
			scanf("%s",ss[i]);
			ac.insert(ss[i],i);
		}
		ac.getFail();
		scanf("%s",s);
		ac.AC(s);
		int ans=0;
		for(int i=1;i<=N;i++)
			ans=max(ans,ac.tot[i]);
		printf("%d\n",ans);
		for(int i=1;i<=N;i++)
			if(ac.tot[M[string(ss[i])]]==ans) printf("%s\n",ss[i]);
	}
}
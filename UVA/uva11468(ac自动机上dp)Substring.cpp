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
int T,L,N,M;
double dp[110][410],prob[62];
bool vis[110][410];
const int maxnode=410;
int trans(char ch)
{
	if(ch>='0'&&ch<='9') return ch-'0';
	if(ch>='a'&&ch<='z') return ch-'a'+10;
	if(ch>='A'&&ch<='Z') return ch-'A'+36;
}
struct acauto
{
	int Next[maxnode][62],Fail[maxnode],cnt,last[maxnode];
	bool val[maxnode];
	void init()
	{
		memset(Next[0],0,sizeof Next[0]);
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		cnt=0;val[0]=0;
	}
	void insert(char *s)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int ch=trans(s[i]);
			if(!Next[u][ch])
			{
				cnt++;
				memset(Next[cnt],0,sizeof Next[cnt]);
				val[cnt]=0;Next[u][ch]=cnt;
			}
			u=Next[u][ch];
		}
		val[u]=1;
	}
	void getFail()
	{
		queue<int>q;while(!q.empty())q.pop();
		for(int i=0;i<62;i++)
		{
			int x=Next[0][i];
			if(x){q.push(x);last[x]=Fail[x]=0;}
		}
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<62;i++)
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
	double solve(int x,int u)
	{
		if(x>L) return 1.0;
		if(vis[x][u]) return dp[x][u];
		vis[x][u]=1;
		for(int i=0;i<62;i++)
		{
			int v=Next[u][i];
			if(!val[v]&&!last[v]) dp[x][u]+=solve(x+1,v)*prob[i];
		}
		return dp[x][u];
	}
}ac;
char s[1010];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int cas=0;
	scanf("%d",&T);
	while(T--)
	{
		ac.init();
		memset(prob,0,sizeof prob);
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%s",s);
			ac.insert(s);
		}
		ac.getFail();
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
		{
			double pb;
			scanf("%s %lf",s,&pb);
			prob[trans(s[0])]=pb;
		}
		scanf("%d",&L);
		printf("Case #%d: ",++cas);
		printf("%.6lf\n",ac.solve(1,0));
	}
//	system("pause");
}

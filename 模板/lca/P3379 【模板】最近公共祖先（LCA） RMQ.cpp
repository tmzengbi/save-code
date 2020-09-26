#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=500010;
int Log[maxn<<1],cnt=0,first[maxn<<1],k[maxn<<1],dep[maxn<<1],st[maxn<<1][25];
vector<int> edges[maxn];
inline int read()
{
	char ch=getchar();int shu=0,f=1;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
void ST(int n)
{
	Log[1]=0;
	for(int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for(int i=0;i<=Log[n];i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			if(i==0) st[j][i]=j;
			else 
			{
				int a=st[j][i-1],b=st[j+(1<<(i-1))][i-1];
				st[j][i]=dep[a]<dep[b]?a:b;
			}
		}
}
int getMin(int l,int r)
{
	int d=Log[r-l+1],a=st[l][d],b=st[r-(1<<d)+1][d];
	return dep[a]<dep[b]?k[a]:k[b];
}
void dfs(int u,int fa,int d)
{
	k[++cnt]=u;
	dep[cnt]=d;
	first[u]=cnt;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		dfs(v,u,d+1);
		k[++cnt]=u;
		dep[cnt]=d;
	}
}
int main()
{
	int m,n,c;
	n=read();m=read();c=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(c,c,1);
	ST(cnt);
	while(m--)
	{
		int x=read(),y=read();
		x=first[x];y=first[y];
		if(x>y) swap(x,y);
		printf("%d\n",getMin(x,y));
	}
}
/*
7 6
1 2
1 3
2 4
2 5
5 6
5 7
*/
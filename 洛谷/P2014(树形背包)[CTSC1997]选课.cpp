#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=310;
int n,m,val[maxn],f[maxn];
vector<int>edges[maxn];
vector<pii>part[maxn];
void dfs(int u)
{
	for(int v:edges[u]) dfs(v);
	memset(f,-1,sizeof f);f[0]=0;
	for(int v:edges[u])
	{
		for(int j=m;j>=0;j--)
			for(pii i:part[v])
			{
				if(j-i.first>=0&&f[j-i.first]!=-1) f[j]=max(f[j],f[j-i.first]+i.second);
			}
	}
	int d=(u==0?0:1);
	for(int i=0;i<=m;i++)
		if(i+d<=m&&f[i]!=-1) part[u].push_back(make_pair(i+d,f[i]+val[u]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int from;scanf("%d%d",&from,&val[i]);
		edges[from].push_back(i);
	}
	dfs(0);
	int ans=0;
	for(pii i:part[0])
		ans=max(ans,i.second);
	printf("%d\n",ans);
//	system("pause");
}
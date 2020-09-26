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
typedef pair<int,int>pii;
const int maxn=510;
vector<int>edges[maxn];
int n,m,k,g[maxn],ok[maxn],vis[maxn];
bool match(int u)
{
	for(int v:edges[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(!g[v]||match(g[v]))
		{
			ok[u]=v;g[v]=u;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof vis);
		if(match(i)) ans++;
	}
	printf("%d\n",ans);
//	system("pause");
}
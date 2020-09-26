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
const int maxn=1510;
vector<int>edges[maxn];
int n;
vector<int>lef;
void colorbipartile(int u,int fa,int now)
{
	if(now) lef.push_back(u);
	for(int v:edges[u])
	{
		if(v==fa) continue;
		colorbipartile(v,u,now^1);
	}
}
bool vis[maxn];
int pre[maxn];
bool match(int u)
{
	for(int v:edges[u])
	{
		if(vis[v]) continue;
		vis[v]=1;
		if(!pre[v]||match(pre[v]))
		{
			pre[v]=u;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,siz;scanf("%d%d",&u,&siz);
		for(int j=1;j<=siz;j++)
		{
			int v;scanf("%d",&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
	}
	colorbipartile(0,0,0);
	int ans=0;
	for(int u:lef)
	{
		memset(vis,0,sizeof vis);
		if(match(u)) ans++;
	}
	printf("%d\n",ans);
//	system("pause");
}
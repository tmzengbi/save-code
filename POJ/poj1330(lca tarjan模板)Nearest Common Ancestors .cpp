#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10010;
int t,pre[maxn],n,cnt=0,in[maxn],q1,q2,ans;
bool vis[maxn];
vector<int> edges[maxn];
int findroot(int r)
{
	return r==pre[r]?r:pre[r]=findroot(pre[r]);
}
void merge(int r1,int r2)
{
	pre[findroot(r1)]=findroot(r2);
}
bool lca(int u,int fa)
{
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		if(lca(v,u)) return true;
		merge(v,u);
		vis[v]=true;
	}
	if(u==q1&&vis[q2])
	{
		ans=findroot(q2);
		return true;
	}
	else if(u==q2&&vis[q1])
	{
		ans=findroot(q1);
		return true;
	}
	return false;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		edges[i].clear();
	}
	memset(in,0,sizeof in);
	memset(vis,false,sizeof vis);
	cnt=0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int s;
		scanf("%d",&n);
		init();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
			in[v]++;
		}
		for(int i=1;i<=n;i++)
			if(in[i]==0){s=i;break;}
		scanf("%d%d",&q1,&q2);
		if(lca(s,s)) printf("%d\n",ans);

	}
//	system("pause");
}
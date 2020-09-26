#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=100010;
vector<int>edges[maxn];
int N,M,a[maxn],ans[maxn],pre[maxn];
bool vis[maxn];
int Find(int r)
{
	return r==pre[r]?r:(pre[r]=Find(pre[r]));
}
void merge(int r1,int r2,int p)
{
	r1=Find(r1);r2=Find(r2);
	if(r1!=r2)
	{
		pre[r1]=r2;
		ans[p]--;
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&N,&M)==2)
	{
		for(int i=1;i<=N;i++) pre[i]=i;
		for(int i=1;i<=N;i++)
			edges[i].clear();
		memset(vis,false,sizeof vis);
		memset(ans,0,sizeof ans);
		for(int i=1;i<=M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		for(int i=N;i;i--)
		{
			int u=a[i];vis[u]=true;ans[i]=ans[i+1]+1;
			for(int j=0;j<edges[u].size();j++)
			{
				int v=edges[u][j];
				if(vis[v]) merge(u,v,i);
			}
		}
		for(int i=1;i<=N;i++)
			printf("%d\n",ans[i]);
	}
}
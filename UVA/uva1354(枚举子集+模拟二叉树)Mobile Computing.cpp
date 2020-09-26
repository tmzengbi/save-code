#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
const int maxn=1<<6;
struct Tree
{
	double l,r;
	Tree(){l=r=0;}
};
int s,w[7],T,vis[maxn];
double L,ans=-1,sum[maxn];
vector<Tree> t[maxn];
void dfs(int now)
{
	int child=0;
	if(vis[now]) return;
	vis[now]=1;
	for(int i=(now-1)&now;i;i=(i-1)&now)
	{
		child=1;
		int r=now-i;
		double d1=sum[r]/sum[now];
		double d2=sum[i]/sum[now];
		dfs(i);dfs(r);
		for(int j=0;j<t[i].size();j++)
			for(int k=0;k<t[r].size();k++)
			{
				Tree tt;
				tt.l=max(t[i][j].l+d1,t[r][k].l-d2);
				tt.r=max(t[i][j].r-d1,t[r][k].r+d2);				
				if(tt.l+tt.r<L) t[now].push_back(tt);
			}
	}
	if(!child) t[now].push_back(Tree());
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		memset(vis,0,sizeof vis);
		scanf("%lf%d",&L,&s);
		for(int i=1;i<=s;i++) scanf("%d",&w[i]);
		for(int i=0;i<(1<<s);i++)
		{
			sum[i]=0;
			t[i].clear();
			for(int j=0;j<s;j++)
				if(i&(1<<j)) sum[i]+=w[j+1];
		}
		int st=(1<<s)-1;
		dfs(st);
		for(int i=0;i<t[st].size();i++)
			ans=max(ans,t[st][i].l+t[st][i].r);
		if(ans==-1) printf("-1\n");
		else printf("%.16lf\n",ans);
	}
	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
vector<int>scc[200010];
vector<int>edges[200010];
int scc_cnt=0,N,M,ans[3],pre[200010],trans[200010],tot[200010];
bool vis[200010];
int Find(int r)
{
	return r==pre[r]?r:(pre[r]=Find(pre[r]));
}
void merge(int r1,int r2)
{
	r1=Find(r1);r2=Find(r2);
	if(r1==r2) tot[r1]++;
	else
	{
		pre[r1]=r2;
		tot[r2]+=tot[r1]+1;
	}
	
}
int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(ans,0,sizeof ans);
		memset(vis,false,sizeof vis);
		memset(tot,0,sizeof tot);
		scc_cnt=0;
		for(int i=1;i<=N;i++) edges[i].clear();
		for(int i=1;i<=N;i++) pre[i]=i;
		for(int i=1;i<=M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			merge(u,v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int i=1;i<=N;i++)
		{
			if(vis[Find(i)]) scc[trans[Find(i)]].push_back(i);
			else
			{
				vis[Find(i)]=true;
				scc_cnt++;
				scc[scc_cnt].clear();
				trans[Find(i)]=scc_cnt;
				scc[scc_cnt].push_back(i);
			}
			ans[1]=max(ans[1],tot[i]);
		}
		for(int i=1;i<=scc_cnt;i++)
		{
			int len=scc[i].size();
			ans[2]=max(ans[2],len);
//			for(int j=0;j<scc[i].size();j++)
//				cout<<scc[i][j]<<" ";
//			cout<<endl;
		}
		ans[0]=scc_cnt;
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	}
}
/*
6 0

6 1
1 3

8 8
1 8
3 1
8 3
2 3
2 1
5 4
6 7
4 6

3 5
1 2
2 3
3 1
2 3
1 3

9 10
1 2
2 3
3 4
4 9
5 6
6 7
7 8
8 5
6 8
5 7
*/
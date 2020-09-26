#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500;
int F,cnt[maxn+10],map[maxn+10][maxn+10];
vector<int> edge[maxn+10];
vector<int> ans;
void dfs(int u)
{
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(map[u][v])
		{
			map[u][v]--;map[v][u]--;
			dfs(v);
			ans.push_back(v);
		}
	}
}
int main()
{
	memset(map,0,sizeof map);
	memset(cnt,0,sizeof cnt);
	scanf("%d",&F);
	for(int ii=1;ii<=F;ii++)
	{
		int i,j;
		scanf("%d%d",&i,&j);
		map[i][j]++;map[j][i]++;
		edge[i].push_back(j);
		edge[j].push_back(i);
		cnt[i]++;cnt[j]++;
	}
	for(int i=1;i<=maxn;i++)
		sort(edge[i].begin(),edge[i].end());
	int st=1;
	for(int i=1;i<=maxn;i++)
		if(cnt[i]%2){st=i;break;}
	dfs(st);ans.push_back(st);
	for(int i=ans.size()-1;i>=0;i--)
//		cout<<ans[i]<<" ";
		printf("%d\n",ans[i]);
//	system("pause");
}
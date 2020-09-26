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
int N,M,in[maxn],ans[maxn];
void toposort()
{
	priority_queue<int>q;
	int cnt=N;
	for(int i=1;i<=N;i++)
		if(in[i]==0){q.push(i);}
	while(!q.empty())
	{
		int u=q.top();q.pop();
		ans[u]=cnt--;
		for(int i=0;i<edges[u].size();i++)
		{
			int v=edges[u][i];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&N,&M)==2)
	{
		for(int i=1;i<=N;i++)
			edges[i].clear();
		memset(in,0,sizeof in);
		for(int i=1;i<=M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			edges[v].push_back(u);
			in[u]++;
		}
		toposort();
		for(int i=1;i<=N;i++)
		{
			printf("%d",ans[i]);
			if(i<N) printf(" ");
		}
		printf("\n");
	}
}
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
int N,M,Q,tot[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d%d",&N,&M,&Q)==3)
	{
		for(int i=1;i<=N;i++) edges[i].clear();
		for(int i=1;i<=M;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int i=1;i<=N;i++)
		{
			sort(edges[i].begin(),edges[i].end());
			tot[i]=unique(edges[i].begin(),edges[i].end())-edges[i].begin();
//			cout<<tot[i]<<endl;
		}
		
		for(int i=1;i<=Q;i++)
		{
			int u,id;scanf("%d%d",&u,&id);
			if(id>tot[u]) printf("-1\n");
			else printf("%d\n",edges[u][id-1]);
		}
	}
}
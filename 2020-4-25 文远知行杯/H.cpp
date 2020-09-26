#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int n,m,s,a,b;
vector<int>edges[maxn][2];
bool vis[maxn];
queue<pii>q;
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&s,&a,&b);
	for(int i=1;i<=m;i++)
	{
		int u,v,opt;scanf("%d%d%d",&u,&v,&opt);
		edges[u][opt].push_back(v);
		edges[v][opt].push_back(u);
	}
	q.push(make_pair(s,0));
	vis[s]=1;
	while(!q.empty())
	{
		auto from=q.front();q.pop();
		if(from.second<a)
		{
			for(auto to:edges[from.first][0])
			{
				if(!vis[to])
				{
					q.push(make_pair(to,from.second+1));
					vis[to]=1;
				}
			}
		}
		if(from.second<b)
		{
			for(auto to:edges[from.first][1])
			{
				if(!vis[to])
				{
					q.push(make_pair(to,from.second+1));
					vis[to]=1;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(vis[i]) ans++;
	printf("%d\n",ans);
//	system("pause");
}
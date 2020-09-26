#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2010;
int N1,N2,M,cnt=0,pre[maxn],a[maxn];
long long ans=0;
struct Flow
{
	int u,v,f,c;
	Flow(int u,int v,int f,int c):u(u),v(v),f(f),c(c){}
};
vector<Flow> G;
vector<int> edges[maxn];
bool bfs()
{
	queue<int> q;
	memset(a,0,sizeof a);
	a[0]=1e8;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<edges[u].size();i++)
		{
			Flow e=G[edges[u][i]];
			int v=e.v;
			if(!a[v]&&e.c>e.f)
			{
				a[v]=min(a[u],e.c-e.f);
				pre[v]=edges[u][i];
				q.push(v);
			}
		}
		if(a[N1+N2+1]) return true;
	}
	return false;
}
void ek()
{
	while(bfs())
	{
		int k=N1+N2+1;
		while(k!=0)
		{
			Flow &e=G[pre[k]];
			Flow &fe=G[pre[k]^1];
			e.f+=a[N1+N2+1];fe.f-=a[N1+N2+1];
			k=e.u;
		}
		ans+=a[N1+N2+1];
	}
}
int main()
{
//	freopen("testdata.in","r",stdin);
//	freopen("11.txt","w",stdout);
	scanf("%d%d%d",&N1,&N2,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(u>N1||v>N2) continue;
		G.push_back(Flow(u,v+N1,0,1));
		edges[u].push_back(cnt++);
		G.push_back(Flow(v+N1,u,1,1));
		edges[v+N1].push_back(cnt++);
	}
	for(int i=1;i<=N1;i++)
	{
		G.push_back(Flow(0,i,0,1));
		edges[0].push_back(cnt++);
		G.push_back(Flow(i,0,1,1));
		edges[i].push_back(cnt++);
	}
	for(int i=N1+1;i<=N1+N2;i++)
	{
		G.push_back(Flow(i,N1+N2+1,0,1));
		edges[i].push_back(cnt++);
		G.push_back(Flow(N1+N2+1,i,1,1));
		edges[N1+N2+1].push_back(cnt++);
	}
	ek();
	printf("%lld\n",ans);

//	system("pause");
}
/*
5 4 8
1 1 
2 1
2 3
3 2
3 3
3 4
4 3
5 3
*/
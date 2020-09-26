#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Flow
{
	int u,v,f,c;
	Flow(int u,int v,int f,int c):u(u),v(v),f(f),c(c){}
};
int Min=1e9,t,pre[10010],ans=0;
int n,m,s,cnt=0;
vector<Flow> G;
vector<int> edges[10010];
bool bfs()
{
	Min=1e9;
	memset(pre,-1,sizeof pre);
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==t) return true;
		for(int i=0;i<edges[u].size();i++)
		{
			Flow &e=G[edges[u][i]];
			if(pre[e.v]==-1&&e.f<e.c)
			{
				Min=min(Min,e.c-e.f);
				pre[e.v]=edges[u][i];
				q.push(e.v);
			}
		}
	}
	return false;
}

int ek()
{
	while(bfs())
	{
		int k=t;
		while(k!=s)
		{
			Flow &e=G[pre[k]];
			Flow &re=G[pre[k]^1];
			e.f+=Min;re.f-=Min;
			k=re.v;
		}
		ans+=Min;
		Min=1e9;
		memset(pre,0,sizeof pre);
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,c;scanf("%d%d%d",&u,&v,&c);
		G.push_back(Flow(u,v,0,c));
		edges[u].push_back(cnt++);
		G.push_back(Flow(v,u,c,c));
		edges[v].push_back(cnt++);
	}
	printf("%d\n",ek());

//	system("pause");

}
/*
4 5 1 4
1 2 8
1 3 3
2 3 1
2 4 6
3 4 5

4 5 1 4
1 2 1
1 3 1
2 3 1
2 4 1
3 4 1

7 7 1 7
1 2 2
1 3 3
2 4 5
3 5 2
4 7 4
4 5 1
5 2 1

*/
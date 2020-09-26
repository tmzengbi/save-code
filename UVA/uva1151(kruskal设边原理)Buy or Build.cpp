#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct Net
{
	int cost;
	vector<int> net;
}s[9];
struct Node
{
	int x,y;
}n[1010];
struct Edge
{
	int u,v,d;
	Edge(){}
	Edge(int u,int v,int d):u(u),v(v),d(d){}
	bool operator < (const Edge E) const
	{
		return d<E.d;
	}
}e[1000010],edge[1010];
int T,N,Q,pre[1010],cnt=0,ans=1e9;
bool used[9];
int findroot(int x)
{
	if(x==pre[x]) return x;
	else pre[x]=findroot(pre[x]);
	return pre[x];
}
void merge(int x,int y)
{
	x=findroot(x);y=findroot(y);
	if(x!=y) pre[x]=y;
}
void getused(int num)
{
	for(int i=0;i<8;i++)
		used[i+1]=(num>>i)&1;
}
void kru(int Index)
{
	int cnt_Edge=0;
	for(int i=1;i<=N;i++) pre[i]=i;
	for(int i=1;i<=Index;i++)
	{
		int u=e[i].u,v=e[i].v;
		u=findroot(u);v=findroot(v);
		if(u!=v)
		{
			merge(u,v);
			edge[++cnt]=e[i];
			cnt_Edge++;
		}
		if(cnt_Edge==N-1) break;
	}
}
void work()
{
	int start=0;
	while(start<(1<<Q))
	{
		int sum=0,cnt_Edge=0;
		getused(start);
		for(int i=1;i<=N;i++)	pre[i]=i;
		for(int i=1;i<=Q;i++)
			if(used[i])
			{
				sum+=s[i].cost;
				for(int j=1;j<s[i].net.size();j++)
				{
					int x=findroot(s[i].net[0]),y=findroot(s[i].net[j]);
					if(x!=y) {merge(x,y);cnt_Edge++;}
				}
			}
		for(int i=1;i<=cnt;i++)
		{
			int x=edge[i].u,y=edge[i].v;
			x=findroot(x);y=findroot(y);
			if(x!=y)
			{
				sum+=edge[i].d;
				merge(x,y);
				cnt_Edge++;
			}
			if(cnt_Edge==N-1) break;
		}
		ans=min(ans,sum);
		start++;
	}
}
int getcost(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;ans=1e9;
		scanf("%d%d",&N,&Q);
		for(int i=1;i<=Q;i++)
		{
			int m,c;
			scanf("%d%d",&m,&c);s[i].cost=c;
			s[i].net.clear();
			for(int j=1;j<=m;j++)
			{
				int node;scanf("%d",&node);
				s[i].net.push_back(node);
			}
		}
		for(int i=1;i<=N;i++)
			scanf("%d%d",&n[i].x,&n[i].y);
		int Index=0;
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)
			{
				int d=getcost(n[i].x,n[i].y,n[j].x,n[j].y);
				e[++Index]=Edge(i,j,d);
			}
		sort(e+1,e+Index+1);
		kru(Index);
		work();
		printf("%d\n",ans);
		if(T)printf("\n");
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=200;
struct Node
{
	int x,y,h;
	Node(){}
	Node(int x,int y,int h):x(x),y(y),h(h){}
	bool operator <(const Node &Q)
	{
		return (x<Q.x)&&(y<Q.y);
	}
}node[maxn];
int Index=0,N,in[maxn],array[maxn],dp[maxn],ans=0,kase=0;
vector<int>edges[maxn];
void toposort()
{
	queue<int>q;
	int tot=0;
	for(int i=1;i<=Index;i++)
		if(in[i]==0) q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		array[++tot]=u;
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
	while(scanf("%d",&N)==1&&N)
	{
		for(int i=1;i<=Index;i++) edges[i].clear();
		Index=0;ans=0;
		memset(dp,0,sizeof dp);
		memset(in,0,sizeof in);
		for(int i=1;i<=N;i++)
		{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			node[++Index]=Node(x,y,z);
			node[++Index]=Node(y,x,z);
			node[++Index]=Node(x,z,y);
			node[++Index]=Node(z,x,y);
			node[++Index]=Node(y,z,x);
			node[++Index]=Node(z,y,x);
		}
		for(int i=1;i<=Index;i++)
			for(int j=1;j<=Index;j++)
				if(node[i]<node[j]){edges[j].push_back(i);in[i]++;}
		toposort();
		for(int i=1;i<=Index;i++) dp[array[i]]=node[array[i]].h;
		for(int i=1;i<=Index;i++)
		{
			int u=array[i];
			for(int j=0;j<edges[u].size();j++)
			{
				int v=edges[u][j];
				dp[v]=max(dp[v],dp[u]+node[v].h);
				ans=max(ans,dp[v]);
			}
		}
		printf("Case %d: maximum height = ",++kase);
		printf("%d\n",ans);
	}
//	system("pause");
}
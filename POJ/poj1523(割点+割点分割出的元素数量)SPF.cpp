#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1010;
int dfn[maxn],low[maxn],cnt=0,subnets[maxn];
bool iscut[maxn];
vector<int>edges[maxn];
vector<int>Node;
void addedge(int u,int v)
{
	edges[u].push_back(v);
	edges[v].push_back(u);
}
void init()
{
	Node.clear();
	cnt=0;
	for(int i=1;i<=1000;i++)
	{
		iscut[i]=false;
		edges[i].clear();
		subnets[i]=dfn[i]=low[i]=0;
	}
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	int child=0;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfn[v])
		{
			child++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u])
			{
				subnets[u]++;
				iscut[u]=true;
			}
		}
		else if(dfn[v]<dfn[u]&&v!=fa)
			low[u]=min(low[u],dfn[v]);
	}
	if(fa==0&&child==1) iscut[u]=false;
	if(fa) subnets[u]++;			//不是父节点 就++
	if(iscut[u]) Node.push_back(u);
}
void work()
{
	for(int i=1;i<=1000;i++)
		if(!dfn[i]) tarjan(i,0);
	sort(Node.begin(),Node.end());
	for(int i=0;i<Node.size();i++)
	{
		int u=Node[i];
		printf("  SPF node %d leaves %d subnets\n",u,subnets[u]);
	}
	if(Node.size()==0) printf("  No SPF nodes\n");
	printf("\n");
}
int main()
{
	int Cas=1;
	while(true)
	{
		bool input=false;	
		init();
		int u,v;
		while(scanf("%d",&u)==1&&u)
		{
			input=true;
			scanf("%d",&v);
			addedge(u,v);
		}
		if(!input) break;
		printf("Network #%d\n",Cas++);
		work();
	}
}
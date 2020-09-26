#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
struct Node
{
	int u,dep;
	Node(int u,int dep):u(u),dep(dep){}
	bool operator < (const Node AA)const
	{
		return dep>AA.dep;
	}
};
vector<int>edges[200010];
priority_queue<Node>q;
int deep[200010],num[200010];
bool vis[200010];
int bfs()
{
	while(!q.empty())
	{
		Node e=q.top();q.pop();
		int u=e.u;
		vis[u]=false;
		for(int i=0;i<edges[u].size();i++)
		{
			int v=edges[u][i];
			if(deep[v]==0||deep[v]==deep[u]+1)
			{
				num[v]+=num[u];
				deep[v]=deep[u]+1;
				if(num[v]==m) return v;
				if(!vis[v])
				{
					vis[v]=true;
					q.push(Node(v,deep[v]));
				}
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("YES\n1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		int key;scanf("%d",&key);
		q.push(Node(key,1));
		vis[key]=true;
		deep[key]=1;
		num[key]=1;
	}
	int ans=bfs();
	if(ans)	printf("YES\n%d\n",ans);
	else printf("NO\n");

//	system("pause");
}
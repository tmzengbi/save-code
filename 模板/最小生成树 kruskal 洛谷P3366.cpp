#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pre[5010],N,M;
struct Node
{
	int u,v,d;
	bool operator < (const Node E) const
	{
		return d<E.d;
	}
}e[200000];
int findRoot(int root)
{
	if(root==pre[root]) return root;
	else pre[root]=findRoot(pre[root]);
	return pre[root];
}
int work()
{
	for(int i=1;i<=N;i++) pre[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=M;i++)
	{
		int u=e[i].u,v=e[i].v,root1=findRoot(u),root2=findRoot(v);
		if(root1!=root2)
		{
			pre[root1]=root2;
			cnt++;ans+=e[i].d;
		}
	}
	if(cnt==N-1) return ans;
	else return -1;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
	sort(e+1,e+M+1);
	int ans=work();
	if(ans==-1)	printf("orz\n");
	else printf("%d\n",ans);

//	system("pause");
}
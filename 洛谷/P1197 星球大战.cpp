#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
vector<int> edges[400010];
vector<int>	ans;
stack<int> del;
int pre[4000010],size[4000010],sum=0;
bool des[4000010];
int find_root(int root)
{
	int son=root;
	while(root!=pre[root])
		root=pre[root];
	while(son!=root)
	{
		int tmp=pre[son];
		pre[son]=root;
		son=tmp;
	}
	return root;
}
bool add_root(int r1,int r2)
{
	int root1=find_root(r1),root2=find_root(r2);
	if(root1==root2)	return false;
	if(size[root1]>size[root2])	swap(root1,root2);
	pre[root1]=root2;
	size[root2]+=size[root1];
	return true;
}
void addnode(int root)
{
	for(int i=0;i<edges[root].size();i++)
	{
		int v=edges[root][i];
		if(!des[v])
			if(add_root(root,v)	) sum++;
	}
}
int main()
{
	memset(des,0,sizeof des);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		pre[i]=i;
		size[i]=1;
	}
	for(int i=1;i<=M;i++)
	{
		int e1,e2;
		scanf("%d%d",&e1,&e2);
		edges[e1].push_back(e2);
		edges[e2].push_back(e1);
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		del.push(tmp);
		des[tmp]=true;
	}
	for(int i=0;i<N;i++)
	{
		if(!des[i])
			addnode(i);
	}
	ans.push_back(N-k-sum);
	k--;
	while(!del.empty())
	{
		int d=del.top();
		des[d]=false;
		del.pop();
		addnode(d);
		ans.push_back(N-k-sum);
		k--;
	}
	int len=ans.size();
	for(int i=len-1;i>=0;i--)
		cout<<ans[i]<<endl;
}

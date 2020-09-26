#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=500010;
int tree[maxn<<1],M,N;
int lowbit(int x)
{
	return x&-x;
}
void update(int s,int v)
{
	for(;s<=N;s+=lowbit(s))
		tree[s]+=v;
}
int query(int s)
{
	int ans=0;
	for(;s;s-=lowbit(s))
		ans+=tree[s];
	return ans;
}
int main()
{
	memset(tree,0,sizeof tree);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		int x;scanf("%d",&x);
		update(i,x);
	}
	while(M--)
	{
		int m,x,y;
		scanf("%d%d%d",&m,&x,&y);
		if(m==1) update(x,y);
		else if(m==2) printf("%d\n",query(y)-query(x-1));
	}
}
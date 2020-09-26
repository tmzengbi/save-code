#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=500010;
int n,tree[maxn<<1];
ll ans=0;
struct Node
{
	int a,rank,c;
}t[maxn];
bool cmp1(Node n1,Node n2)
{
	return n1.a>n2.a;
}
bool cmp2(Node n1,Node n2)
{
	return n1.c<n2.c;
}
int lowbit(int b)
{
	return b&(-b);
}
void add(int d)
{
	for(int i=d;i<=n;i=i+lowbit(i))
		tree[i]++;
}
int query(int d)
{
	int sum=0;
	while(d)
	{
		sum+=tree[d];
		d=d-lowbit(d);
	}
	return sum;
}


int main()
{
	memset(tree,0,sizeof tree);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i].a);
		t[i].c=i;
	}
	sort(t+1,t+n+1,cmp1);
	int Index=1;t[1].rank=1;
	for(int i=2;i<=n;i++)
	{
		if(t[i].a==t[i-1].a)	t[i].rank=Index;
		else t[i].rank=++Index;
	}
	sort(t+1,t+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		ans+=query(t[i].rank-1);
		add(t[i].rank);
	}
	printf("%lld\n",ans);




//	system("pause");
}
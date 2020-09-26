#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tree[1000010],a[500010],n,m;
int lowbit(int k)
{
	return k&(-k);
}
void add(int i,int v)
{
	while(i<=n)
	{
		tree[i]+=v;
		i=i+lowbit(i);
	}
}
int query(int q)
{
	int ans=0;
	while(q)
	{
		ans+=tree[q];
		q=q-lowbit(q);
	}
	return ans;
	
}
int main()
{
	scanf("%d%d",&n,&m);
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(i,a[i]-a[i-1]);
	}
	while(m--)
	{
		int mod,x,y,k;
		scanf("%d%d",&mod,&x);
		if(mod==1)
		{
			scanf("%d%d",&y,&k);
			add(x,k);
			add(y+1,-k);
		}
		else if(mod==2)
		{
			cout<<query(x)<<endl;
		}
	}
}

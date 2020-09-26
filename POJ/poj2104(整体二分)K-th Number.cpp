#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxn=1e5+10;
int n,m,t[maxn];
inline int lowbit(int x){return x&-x;}
void add(int x,int s)
{
	for(;x<=n;x+=lowbit(x)) t[x]+=s;
}
int query(int x)
{
	int sum=0;
	for(;x;x-=lowbit(x)) sum+=t[x];
	return sum;
}
struct Node
{
	int qy,l,r,k,pos;
}q[maxn<<1],q1[maxn<<1],q2[maxn<<1];
int ans[maxn];
void divide(int l,int r,int L,int R)
{
	if(l>r||L>R) return;
	if(l==r)
	{
		for(int i=L;i<=R;i++)
			if(q[i].qy) ans[q[i].pos]=l;
		return;
	}
	int mid=l+r>>1,cnt1=0,cnt2=0;
	for(int i=L;i<=R;i++)
	{
		if(q[i].qy)
		{
			int tmp=query(q[i].r)-query(q[i].l-1);
			if(q[i].k<=tmp) q1[++cnt1]=q[i];
			else q[i].k-=tmp,q2[++cnt2]=q[i];
		}
		else
		{
			if(q[i].l<=mid){add(q[i].pos,1);q1[++cnt1]=q[i];}
			else q2[++cnt2]=q[i];
		}
	}
	for(int i=1;i<=cnt1;i++) if(!q1[i].qy) add(q1[i].pos,-1);
	for(int i=1;i<=cnt1;i++) q[L+i-1]=q1[i];
	for(int i=1;i<=cnt2;i++) q[L+cnt1+i-1]=q2[i];
	divide(l,mid,L,L+cnt1-1);divide(mid+1,r,L+cnt1,R);
}
int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int num;scanf("%d",&num);
		q[++cnt]=(Node){0,num,0,0,i};
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		q[++cnt]=(Node){1,l,r,k,i};
	}
	const int inf=1e9;
	divide(-inf,inf,1,cnt);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
//	system("pause");
}
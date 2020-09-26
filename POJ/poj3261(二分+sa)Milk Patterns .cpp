#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxn=20000*2+10;
int N,K,sa[maxn],height[maxn],t[maxn],t1[maxn],M,rk[maxn],b[maxn],c[maxn];
struct Node
{
	int v,id;
}a[maxn];
bool cmp1(Node &n1,Node &n2)
{
	return n1.v<n2.v;
}
bool cmp2(Node &n1,Node &n2)
{
	return n1.id<n2.id;
}
void getsa()
{
	int *x=t,*y=t1;
	memset(sa,0,sizeof sa);
	for(int i=1;i<=M;i++) c[i]=0;
	for(int i=1;i<=N;i++) c[x[i]=b[i]]++;
	for(int i=2;i<=M;i++) c[i]+=c[i-1];
	for(int i=N;i>=1;i--) sa[c[x[i]]--]=i;
	for(int k=1;k<=N;k<<=1)
	{
		int p=0;
		for(int i=N-k+1;i<=N;i++) y[++p]=i;
		for(int i=1;i<=N;i++) if(sa[i]>k) y[++p]=sa[i]-k;
		for(int i=1;i<=M;i++) c[i]=0;
		for(int i=1;i<=N;i++) c[x[y[i]]]++;
		for(int i=2;i<=M;i++) c[i]+=c[i-1];
		for(int i=N;i>=1;i--) sa[c[x[y[i]]]--]=y[i];
		swap(x,y);
		x[sa[1]]=1;p=1;
		for(int i=2;i<=N;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p:++p;
		if(p>=N) break;
		M=p;
	}
	int p=0;
	for(int i=1;i<=N;i++)
	{
		if(p)p--;
		if(x[i]==1){height[x[i]]=p=0;continue;}
		while(b[i+p]==b[sa[x[i]-1]+p])p++;
		height[x[i]]=p;
	}
}
bool check(int k)
{
	int i=1,sum=0;
	while(i<=N)
	{
		sum=1;i++;
		for(;i<=N;i++)
		{
			if(height[i]<k) break;
			sum++;
		}
		if(sum>=K) return true;
	}
	return false;
}
int main()
{
	while(scanf("%d%d",&N,&K)==2)
	{
		for(int i=1;i<=N;i++){scanf("%d",&a[i].v);a[i].id=i;}
		sort(a+1,a+N+1,cmp1);
		for(int i=1;i<=N;i++) rk[i]=a[i].id;
		sort(a+1,a+N+1,cmp2);
		int cnt=1;b[rk[1]]=1;
		for(int i=2;i<=N;i++) b[rk[i]]=a[rk[i]].v==a[rk[i-1]].v?cnt:++cnt;
		M=cnt;
		getsa();
		int l=0,r=N+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l-1);
	}
}
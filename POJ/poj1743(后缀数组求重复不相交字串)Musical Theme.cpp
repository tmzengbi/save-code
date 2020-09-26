#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=40010;
int t[maxn],t1[maxn],a[maxn],sa[maxn],rank[maxn],height[maxn],N,M,c[maxn];
void getsuffix()
{
	memset(sa,0,sizeof sa);
	M=88*2;
	int *x=t,*y=t1;
	for(int i=1;i<=M;i++) c[i]=0;
	for(int i=1;i<=N;i++) c[x[i]=a[i]]++;
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
		p=1;x[sa[1]]=1;
		for(int i=2;i<=N;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p:++p;
		if(p>=N) break;
		M=p;
	}
	int p=0;
	for(int i=1;i<=N;i++)
	{
		rank[i]=x[i];
		if(p)p--;
		if(x[i]==1) {height[x[i]]=p=0;continue;}
		while(a[i+p]==a[sa[x[i]-1]+p]) p++;
		height[x[i]]=p;
	}
//	for(int i=1;i<=N;i++) printf("%d ",height[i]);puts("");
}
bool check(int k)
{
	int Max,Min;
	int i=1;
	while(i<=N)
	{
		Max=Min=sa[i++];
		for(;i<=N;i++)
		{
			if(height[i]<k) break;
			Max=max(Max,sa[i]);
			Min=min(Min,sa[i]);
//			printf("%d %d\n",Min,Max);
			if(Max-Min>k) return true;
		}
	}
	return false;
}
int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		int t=1e5;
		for(int i=N;i>=2;i--){a[i]-=a[i-1];t=min(t,a[i]);}
		for(int i=2;i<=N;i++) a[i]=a[i]-t+1;
		for(int i=1;i<=N;i++) a[i]=a[i+1];
		N--;
		getsuffix();
		int l=0,r=N;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
//			printf("%d %d\n",l,r);
//			system("pause");
		}
		if(l>=5) printf("%d\n",l);
		else printf("0\n");
	}
}
/*
8
1 1 2 1 1 1 1 2

90
25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18
82 78 74 70 66 67 64 60 65 80 25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18 
82 78 74 70 66 67 64 60 65 80 25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18 
82 78 74 70 66 67 64 60 65 80
*/
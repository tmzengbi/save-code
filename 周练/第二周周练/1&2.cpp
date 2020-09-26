#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[100010],b[100010];
long long ans=0;
void submerge(int l,int r)
{
	int mid=(l+r)>>1,s=l,e=mid+1,Index=l;
	while(s<=mid&&e<=r)
		if(a[s]<=a[e]) b[Index++]=a[s++];
		else {ans+=e-Index;b[Index++]=a[e++];}
	while(s<=mid)	b[Index++]=a[s++];
	while(e<=r) b[Index++]=a[e++];
	for(int i=l;i<=r;i++) a[i]=b[i];
}
void merge(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	submerge(l,r);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	merge(1,n);
	printf("%lld\n",ans);
}
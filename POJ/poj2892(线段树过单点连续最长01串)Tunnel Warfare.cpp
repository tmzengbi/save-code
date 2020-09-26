#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=50010;
int inf;
int minv[maxn<<2],maxv[maxn<<2],a[maxn];
void pushup(int o)
{
	minv[o]=min(minv[o<<1],minv[o<<1|1]);
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}
void build(int o,int l,int r)
{
	minv[o]=inf;maxv[o]=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
}
void update(int o,int l,int r,int q,int v)
{
	if(l==r)
	{
		minv[o]=v;
		if(!v) maxv[o]=minv[o]=l;
		else{maxv[o]=0;minv[o]=inf;}
		return;
	}
	int mid=l+r>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
	pushup(o);
}
int queryright(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return maxv[o];
	int mid=l+r>>1,ans=0;
	if(ql<=mid) ans=max(ans,queryright(o<<1,l,mid,ql,qr));
	if(mid<qr) ans=max(ans,queryright(o<<1|1,mid+1,r,ql,qr));
	return ans;
}
int queryleft(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return minv[o];
	int mid=l+r>>1,ans=inf;
	if(ql<=mid) ans=min(ans,queryleft(o<<1,l,mid,ql,qr));
	if(mid<qr) ans=min(ans,queryleft(o<<1|1,mid+1,r,ql,qr));
	return ans;
}
int s[maxn],Index=0;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	inf=n+1;
	for(int i=1;i<=n;i++) a[i]=1;
	build(1,1,n);
	while(m--)
	{
		char ss[5];int k;
		scanf("%s",ss);
		if(ss[0]=='D')
		{
			scanf("%d",&k);
			update(1,1,n,k,0);
			a[k]=0;
			s[Index++]=k;
		}
		if(ss[0]=='Q')
		{
			scanf("%d",&k);
			if(!a[k]){printf("0\n");continue;}
			int l=queryright(1,1,n,1,k);
			int r=queryleft(1,1,n,k,n);
			printf("%d\n",r-l-1);
		}
		if(ss[0]=='R')
		{
			int r=s[--Index];
			update(1,1,n,r,1);
			a[r]=1;
		}
	}
//	system("pause");
}
 #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
int n,a[maxn];
struct segment{
	int mx[maxn<<2],opt;
	inline int cmp(int x,int y){
		return opt?max(x,y):min(x,y);
	}
	void build(int o,int l,int r,int *a){
		if(l==r){
			mx[o]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(o<<1,l,mid,a);build(o<<1|1,mid+1,r,a);
		mx[o]=cmp(mx[o<<1],mx[o<<1|1]);
	}
	int query(int o,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			return mx[o];
		}
		int mid=(l+r)>>1;
		if(ql<=mid&&mid<qr) return cmp(query(o<<1,l,mid,ql,qr),query(o<<1|1,mid+1,r,ql,qr));
		if(ql<=mid) return query(o<<1,l,mid,ql,qr);
		if(mid<qr) return query(o<<1|1,mid+1,r,ql,qr); 
		return 0;
	}
}minv[20],maxv[20];
int l[20][maxn],r[20][maxn];
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=n+1;i<=n*3;++i)
		a[i]=a[i-n];
	for(int i=1;i<=n*3;++i){
		l[0][i]=max(1,i-a[i]);
		r[0][i]=min(n*3,i+a[i]);
	}
	for(int i=1;i<20;++i){
		minv[i-1].opt=0;maxv[i-1].opt=1;
		minv[i-1].build(1,1,n*3,l[i-1]);maxv[i-1].build(1,1,n*3,r[i-1]);
		for(int j=1;j<=n*3;++j){
			l[i][j]=minv[i-1].query(1,1,n*3,l[i-1][j],r[i-1][j]);
			r[i][j]=maxv[i-1].query(1,1,n*3,l[i-1][j],r[i-1][j]);
		}
	}
	minv[19].opt=0;maxv[19].opt=1;
	minv[19].build(1,1,n*3,l[19]);maxv[19].build(1,1,n*3,r[19]);
	for(int i=n+1;i<=n*2;++i){
		int ans=0,L=i,R=i;
		for(int j=19;j>=0;--j){
			int ql=minv[j].query(1,1,n*3,L,R),qr=maxv[j].query(1,1,n*3,L,R);
			if(qr-ql+1<n){
				L=ql;R=qr;
				ans+=(1<<j);
			}
		}
		printf("%d ",ans+1);
	}
}
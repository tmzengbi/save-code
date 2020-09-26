#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxm=2e5+10;
int n,k;
struct Node{
	int s,c,m,id,cnt;
	bool operator < (const Node &rhs)const{
		if(s^rhs.s) return s<rhs.s;
		if(c^rhs.c) return c<rhs.c;
		if(m^rhs.m) return m<rhs.m;
		return 0;
	}
}a[maxn],p[maxn];
bool cmp(const Node&r1,const Node&r2){
	return r1.id<r2.id;
}
int t[maxm];
inline int lowbit(int x){return x&-x;}
void update(int x,int v){
	for(;x<=k;x+=lowbit(x)) t[x]+=v;
}
int query(int x){
	int sum=0;
	for(;x;x-=lowbit(x)) sum+=t[x];
	return sum;
}
int ans[maxn],sum[maxn];
int b[maxn],c[maxn];
void cdq(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid);cdq(mid+1,r);
	int le=l,ri=mid+1,Index=l;
	while(le<=mid&&ri<=r){
		if(p[b[le]].c<=p[b[ri]].c){
			update(p[b[le]].m,p[b[le]].cnt);
			c[Index++]=b[le++];
		} else {
			ans[p[b[ri]].id]+=query(p[b[ri]].m);
			c[Index++]=b[ri++];
		}
	}
	while(le<=mid){
		update(p[b[le]].m,p[b[le]].cnt);
		c[Index++]=b[le++];
	}
	while(ri<=r){
		ans[p[b[ri]].id]+=query(p[b[ri]].m);
		c[Index++]=b[ri++];
	}
	for(int i=l;i<=mid;++i)
		update(p[b[i]].m,-p[b[i]].cnt);
	for(int i=l;i<=r;++i)
		b[i]=c[i];
}
int main(){
	scanf("%d%d",&n,&k);
	const int N=n;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].s,&a[i].c,&a[i].m);
	}
	sort(a+1,a+n+1);
	n=0;
	for(int i=1;i<=N;++i){
		if(a[i].s!=a[i-1].s||a[i].c!=a[i-1].c||a[i].m!=a[i-1].m){
			p[++n]=a[i];p[n].cnt=1;
		} else {
			++p[n].cnt;
		}
	}
	for(int i=1;i<=n;++i) p[i].id=b[i]=i;
	cdq(1,n);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i){
//		printf("%d\n",ans[i]);
//		cout<<ans[i]+p[i].cnt-1<<" ";
		sum[ans[i]+p[i].cnt-1]+=p[i].cnt;
	}
	for(int i=0;i<N;++i)
		printf("%d\n",sum[i]);
}
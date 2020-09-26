#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Node{
	int l,r,h,opt;
	Node(){}
	Node(int l,int r,int h,int opt):l(l),r(r),h(h),opt(opt){}
	bool operator<(const Node&rhs){
		return h<rhs.h;
	}
}p[maxn<<1];
int n;
int x[maxn<<1],y[maxn<<1],cnt[2];
int len[3][maxn<<3];int tag[maxn<<3];
//len 0->偶数	1->奇数		2->所有数 
void pushup(int o,int l,int r){
	if(l==r){
		if(tag[o]) len[2][o]=x[r+1]-x[r];
		else len[2][o]=0;
		len[tag[o]&1][o]=x[r+1]-x[r];
		len[(tag[o]&1)^1][o]=0;
		return;
	}
	if(tag[o]){
		len[2][o]=x[r+1]-x[l];
	} else {
		len[2][o]=len[2][o<<1]+len[2][o<<1|1];
	}
	if(tag[o]&1){
		len[1][o]=len[0][o<<1]+len[0][o<<1|1];
		len[0][o]=len[1][o<<1]+len[1][o<<1|1];
	} else {
		len[1][o]=len[1][o<<1]+len[1][o<<1|1];
		len[0][o]=len[0][o<<1]+len[0][o<<1|1];
	}
}
void build(int o,int l,int r){
	if(l==r){
		len[0][o]=x[l+1]-x[l];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	pushup(o,l,r);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr){
		tag[o]+=v;pushup(o,l,r);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,v);
	if(qr>mid) update(o<<1|1,mid+1,r,ql,qr,v);
	pushup(o,l,r);
}
int at(int xx){
	return lower_bound(x+1,x+cnt[0]+1,xx)-x;
}
int main(){
	#ifdef DEBUG
	
//		freopen("a.in","r",stdin);
//		freopen("a11.out","w",stdout);
		
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x11,y11,x22,y22;scanf("%d%d%d%d",&x11,&y11,&x22,&y22);
		if(x11==x22||y11==y22) continue;
		if(x11>x22) swap(x11,x22);
		if(y11>y22) swap(y11,y22);
		p[++cnt[1]]=Node(x11,x22,y11,1);
		p[++cnt[1]]=Node(x11,x22,y22,-1);
		x[++cnt[0]]=x11;x[++cnt[0]]=x22;
	}
	if(cnt[0]==0){
		puts("0");
		return 0;
	}
	sort(x+1,x+cnt[0]+1);
	cnt[0]=unique(x+1,x+cnt[0]+1)-x-1;
	sort(p+1,p+cnt[1]+1);
	build(1,1,cnt[0]-1);
	ll ans1=0,ans2=0;
	for(int i=1;i<cnt[1];++i){
		int l=p[i].l,r=p[i].r,h=p[i+1].h-p[i].h;
		l=at(l);r=at(r);--r;
		update(1,1,cnt[0]-1,l,r,p[i].opt);
		ans1+=1LL*len[2][1]*h;
		ans2+=1LL*len[1][1]*h;
	}
	printf("%lld\n",ans1-ans2);
}
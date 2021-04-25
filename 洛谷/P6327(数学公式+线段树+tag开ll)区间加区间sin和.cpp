/*
    把int类型的tag改为ll时，
    除了修改tag的类型外，一定要记得修改addtag函数的参数类型
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;
double s[maxn<<2],c[maxn<<2];
int n,m;
ll tag[maxn<<2];
int a[maxn];
inline void up(int o) {
	s[o]=s[o<<1]+s[o<<1|1];
	c[o]=c[o<<1]+c[o<<1|1];
}
void build(int o,int l,int r) {
	if(l==r) {
		s[o]=sin(a[l]);
		c[o]=cos(a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	up(o);
}
void addtag(int o,ll x) { 	// sin(a+x)=sin(a)cos(x)+sin(x)cos(a);
							// cos(a+x)=cos(a)cos(x)-sin(a)sin(x);
	double sina=s[o],cosa=c[o];
	double cosx=cos(x),sinx=sin(x);
	s[o]=sina*cosx+cosa*sinx;
	c[o]=cosa*cosx-sina*sinx;
	tag[o]+=x;
}
void pushdown(int o) {
	if(!tag[o]) return;
	addtag(o<<1,tag[o]);
	addtag(o<<1|1,tag[o]);
	tag[o]=0;
}
void update(int o,int l,int r,int ql,int qr,int x) {
	if(ql<=l&&r<=qr) {
		addtag(o,x);
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if(ql<=mid) update(o<<1,l,mid,ql,qr,x);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,x);
	up(o);
}
double query(int o,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) return s[o];
	double res=0;
	int mid=(l+r)>>1;
	pushdown(o);
	if(ql<=mid) res+=query(o<<1,l,mid,ql,qr);
	if(mid<qr) res+=query(o<<1|1,mid+1,r,ql,qr);
	return res;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--) {
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		if(opt==1) {
			int v;scanf("%d",&v);
			update(1,1,n,l,r,v);
		} else {
			double res=query(1,1,n,l,r);
			printf("%.1lf\n",res);
		}
	}
}
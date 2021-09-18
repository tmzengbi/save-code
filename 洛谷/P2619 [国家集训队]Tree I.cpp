#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,d;
struct Node {
	int u,v;
	double d;
	bool operator < (const Node &rhs) const {
		return d<rhs.d;
	}
}a[maxn],b[maxn];
int siz[2];
int f[maxn];
int find(int x) {
	return x==f[x]?x:(f[x]=find(f[x]));
}
void merge(int x,int y) {
	x=find(x);y=find(y);
	f[x]=y;
}
double sum;
int res;
void solve(double x) {
	for(int i=0;i<=n;++i) f[i]=i;
	for(int i=1;i<=siz[0];++i) a[i].d-=x;
	int tot=0;
	res=sum=0;
	int cnt[2]={1,1};
	while(tot<n-1) {
		if(cnt[0]>siz[0]) {
			int u=b[cnt[1]].u,v=b[cnt[1]].v;
			if(find(u)!=find(v)) {
				merge(u,v);
				++tot;sum+=b[cnt[1]].d;
			}
			++cnt[1];
		} else if(cnt[1]>siz[1]) {
			int u=a[cnt[0]].u,v=a[cnt[0]].v;
			if(find(u)!=find(v)) {
				merge(u,v);
				++tot;sum+=a[cnt[0]].d;
				++res;
			}
			++cnt[0];
		} else {
			if(b[cnt[1]].d<=a[cnt[0]].d) {
				int u=b[cnt[1]].u,v=b[cnt[1]].v; 
				if(find(u)!=find(v)) {
					merge(u,v);
					++tot;sum+=b[cnt[1]].d;
				}
				++cnt[1];
			} else {
				int u=a[cnt[0]].u,v=a[cnt[0]].v;
				if(find(u)!=find(v)) {
					merge(u,v);
					++tot;sum+=a[cnt[0]].d;
					++res;
				}
				++cnt[0];
			}
		}
	}
	for(int i=1;i<=siz[0];++i) a[i].d+=x;
}
const double eps=1e-6;
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;++i) {
		int u,v,c,col;
		scanf("%d%d%d%d",&u,&v,&c,&col);
		if(!col) a[++siz[0]]=(Node){u,v,1.0*c};
		else b[++siz[1]]=(Node){u,v,1.0*c};
	}
	sort(a+1,a+siz[0]+1);
	sort(b+1,b+siz[1]+1);
	double l=-1e11,r=1e11;
	while((r-l)>eps) {
		double mid=(l+r)/2;
		solve(mid);
		// if(res==d) {l=mid;break;}
		if(res>=d) r=mid;
		else l=mid;
	}
	printf("%lld\n",(ll)(sum+l*d+0.49));
}
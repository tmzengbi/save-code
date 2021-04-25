#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=5e5+10;
int t,m,n,cur[maxn][31],c[maxn][31];
void insert(int *c,int *cur,int x,int cr) {
	for(int i=30;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(c[i]) {
			if(cr>cur[i]) {
				swap(cur[i],cr);
				swap(x,c[i]);
			}
			x^=c[i];
		} else {
			c[i]=x;
			cur[i]=cr;
			break;
		}
	}
}
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		int las=0;
		for(int i=1;i<=n;++i) {
			int x;scanf("%d",&x);
			memcpy(c[i],c[i-1],sizeof(c[i]));
			memcpy(cur[i],cur[i-1],sizeof(cur[i]));
			insert(c[i],cur[i],x,i);
		}
		for(int i=1;i<=m;++i) {
			int opt;
			int l,r,x;
			scanf("%d",&opt);
			if(opt==0) {
				scanf("%d%d",&l,&r);
				l=(l^las)%n+1;r=(r^las)%n+1;
				if(l>r) swap(l,r);
				int res=0;
				for(int j=30;j>=0;--j) {
					if(cur[r][j]<l) continue;
					if((res^c[r][j])>res) res^=c[r][j];
				}
				printf("%d\n",las=res);
			} else {
				scanf("%d",&x);
				x^=las;++n;
				memcpy(c[n],c[n-1],sizeof(c[n]));
				memcpy(cur[n],cur[n-1],sizeof(cur[n]));
				insert(c[n],cur[n],x,n);
			}
		}
	}
}
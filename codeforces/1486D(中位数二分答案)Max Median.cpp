#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],n,k,c[maxn],s[maxn];
bool check(int x) {
	for(int i=1;i<=n;++i){
		c[i]=(a[i]<x)?-1:1;
		s[i]=s[i-1]+c[i];
	}
	int mn=0;
	for(int i=k;i<=n;++i) {
		if(s[i]-mn>0) return true;
		mn=min(mn,s[i-k+1]);
	}
	return false;
}
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int l=1,r=n+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l-1);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int n,L;
const ll inf=1LL<<55;
int c[maxn];
ll s[maxn];
ll sta[maxn],go[maxn],idx;
ll dp[maxn];
ll calc(int i,int j) {
	return 1LL*(j-i+s[j]-s[i-1]-L)*(j-i+s[j]-s[i-1]-L);
}
ll w(int i,int j) {
	if(i>=j) return inf;
	return dp[i]+calc(i+1,j);
}
int solve(int x) {
	int l=sta[idx],r=n+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(w(go[idx],mid)<=w(x,mid)) l=mid+1;
		else r=mid;
	}
	return l;
}
// int from[maxn];
int main() {
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;++i) {
		scanf("%d",&c[i]);
		s[i]=s[i-1]+c[i];
	}
	sta[++idx]=1;
	go[idx]=0;
	int k=1;
	for(int i=1;i<=n;++i) {
		if(i==sta[k+1]) ++k;
		dp[i]=w(go[k],i);
		// from[i]=go[k];
		while(i<sta[idx]&&w(i,sta[idx])<w(go[idx],sta[idx])) --idx;
		int x=solve(i);
		if(x<=n) {
			sta[++idx]=x;
			go[idx]=i;
		}
	}
	// for(int i=1;i<=n;++i)
	// 	cout<<i<<" "<<from[i]<<endl;
	printf("%lld\n",dp[n]);
}
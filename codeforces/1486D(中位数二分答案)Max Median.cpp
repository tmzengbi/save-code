#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],n,k,c[maxn],s[maxn];
bool check(int x) {
	for(int i=1;i<=n;++i){
		c[i]=(a[i]<x);
		s[i]=s[i-1]+c[i];
	}
	int l=1,cnt=0;
	for(int i=1;i<k;++i)
		cnt+=c[i];
	for(int i=k;i<=n;++i) {
		cnt+=c[i];
		while(i-l>=k&&c[l]==1)
			cnt-=c[l++];
		if(i-k>l&&(i-k-l+1)%2==0&&s[i-k]-s[l-1]==(i-k-l+1)/2){
			while(l<i-k+1)
				cnt-=c[l++];
		}
		if(cnt<=(i-l)/2) return true;
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
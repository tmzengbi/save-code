#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn],b[maxn],mp[maxn],cnt[maxn],mx=0;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		b[i]=mp[b[i]];
	}
	for(int i=1;i<=n;++i){
		if(b[i]>cnt[mx]) {
			cnt[++mx]=b[i];
		} else {
			int l=1,r=mx;
			while(l<r) {
				int mid=(l+r)>>1;
				if(cnt[mid]<=b[i]) l=mid+1;
				else r=mid;
			}
			cnt[l]=b[i];
		}
	}
	printf("%d\n",mx);
}
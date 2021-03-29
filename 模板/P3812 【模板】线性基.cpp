#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=55;
const int P=1e9+7;
ll a[maxn],b[maxn];
int n;
void insert(ll x) {
	for(int i=50;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(b[i]) {
			x^=b[i];
		} else {
			for(int j=i-1;j>=0;--j)
				if((x>>j)&1) x^=b[j];
			for(int j=i+1;j<=50;++j)
				if((b[j]>>i)&1) b[j]^=x;
			b[i]=x;
			return;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		insert(a[i]);
	}
	ll res=0;
	for(int i=0;i<=50;++i)
		res^=b[i];
	printf("%lld\n",res);
}

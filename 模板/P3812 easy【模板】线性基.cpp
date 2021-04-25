#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
ll a[55];
void insert(ll x) {
	for(int i=50;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(a[i]) {
			x^=a[i];
		} else {
			a[i]=x;
			break;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		ll x;
		scanf("%lld",&x);
		insert(x);
	}
	ll res=0;
	for(int i=50;i>=0;--i) {
		if((res^a[i])>res) res^=a[i];
	}
	printf("%lld\n",res);

}
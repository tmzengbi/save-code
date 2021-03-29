#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=65;
ll b[maxn];
vector<int>p;
void insert(ll &x) {
	for(int i=62;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(b[i]){
			x^=b[i];
		} else {
			for(int j=0;j<i;++j)
				if((x>>j)&1) x^=b[j];
			for(int j=63;j>i;--j)
				if((b[j]>>i)&1) b[j]^=x;
			b[i]=x;
			return;
		}
	}
}
int t,n,q;
int main() {
	scanf("%d",&t);
	int cas=0;
	while(t--) {
		memset(b,0,sizeof b);
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			ll x;scanf("%lld",&x);
			insert(x);
		}
		printf("Case #%d:\n",++cas);
		p.clear();
		for(int i=0;i<=63;++i)
			if(b[i]) p.push_back(b[i]);
		ll lim=(1LL<<p.size())-1;
		scanf("%d",&q);
		while(q--) {
			ll x;scanf("%lld",&x);
			if(p.size()!=n) --x;
			if(x>lim) {
				puts("-1");
			} else {
				ll res=0;
				for(int i=0;i<p.size();++i)
					if((x>>i)&1) res^=p[i];
				printf("%lld\n",res);
			}
		}
	}
}
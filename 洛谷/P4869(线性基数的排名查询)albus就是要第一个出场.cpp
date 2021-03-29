#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=44;
const int P=10086;
int n,a,b[44],cnt=0;
vector<int>p;
void insert(int x) {
	for(int i=30;i>=0;--i) {
		if(!((x>>i)&1)) continue;
		if(b[i]){
			x^=b[i];
		} else {
			for(int j=0;j<i;++j)
				if((x>>j)&1) x^=b[j];
			for(int j=i+1;j<=30;++j)
				if((b[j]>>i)&1) b[j]^=x;
			b[i]=x;
			++cnt;
			return;
		}
	}
}
ll Pow(ll a,ll b) {
	ll sum=1;
	for(;b;b>>=1) {
		if(b&1) sum=sum*a%P;
		if(b) a=a*a%P;
	}
	return sum;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		insert(x);
	}
	scanf("%d",&a);
	int xx=0;
	for(int i=0;i<=30;++i)
		if(b[i]) p.push_back(i);
	for(int i=0;i<p.size();++i)
		if((a>>p[i])&1) xx|=(1<<i);
	printf("%lld\n",(1LL*xx*Pow(2,n-cnt)%P+1)%P);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int P=998244353;
ll Pow(ll a,ll b) {
	ll sum=1;
	for(;b;b>>=1) {
		if(b&1) sum=sum*a%P;
		if(b) a=a*a%P;
	}
	return sum;
}
ll inv(ll x){
	return Pow(x,P-2);
}
int n,k;
struct Node{
	int x,y;
}p[maxn];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	ll res=0;
	for(int i=1;i<=n;++i) {
		ll fm=1,fz=1;
		for(int j=1;j<=n;++j) {
			if(i==j) continue;
			fz=fz*(k-p[j].x)%P;
			fm=fm*(p[i].x-p[j].x)%P;
		}
		fz+=P;
		fz%=P;
		fm+=P;
		fm%=P;
		res+=fz*inv(fm)%P*p[i].y%P;
		res%=P;
	}
	printf("%lld\n",res);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<17)+10;
const int P=998244353;
int n;
ll a[maxn],b[maxn];
ll aa[maxn],bb[maxn];
ll Pow(ll a,ll b) {
	ll sum=1;
	for(;b;b>>=1) {
		if(b&1) sum=sum*a%P;
		if(b) a=a*a%P;
	}
	return sum;
}
void fwt_or(ll *a,int n,int inv) {
	for(int len=2;len<=n;len<<=1) {
		int mid=len/2;
		for(int i=0;i<n;i+=len)
			for(int j=mid;j<len;++j)
				a[j+i]=(a[j+i]+a[j+i-mid]*inv+P)%P;
	}
}
void fwt_and(ll *a,int n,int inv) {
	for(int len=2;len<=n;len<<=1) {
		int mid=len/2;
		for(int i=0;i<n;i+=len)
			for(int j=0;j<mid;++j)
				a[j+i]=(a[j+i]+a[j+mid+i]*inv+P)%P;
	}
}
void fwt_xor(ll *a,int n,int inv) {
	static const ll inv2=Pow(2,P-2);
	for(int len=2;len<=n;len<<=1) {
		int mid=len/2;
		for(int i=0;i<n;i+=len)
			for(int j=0;j<mid;++j) {
				ll A0=a[i+j],A1=a[i+j+mid];
				a[i+j]=(A0+A1)%P,a[i+j+mid]=(A0-A1+P)%P;
				if(inv==-1) a[i+j]=(a[i+j]*inv2)%P,a[i+j+mid]=(a[i+j+mid]*inv2)%P;
			}
	}
}
int main() {
	scanf("%d",&n);
	n=1<<n;
	for(int i=0;i<n;++i) scanf("%lld",&a[i]);
	for(int i=0;i<n;++i) scanf("%lld",&b[i]);
	memcpy(aa,a,sizeof(ll)*n);
	memcpy(bb,b,sizeof(ll)*n);
	fwt_or(aa,n,1);fwt_or(bb,n,1);
	for(int i=0;i<n;++i)
		aa[i]=(aa[i]*bb[i])%P;
	fwt_or(aa,n,-1);
	for(int i=0;i<n;++i) {
		printf("%lld",aa[i]);
		if(i!=n-1) printf(" ");
	}
	puts("");

	memcpy(aa,a,sizeof(ll)*n);
	memcpy(bb,b,sizeof(ll)*n);
	fwt_and(aa,n,1);fwt_and(bb,n,1);
	for(int i=0;i<n;++i)
		aa[i]=(aa[i]*bb[i])%P;
	fwt_and(aa,n,-1);
	for(int i=0;i<n;++i) {
		printf("%lld",aa[i]);
		if(i!=n-1) printf(" ");
	}
	puts("");

	memcpy(aa,a,sizeof(ll)*n);
	memcpy(bb,b,sizeof(ll)*n);
	fwt_xor(aa,n,1);fwt_xor(bb,n,1);
	for(int i=0;i<n;++i)
		aa[i]=(aa[i]*bb[i])%P;
	fwt_xor(aa,n,-1);
	for(int i=0;i<n;++i) {
		printf("%lld",aa[i]);
		if(i!=n-1) printf(" ");
	}
	puts("");
}
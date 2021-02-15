#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cp {
	double real,imag;
	cp() {real=imag=0;}
	cp(double real,double imag):real(real),imag(imag){}
	cp operator + (const cp &b) const {
		return cp(real+b.real,imag+b.imag);
	}
	cp operator - (const cp &b) const {
		return cp(real-b.real,imag-b.imag);
	}
	cp operator * (const cp &b) const {
		return cp(real*b.real-imag*b.imag,real*b.imag+b.real*imag);
	}
	cp operator *= (const cp &b) {
		return *this=*this*b;
	}
};
const double pi=acos(-1);
const int maxn=4e5+10;
int r[maxn];
void init(int n) {
	for(int i=0;i<n;++i)
		r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
}
void fft(cp *a,int n,int inv){
	for(int i=0;i<n;++i)
		if(i<r[i]) swap(a[i],a[r[i]]);
	for(int len=2;len<=n;len<<=1){
		cp ut(cos(2*pi/len),sin(2*pi/len)*inv);
		for(int i=0;i<n;i+=len) {
			int mid=len/2;
			cp now(1,0);
			for(int j=0;j<mid;++j,now*=ut){
				cp tmp1(a[i+j]),tmp2(now*a[i+j+mid]);
				a[i+j]=tmp1+tmp2;
				a[i+j+mid]=tmp1-tmp2;
			}
		}
	}
	if(inv==-1){
		for(int i=0;i<n;++i)
			a[i].real/=n;
	}
}
int t,n,x[maxn];
cp a[maxn],b[maxn];
int main(){
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int lim=1;
	for(;lim<=200000;lim<<=1);
	init(lim);
	scanf("%d",&t);
	while(t--) {
		for(int i=0;i<maxn;++i)
			a[i].real=a[i].imag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			scanf("%d",&x[i]);
			a[x[i]].real+=1.0;
		}
		memcpy(b,a,sizeof a);
		fft(b,lim,1);
		for(int i=0;i<lim;++i)
			b[i]*=b[i];
		fft(b,lim,-1);
		long double res=0,sum=0;
		for(int i=1;i<=n;++i)
			b[x[i]<<1].real-=1.0;
		for(int i=0;i<lim;++i) {
			// cout<<b[i].real<<endl;
			assert(b[i].real+1e-7>=0);
			sum+=b[i].real;
			res+=sum*a[i].real;
		}
		// for(int i=0;i<10;++i)
		// 	cout<<(int)(b[i].real+0.49)<<" ";
		// cout<<endl;
		long long x=1LL*n*(n-1)*(n-2)/6;
		// cout<<x<<" "<<res<<endl;
		printf("%.10Lf\n",1.0L-1.0L*(long long)(res/2+0.49L)/x);
	}
} 

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
const int maxn=3e5+10;
const double pi=acos(-1);
int n,m,r[maxn];
double q[maxn];
cp f1[maxn],f2[maxn],g[maxn];
void fft(cp *a,int inv){
	for(int i=0;i<n;++i)
		if(i<r[i]) swap(a[i],a[r[i]]);
	for(int len=2;len<=n;len<<=1){
		cp ut(cos(2*pi/len),sin(2*pi/len)*inv);
		for(int i=0;i<n;i+=len) {
			int mid=len/2;
			cp now(1,0);
			for(int j=0;j<mid;++j,now*=ut){
				cp tmp1(a[i+j]),tmp2(a[i+j+mid]);
				a[i+j]=tmp1+now*tmp2;
				a[i+j+mid]=tmp1-now*tmp2;
			}
		}
	}
}
cp res1[maxn],res2[maxn];
double res[maxn];
int main(){
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d",&n);
	int k=n;
	for(int i=1;i<=n;++i){
		scanf("%lf",&q[i]);
		f1[i].real=q[i];
		f2[n-i]=f1[i];
		g[i].real=1.0/i/i;
	}
	for(m=n<<1,n=1;n<=m;n<<=1);
	for(int i=0;i<n;++i){
		r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
	}
	fft(f1,1);fft(g,1);fft(f2,1);
	for(int i=0;i<n;++i){
		res1[i]=f1[i]*g[i];
		res2[i]=f2[i]*g[i];
	}
	fft(res1,-1);fft(res2,-1);
	for(int i=1;i<=k;++i) {
		printf("%lf\n",(res1[i].real-res2[k-i].real)/n);
	}
}
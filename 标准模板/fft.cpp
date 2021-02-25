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
const int maxn=3e5+10;
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
				cp tmp1(a[i+j]),tmp2(a[i+j+mid]);
				a[i+j]=tmp1+now*tmp2;
				a[i+j+mid]=tmp1-now*tmp2;
			}
		}
	}
	if(inv==-1){
		for(int i=0;i<n;++i)
			a[i].real/=n;
	}
}
int main(){
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	
}

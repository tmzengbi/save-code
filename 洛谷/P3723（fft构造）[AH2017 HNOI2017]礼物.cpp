#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cp {
	long double real,imag;
	cp() {real=imag=0;}
	cp(long double real,long double imag):real(real),imag(imag){}
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
const long double pi=acos(-1);
int n,m,r[maxn];
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
int a[maxn],b[maxn];
int solve(int x,int sum) {
	return n*x*x+2*x*sum;
}
cp aa[maxn],bb[maxn];
int main(){
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	int res=0,sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		res+=a[i]*a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		res+=b[i]*b[i];
		sum-=b[i];
	}
	int x=-sum/n;
	int tmp=0x7fffffff;
	for(int i=x-1;i<=x+1;++i)
		tmp=min(solve(i,sum),tmp);
	res+=tmp;
	for(int i=1;i<=n;++i){
		aa[i+n].real=aa[i].real=a[n-i+1];
		bb[i].real=b[i];
	}
	int lim=1;
	for(;lim<=n*3;lim<<=1);
	for(int i=0;i<lim;++i){
		r[i]=(r[i>>1]>>1)|((i&1)?(lim>>1):0);
	}
	fft(aa,lim,1);fft(bb,lim,1);
	for(int i=0;i<lim;++i)
		aa[i]*=bb[i];
	fft(aa,lim,-1);
	int maxx=-0x7fffffff;
	for(int i=n+1;i<=n*2+1;++i){
		maxx=max(maxx,(int)(aa[i].real+0.49));
	}
	printf("%d\n",res-2*maxx);
}
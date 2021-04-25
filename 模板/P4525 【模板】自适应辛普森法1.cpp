#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
double a,b,c,d,l,r;
double f(double x) {
	return (c*x+d)/(a*x+b);
}
double simp(double x,double y) {
	return (f(x)+f((x+y)/2)*4.0+f(y))*(y-x)/6;
}
double solve(double l,double r,const double eps=1e-6) {
	double mid=(l+r)/2;
	double res1=simp(l,r);
	double res2=simp(l,mid)+simp(mid,r);
	if(fabs(res1-res2)<eps) {
		return res2;
	} else {
		return solve(l,mid,eps/2)+solve(mid,r,eps/2);
	}
}
int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r);
	double res=solve(l,r);
	printf("%.6lf\n",res);
}
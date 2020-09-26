#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
using namespace std;
typedef long long ll;
typedef complex<double> cp;
const int maxn=3e6+10;
const double pi=acos(-1);
int n,m;
cp a1[maxn],a2[maxn],b[maxn];
void fft(cp *a,int len,int inv)
{
	if(len==1) return;
	int mid=len/2;
	for(int i=0;i<mid;i++) b[i]=a[i<<1],b[i+mid]=a[i<<1|1];
	for(int i=0;i<len;i++) a[i]=b[i];
	fft(a,mid,inv);fft(a+mid,mid,inv);
	for(int i=0;i<mid;i++)
	{
		cp tmp(cos(pi*2*i/len),inv*sin(pi*2*i/len));
		b[i]=a[i]+tmp*a[i+mid];
		b[i+mid]=a[i]-tmp*a[i+mid];
	}
	for(int i=0;i<len;i++) a[i]=b[i];
}
int main()
{
    scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){double r;scanf("%lf",&r);a1[i].real(r);}
	for(int i=0;i<=m;i++){double r;scanf("%lf",&r);a2[i].real(r);}
	for(m+=n,n=1;n<=m;n<<=1);
	fft(a1,n,1);fft(a2,n,1);
	for(int i=0;i<n;i++) a1[i]*=a2[i];
	fft(a1,n,-1);
	for(int i=0;i<=m;i++)
		printf("%d ",(int)(a1[i].real()/n+0.49));
//	system("pause");
}
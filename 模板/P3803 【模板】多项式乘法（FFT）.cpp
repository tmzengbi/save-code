#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
#include<cmath>
using namespace std;
typedef long long ll;
//typedef complex<double> cp;
const int maxn=3e6+10;
const double pi=acos(-1);
struct cp
{
	double real,image;
	cp(double real,double image){this->real=real;this->image=image;}//:real(real),image(image){}
	cp(){real=image=0;}
	cp operator*(const cp& p2)const
	{
		double r=real*p2.real-image*p2.image;
		double ii=real*p2.image+p2.real*image;
		return cp(r,ii);
	}
	cp operator+(const cp&p2)const
	{
		double r=real+p2.real,ii=image+p2.image;
		return cp(r,ii);
	}
	cp operator-(const cp&p2)const
	{
		double r=real-p2.real,ii=image-p2.image;
		return cp(r,ii);
	}
};
int n,m,tr[maxn];
cp a1[maxn],a2[maxn];
void fft(cp *a,int len,int inv)
{
	for(int i=0;i<len;i++)
		if(i<tr[i]) swap(a[i],a[tr[i]]);
	for(int mid=1;mid<len;mid<<=1)
	{
		cp tmp(cos(pi/mid),inv*sin(pi/mid));
		for(int i=0;i<len;i+=mid*2)
		{
			cp ut(1,0);
			for(int j=0;j<mid;j++,ut=ut*tmp)
			{
				cp x=a[i+j],y=ut*a[i+j+mid];
				a[i+j]=x+y;a[i+j+mid]=x-y;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){double r;scanf("%lf",&r);a1[i].real=r;}
	for(int i=0;i<=m;i++){double r;scanf("%lf",&r);a2[i].real=r;}
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=0;i<n;i++)
		tr[i]=(tr[i>>1]>>1|((i&1)?n>>1:0));
	fft(a1,n,1);fft(a2,n,1);
	for(int i=0;i<n;i++) a1[i]=a1[i]*a2[i];
	fft(a1,n,-1);
	for(int i=0;i<=m;i++)
		printf("%d ",(int)(a1[i].real/n+0.5));
//	system("pause");
}
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
const int maxn=3e6+10;
const long double pi=acos(-1);
struct cp
{
	long double real,image;
	cp(long double real,long double image){this->real=real;this->image=image;}//:real(real),image(image){}
	cp(){real=image=0;}
	void init(){*this=cp();}
	cp operator*(const cp& p2)const
	{
		long double r=real*p2.real-image*p2.image;
		long double ii=real*p2.image+p2.real*image;
		return cp(r,ii);
	}
	cp operator+(const cp&p2)const
	{
		long double r=real+p2.real,ii=image+p2.image;
		return cp(r,ii);
	}
	cp operator-(const cp&p2)const
	{
		long double r=real-p2.real,ii=image-p2.image;
		return cp(r,ii);
	}
};
int n,m,tr[maxn];
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
int getnum(char *s)
{
	int sum=0;
	while(isdigit(*s))
	{
		sum=sum*10+*s-'0';
		s++;
	}
	return sum;
}
int from,to,k,hes[50010];
char s[1010];
cp a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	for(int i=4;i<=50000;i++)
		for(int j=2;j*j<=i;j++)
			if(i%j==0){hes[i]=1;break;}
	int cas=0;
	while(scanf("%d%d%d",&from,&to,&k)==3)
	{
		if(!from&&!to&&!k) break;
		for(int i=4;i<=to;i++)
			a[i].real=b[i].real=c[i].real=d[i].real=hes[i];
		for(int i=1;i<=k;i++)
		{
			scanf("%s",s);
			int len=strlen(s);
			if(s[len-1]=='S') a[getnum(s)].real=0;
			else if(s[len-1]=='H') b[getnum(s)].real=0;
			else if(s[len-1]=='C') c[getnum(s)].real=0;
			else d[getnum(s)].real=0;
//			printf("%d\n",getnum(s));
		}
		for(n=1;n<=to;n<<=1);n<<=2;
		for(int i=0;i<n;i++)
			tr[i]=(tr[i>>1]>>1|((i&1)?n>>1:0));
		fft(a,n,1);fft(b,n,1);fft(c,n,1);fft(d,n,1);
		for(int i=0;i<n;i++)
			a[i]=a[i]*b[i]*c[i]*d[i];
		fft(a,n,-1);
		for(int i=from;i<=to;i++)
			printf("%lld\n",(ll)((a[i].real/n)+0.5));
		for(int i=0;i<n;i++)
		{
			a[i].init();b[i].init();
			c[i].init();d[i].init();
		}
		puts("");
	}
}
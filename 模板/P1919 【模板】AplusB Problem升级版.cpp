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
const double pi=acos(-1);
struct cp
{
	double a,b;
	cp(double a,double b){this->a=a;this->b=b;}
	cp(){a=b=0;}
	cp operator +(const cp&B)const
	{
		return cp(a+B.a,b+B.b);
	}
	cp operator -(const cp&B)const
	{
		return cp(a-B.a,b-B.b);
	}
	cp operator*(const cp&B)const
	{
		return cp(a*B.a-b*B.b,a*B.b+b*B.a);
	}
}a1[maxn],a2[maxn];
char s[maxn];
int n,m,tr[maxn],c[maxn];
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
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) a1[i].a=s[n-i-1]-'0';
	scanf("%s",s);
	m=strlen(s);
	for(int i=0;i<m;i++) a2[i].a=s[m-i-1]-'0';
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=0;i<n;i++) tr[i]=(tr[i>>1]>>1|((i&1)?n>>1:0));
	fft(a1,n,1);fft(a2,n,1);
	for(int i=0;i<n;i++) a1[i]=a1[i]*a2[i];
	fft(a1,n,-1);
	int len=0;
	for(int i=0;;i++,len++)
	{
		if(i<=m)c[i]+=(int)(a1[i].a/n+0.49);
		if(i>m&&c[i]==0) break;
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]=c[i]%10;
		}
	}
	while(c[len-1]==0)len--;
	for(int i=len-1;i>=0;i--)
		printf("%d",c[i]);
//	system("pause");
}
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
const int P=998244353,g=3,maxn=3e6+10;
int a1[maxn],a2[maxn],n,m,tr[maxn];
int Pow(int a,int b)
{
	ll sum=1,z=a;
	for(;b;b>>=1)
	{
		if(b&1) sum=sum*z%P;
		if(b) z=z*z%P;
	}
	return (int)sum%P;
}
void ntt(int *a,int inv)
{
	for(int i=0;i<n;i++)
		if(i<tr[i]) swap(a[i],a[tr[i]]);
	for(int mid=1;mid<n;mid<<=1)
	{
		int tmp=Pow(g,(P-1)/(mid*2));
		if(inv==-1) tmp=Pow(tmp,P-2);
		for(int i=0;i<n;i+=mid*2)
		{
			ll ut=1;
			for(int j=0;j<mid;j++,ut=ut*tmp%P)
			{
				int x=a[i+j],y=ut*a[i+j+mid]%P;
				a[i+j]=(x+y)%P;a[i+j+mid]=(x-y+P)%P;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) scanf("%d",&a1[i]);
	for(int i=0;i<=m;i++) scanf("%d",&a2[i]);
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=0;i<n;i++)
		tr[i]=(tr[i>>1]>>1|((i&1)?n>>1:0));
	ntt(a1,1);ntt(a2,1);
	for(int i=0;i<n;i++) a1[i]=(ll)a1[i]*a2[i]%P;
	ntt(a1,-1);
	for(int i=0;i<n;i++) a1[i]=(ll)a1[i]*Pow(n,P-2)%P;
	for(int i=0;i<=m;i++)
		printf("%d ",a1[i]);
//	system("pause");
}
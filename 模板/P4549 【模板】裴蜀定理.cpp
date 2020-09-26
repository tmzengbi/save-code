#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)	return a;
	return gcd(b,a%b);
}
int main()
{	
	int n,a[22],r,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	r=abs(a[1]);
	for(int i=2;i<=n;i++)
		r=gcd(r,abs(a[i]));
	cout<<r<<endl;
}
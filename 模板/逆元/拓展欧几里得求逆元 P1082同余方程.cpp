#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0){x=1;y=0;return a;}
	int r=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return r;
}
int c(int a,int d)
{
	if(a<0)	return a+d;
	else return a;
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int r=exgcd(a,b,x,y);
	printf("%d",c(x,b));
}

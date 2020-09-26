#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a[8]={0,1,2,3,4,5,6,7},N=7;
void xx(int root)		//先序
{
	if(root>N)	return;
	cout<<a[root]<<" ";
	xx(root<<1);
	xx(root<<1|1);
}
void zx(int root)		//中序
{
	if(root>N)	return;
	zx(root<<1);
	cout<<a[root]<<" ";
	zx(root<<1|1);
}
void hx(int root)		//后序
{
	if(root>N)	return;
	hx(root<<1);
	hx(root<<1|1);
	cout<<a[root]<<" ";
}
int main()
{
	xx(1);cout<<endl;
	zx(1);cout<<endl;
	hx(1);cout<<endl;


	
}
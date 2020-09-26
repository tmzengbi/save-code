#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int bfind(int m,int l,int r,int a[])
{
	if(l==r)	return l;
	int mid=(l+r)>>1;
	if(a[mid]>=m)	return bfind(m,l,mid,a);
	else	return bfind(m,mid+1,r,a);
}
int main()
{
	srand((unsigned)time(NULL));
	int a[11],l=1,r=10;
	for(int i=1;i<=10;i++)
		a[i]=rand()%99+1;
	sort(a+1,a+11);
	for(int i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
	int m;
	while(true)
	{
		cin>>m;
		cout<<m<<" "<<bfind(m,l,r,a)<<endl;
//		system("pause");
	}
}
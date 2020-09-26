#include<iostream>
using namespace std;
int n,a,x,b,y;
int main()
{
	cin>>n>>a>>x>>b>>y;
	while(a!=x&&b!=y)   //
	{
		a++;b--;
		if(a>n)	a=a-n;
		if(b<1) b=b+n;
		if(a==b)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}

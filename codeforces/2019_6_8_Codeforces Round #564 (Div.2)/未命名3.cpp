#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c==0)
	{
		if(a==b)
		{
			cout<<0;
			return 0;
		}
		if(a>b)
		{
			cout<<'+';
			return 0;
		}
		if(a<b)
		{
			cout<<'-';
			return 0;
		}
	}
	else if(c!=0)
	{
		if(a>b+c)
		{
			cout<<'+';
			return 0;
		}
		else if(b>a+c)
		{
			cout<<'-';
			return 0;
		}
		else 
		{
			cout<<'?';
			return 0;
		}
	}
}

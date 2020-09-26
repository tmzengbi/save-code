#include<iostream>
using namespace std;
bool ans(int &x);
int n;
bool flag=true;
inline int read();
int main()
{
	n=read();
	while(n-->0)
	{
		flag=true;
		int weight=0;
		bool pass=ans(weight);
		if(pass) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
		if(n) cout<<"\n";
	}
}
bool ans(int &x)
{
	int lw,ld,rw,rd;
	cin>>lw>>ld>>rw>>rd;

	bool b1=true,b2=true;

	if(!lw)	//b1=ans(lw);						
		flag=ans(lw);
	if(!rw)	//b2=ans(rw);					
	flag=ans(rw);
	x=lw+rw;
	return //b1&&b2&&(lw*ld==rw*rd);				
						(flag&&(lw*ld==rw*rd)) ;
}
inline int read()
{
	int f=1,shu=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}

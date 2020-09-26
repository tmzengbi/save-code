#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll read(ll m)
{
	ll shu=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		if(shu>m)	f=1;
		shu%=m;
		ch=getchar();
	}
	return shu+(f==1?m:0);
}
ll auler(ll m)
{
	ll sum=m,k=m;
	for(ll i=2;i*i<k;i++)
	{
		if(m%i==0)
		{
			sum=sum/i*(i-1);
			while(m%i==0)	m=m/i;
		}
	}
	if(m>1)	sum=sum/m*(m-1);
	return sum;
}
ll fpow(ll a,ll p,ll m)
{
	ll sum=1;
	for(;p;p>>=1)
	{
		if(p&1)	sum=sum*a%m;
		if(p)	a=a*a%m;
	}
	return sum;
}
int main()
{
	ll a,m,b;
	cin>>a>>m;
	ll au=auler(m);
	b=read(au);
	cout<<fpow(a,b,m)<<endl;
//system("pause");
}
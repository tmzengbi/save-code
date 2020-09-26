#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll a,b,c;
ll read();
int main()
{
	a=read();b=read();c=read();
	ll ans=0;
	if(a>b) 
		ans=b*2+1+c*2;
	else if(a==b)
		ans=a*2+c*2;
	else if(a<b)
		ans=a*2+1+c*2;
	cout<<ans;
}
ll read()
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

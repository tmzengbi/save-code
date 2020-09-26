#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm> 
using namespace std;
stack<int> s;
int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
int main()
{
	int n=read();
	int ans=n;
	s.push(0);
	while(n--)
	{
		int w=read(),k=read();
		int t=s.top();
		if(k>t)	s.push(k);
		else
		{
			while(k<=t)
			{
				if(t==k) ans--;
				s.pop();
				t=s.top();
			}
			s.push(k);
		}
	}
	cout<<ans;
}

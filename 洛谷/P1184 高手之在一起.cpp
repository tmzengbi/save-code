#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<string,bool> m2;
int ans=0;
int main()
{
	int n,m;
	cin>>n>>m;
	string tmp;
	while(n--)
	{
		cin>>tmp;
		string a;
		while(getchar()==' ')
		{
			cin>>a;
			tmp+=a;
		}
		m2[tmp]=true;
	}
	while(m--)
	{
		string a,b;
		cin>>a;
		while(getchar()==' ')
		{
			cin>>b;
			a+=b;
		}
		if(m2[a])	ans++;
	}
	cout<<ans;
} 

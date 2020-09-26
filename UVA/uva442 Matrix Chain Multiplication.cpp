#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int read();

struct edge
{
	int a,b;
	edge(int a1=0,int b1=0):a(a1),b(b1){}
}m[30];

int n,ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		char ch;cin>>ch;
		int Ind=(ch-'A')+1;
		cin>>m[Ind].a>>m[Ind].b;
	}
	string st;
	stack<edge> s;
	while(cin>>st)
	{
		ans=0;
		bool flag=true;
		int len=st.length();
		for(int i=0;i<len;i++)
		{
			if(st[i]=='(') continue;
			if(st[i]==')')
			{
				edge m2=s.top();s.pop();
				edge m1=s.top();s.pop();
				if(m1.b!=m2.a) 
				{
					cout<<"error\n";
					flag=false;
					break;
				}
				else	
				{
					ans+=m1.a*m1.b*m2.b;
					s.push(edge(m1.a,m2.b));
				}
			}
			if(isalpha(st[i]))
			{
				int Ind=st[i]-'A'+1;
				s.push(m[Ind]);
			}
			
		}
		if(flag)
			cout<<ans<<endl;
	}
		
	
}
int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch=='-') 
	{
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return f*shu;
}

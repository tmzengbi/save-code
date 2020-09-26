#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
struct Bignum
{
	vector<int> num;
	Bignum(){init();}
	void init()
	{
		num.clear();
	}
	Bignum operator = (long long n)
	{
		num.clear();
		do
		{
			num.push_back(n%10);
			n/=10;
		}while(n);
		return *this;
	}
	Bignum operator =(const string& str)
	{
		num.clear();
		int x,len=(str.length()-1);
		for(int i=len;i>=0;i--)
		{
			x=str[i]-'0';
			num.push_back(x);
		}
		return *this;
	}
	Bignum operator + (const Bignum &b) const
	{
		Bignum S;
		S.num.clear();
		for(int i=0,g=0;;i++)
		{
			if(g==0&&i>=num.size()&&i>=b.num.size()) break;
			int x=g;
			if(i<num.size()) x+=num[i];
			if(i<b.num.size()) x+=b.num[i];
			S.num.push_back(x%10);
			g=x/10;
		}
		return S;
	}
	Bignum operator +=(const Bignum &b)
	{
		*this=*this+b;return *this;
	}
};
istream& operator >>(istream &in, Bignum &x)
{
	string s;
	if(!(in>>s))	return in;
	x=s;
	return in;
}
ostream& operator <<(ostream& out,const Bignum &x)
{
//	out<<x.num.back();
	for(int i=x.num.size()-1;i>=0;i--)
	{
		char buf[20];
		sprintf(buf,"%d",x.num[i]);
		for(int j=0;j<strlen(buf);j++) out<<buf[j];
	}
	return out;
}
int main()
{

	Bignum a,b;
	cin>>a>>b;
	cout<<a+b;
}
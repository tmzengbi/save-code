#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Bignum
{
	vector<int>num;
	int f;
	bool checkzero()const
	{
		for(int i=0;i<num.size();i++) if(num[i]) return false;
		return true;
	}
	Bignum Add(Bignum &A,Bignum &B)
	{
		Bignum b;b.f=A.f;
		for(int i=0,d=0;;i++)
		{
			int sum=d;
			if(i>=A.num.size()&&i>=B.num.size()&&!d) break;
			if(i<A.num.size()) sum+=A.num[i];
			if(i<B.num.size()) sum+=B.num[i];
			if(sum>=10){sum=sum%10;d=1;}
			else d=0;
			b.num.push_back(sum);
		}
		return b;
	}
	Bignum Minus(Bignum &A,Bignum &B)
	{
		Bignum b;
		if(A<B){swap(A,B);b.f=-A.f;}
		else b.f=A.f;
		for(int i=0,d=0;;i++)
		{
			int sum=d;
			if(i>=A.num.size()&&i>=B.num.size()&&!d) break;
			if(i<A.num.size()) sum+=A.num[i];
			if(i<B.num.size()) sum-=B.num[i];
			if(sum<0){sum=(sum+10)%10;d=-1;}
			else d=0;
			b.num.push_back(sum);
		}
		int k=b.num.size();
		while(!b.num[--k]&&k);
		b.num=vector<int>(b.num.begin(),b.num.begin()+k);
		if(b.checkzero())b.f=1;
		return b;
	}
	Bignum operator-(Bignum &B)
	{
		if(f!=B.f){B.f=-f;return Add(*this,B);}
		return Minus(*this,B);
	}
	Bignum operator+(Bignum &B)
	{
		if(f!=B.f){B.f=-1;return Minus(*this,B);}
		return Add(*this,B);
	}
	Bignum operator/(long long B)
	{
		Bignum b;int bf=1;
		if(B<0) B=-B,bf=-1;
		cout<<f<<" "<<bf<<endl;
		bf=f*bf;
		long long shu=0;
		string ans="";
		for(int i=num.size()-1;i>=0;i--)
		{
			shu=shu*10+num[i];
			if(shu>=B) 
			{
				ans+=char(shu/B+'0');
				shu=shu%B;
			}
			else ans+='0';
		}
		b=ans;b.f=bf;
		if(b.checkzero()) b.f=1;
		return b;
	}
	Bignum operator*(long long B)
	{
		Bignum b;int bf=1;
		if(B<0) B=-B,bf=-1;
		bf=f*bf;
		long long shu[num.size()];
		for(int i=0;i<num.size();i++)
			shu[i]=num[i]*B;
		long long d=0;string ans="";
		for(int i=0;;i++)
		{
			if(i>=num.size()&&!d) break;
			if(i<num.size()) d+=shu[i];
			b.num.push_back(d%10);
			d/=10;
		}
		b.f=bf;
		if(b.checkzero()) b.f=1;
		return b;
	}
	Bignum operator=(long long N)
	{
		num.clear();
		if(N<0) f=-1,N=-N;
		else f=1;
		while(N)
		{
			num.push_back(N%10);
			N/=10;
		}
		return *this;
	}
	Bignum operator=(const string &S)
	{
		num.clear();
		if(S[0]=='-') f=-1;
		else f=1;
		int x,len=(S.length()-1);
		int st=0;
		while(st<=len&&(S[st]=='0'||S[st]=='-'))st++;
		if(st==len+1) num.push_back(0);
		for(int i=len;i>=st;i--)
		{
			x=S[i]-'0';
			num.push_back(x);
		}
		return *this;
	}
	bool operator <(Bignum &B)
	{
		if(f!=B.f) return f<B.f;
		if(num.size()!=B.num.size()) return num.size()<B.num.size();
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=B.num[i]) return num[i]<B.num[i];
		return false;
	}
};
ostream&operator<<(ostream &out,const Bignum &B)
{
	if(B.checkzero()) out<<"0";
	else
	{
		if(B.f==-1) out<<"-";
		int k=B.num.size();
		for(int i=k-1;i>=0;i--)
			out<<B.num[i];
	}
	return out;
}
istream& operator >>(istream &in, Bignum &x)
{
	string s;
	if(!(in>>s)) return in;
	x=s;
	return in;
}
struct node
{
	int l,r;
}t[1010];
bool cmp(const node &n1,const node &n2)
{
	return (n1.l*n1.r)<(n2.l*n2.r);
}
int N,L,R;
int main()
{
//	ios::sync_with_stdio(false);
	cin>>N;
	cout<<N<<endl;
	for(int i=1;i<=N+1;i++)
		cin>>t[i].l>>t[i].r;
	sort(t+2,t+N+2,cmp);
	Bignum Max,num;
	Max=0;num=1;
	for(int i=1;i<=N;i++)
	{
		num=num*t[i].l;
		Bignum k=num/t[i+1].r;
		cout<<num<<" "<<k<<" "<<(Max<k)<<" "<<endl;
		if(Max<k) Max=k;
	}
	cout<<Max<<endl;
//	system("pause");
}
/*
3
1 7
6 1
2 3
2 3
*/


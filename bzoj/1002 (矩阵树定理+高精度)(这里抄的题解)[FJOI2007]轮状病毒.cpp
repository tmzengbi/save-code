#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<random>
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
class Bignum{ // keep number>0 while the whole calculation
private:
	vector<int>c;
	void assign(long long x){
		c.clear();
		while(x){
			c.push_back(x%10);
			x/=10;
		}
	}
	void assign(const string &str){
		c.clear();
		int s=str.size()-1;
		for(;s>=0;--s){
			c.push_back(str[s]-'0');
		}
	}
	void erase_front_zero(){
		int s=c.size()-1;
		while(s>0&&c[s]==0) --s;
		c.resize(s+1);
	}
public:
	Bignum(){
		assign(0);
	}
	Bignum(long long x){
		assign(x);
	}
	Bignum(const string &str){
		assign(str);
	}
	Bignum operator + (const Bignum &rhs) const{
		Bignum tmp;
		vector<int> &vec=tmp.c;
		for(int i=0,d=0;;++i){
			if(i>=rhs.c.size()&&i>=c.size()&&!d) break;
			int add=0;
			if(i<rhs.c.size()) add+=rhs.c[i];
			if(i<c.size()) add+=c[i];
			vec.push_back((d+add)%10);
			d=(d+add)/10;
		}
		return tmp;
	}
	Bignum operator - (const Bignum &rhs) const{
		Bignum tmp;
		vector<int> &vec=tmp.c;
		vec.assign(c.begin(),c.end());
		for(int i=0,d=0;;++i){
			if(i>=rhs.c.size()&&!d) break;
			if(i<rhs.c.size()) vec[i]-=rhs.c[i];
			vec[i]-=d;d=0;
			if(vec[i]<0){
				vec[i]+=10;
				d=1;
			}
		}
		tmp.erase_front_zero();
		return tmp;
	}
	Bignum operator * (const Bignum &rhs) const{
		Bignum tmp;
		vector<int> &vec=tmp.c;
		vec.resize(c.size()+rhs.c.size());
		for(int i=0;i<c.size();++i)
			for(int j=0;j<rhs.c.size();++j){
				vec[i+j]+=c[i]*rhs.c[j];
			}
		for(int i=0,d=0;i<vec.size();++i){
			vec[i]+=d;d=0;
			if(vec[i]>=10){
				d=vec[i]/10;
				vec[i]%=10;
			}
		}
		tmp.erase_front_zero();
		return tmp;
	}
	Bignum operator = (const Bignum &rhs){
		if(&rhs==this) return *this;
		c.assign(rhs.c.begin(),rhs.c.end());
		return *this;
	}
	friend ostream &operator << (ostream &out,const Bignum &rhs){
		int s=rhs.c.size()-1;
		for(;s>=0;--s){
			out<<rhs.c[s];
		}
		return out;
	}
};
Bignum f[110];
int main(){
	int n;cin>>n;
	Bignum a(3),b(2);
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;++i)
		f[i]=a*f[i-1]+b-f[i-2];
	cout<<f[n]<<endl;

}
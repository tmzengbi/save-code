#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
const int P=10007;
int read(){
	int x=0;char ch=getchar();
	bool f=1;
	while(!isdigit(ch)){if(ch=='-')f=false;ch=getchar();}
	while(isdigit(ch)){
		x=(x*10+ch-'0')%P;
		ch=getchar();
	}
	return x;
}
int Pow(int a,int b){
	ll sum=1,z=a;
	for(;b;b>>=1){
		if(b&1) sum=sum*z%P;
		if(b) z=z*z%P;
	}
	return sum;
}
int main(){
	int n=read(),d=Pow(6,P-2);
	printf("%lld\n",((1LL*(n+2)*(n+1)*n%P+P)%P*d%P));
}
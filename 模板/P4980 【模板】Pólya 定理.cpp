#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
int n,t;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
const int P=1e9+7;
int Pow(int a,int b){
	ll sum=1,z=a;
	for(;b;b>>=1){
		if(b&1) sum=sum*z%P;
		if(b) z=z*z%P;
	}
	return (int)sum;
}
int inv(int x){
	return Pow(x,P-2);
}
int getauler(int x){
	if(x==1) return 1;
	int sum=x,to=sqrt(x+0.5);
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			while(x%i==0) x/=i;
			sum=sum/i*(i-1);
		}
	}
	if(x>1) sum=sum/x*(x-1);
	return sum;
}
vector<int> getfactor(int x){
	vector<int> fac;
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			if(i*i==x) fac.push_back(i);
			else{
				fac.push_back(i);
				fac.push_back(x/i);
			}
		}
	}
	return fac;
}
int main(){
	#ifdef DEBUG
//		freopen("a.in","r",stdin);
//		freopen("a.out","w",stdout);
	#endif
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			puts("1");
			continue;
		}
		int ans=0;
		const auto &fac=getfactor(n);
		for(int d:fac){
			ans=(ans+1LL*Pow(n,d)*getauler(n/d)%P)%P;
		}
		ans=1LL*ans*inv(n)%P;
		printf("%d\n",ans);
	}
}
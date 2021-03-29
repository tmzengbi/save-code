#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int t,n,m,p,fac[maxn],inv[maxn];
int Pow(int a,int b){
	ll z=a,sum=1;
	for(;b;b>>=1){
		if(b&1) sum=sum*z%p;
		if(b) z=z*z%p;
	}
	return sum;
}
int c(int a,int b){
	if(a<b) return 0;
	return 1LL*fac[a]*inv[b]%p*inv[a-b]%p;
}
int lucas(int a,int b){
	if(a<b) return 0;
	return b==0?1:1LL*c(a%p,b%p)*lucas(a/p,b/p)%p;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&p);
		fac[0]=inv[0]=1;
		for(int i=1;i<=100000;++i){
			fac[i]=1LL*fac[i-1]*i%p;
			inv[i]=Pow(fac[i],p-2);
		}
		printf("%d\n",lucas(n+m,n));
	}
}
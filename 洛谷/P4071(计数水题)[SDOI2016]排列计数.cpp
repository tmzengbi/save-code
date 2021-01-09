#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int P=1e9+7;
typedef long long ll;
int t,n,m;
int k[maxn],fac[maxn],ifac[maxn];
int c(int a,int b){
    if(a<b) return 0;
    return 1LL*fac[a]*ifac[b]%P*ifac[a-b]%P;
}
int Pow(int a,int b){
    ll z=a,sum=1;
    for(;b;b>>=1){
        if(b&1) sum=sum*z%P;
        if(b) z=z*z%P;
    }
    return sum;
}
int inv(int x){
    return Pow(x,P-2);
}
int main(){
    k[1]=0;k[2]=1;
    for(int i=3;i<=1000000;++i)
        k[i]=1LL*(i-1)*(k[i-1]+k[i-2])%P;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=1000000;++i){
        fac[i]=1LL*fac[i-1]*i%P;
        ifac[i]=inv(fac[i]);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n==m) puts("1");
        else printf("%lld\n",1LL*c(n,m)*k[n-m]%P);
    }
}
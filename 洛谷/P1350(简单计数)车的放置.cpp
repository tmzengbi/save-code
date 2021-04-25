#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int P=1e5+3;
ll fac[maxn],ifac[maxn];
ll Pow(ll a,ll b) {
    ll res=1;
    for(;b;b>>=1) {
        if(b&1) res=res*a%P;
        if(b) a=a*a%P;
    }
    return res;
}
ll inv(ll x) {
    return Pow(x,P-2);
}
ll C(int a,int b) {
    if(a<b) return 0;
    return fac[a]*ifac[b]%P*ifac[a-b]%P;
}
int a,b,c,d,k;
int main() {
    fac[0]=ifac[0]=1;
    for(int i=1;i<maxn;++i) {
        fac[i]=fac[i-1]*i%P;
        ifac[i]=inv(fac[i]);
    }
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    ll res=0;
    for(int n=0;n<=k;++n) {
        if(d-n<0) break;
        res=res+C(c,n)*fac[d]%P*ifac[d-n]%P*C(a,k-n)%P*fac[b+d-n]%P*ifac[b+d-k]%P;
    }
    res%=P;
    printf("%lld\n",res);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int P=1e9+7;
int n,m;
ll a[maxn];
ll res[maxn];
ll Pow(ll a,ll b) {
	ll sum=1;
	for(;b;b>>=1) {
		if(b&1) sum=sum*a%P;
		if(b) a=a*a%P;
	}
	return sum;
}
const ll inv2=Pow(2,P-2);
void fwt_xor(int n,ll *a,int inv) {
	for(int len=2;len<=n;len<<=1) {
		int mid=len>>1;
		for(int i=0;i<n;i+=len) {
			for(int j=0;j<mid;++j) {
				ll a1=a[i+j],a2=a[i+j+mid];
				a[i+j]=(a1+a2)%P,a[i+j+mid]=(a1-a2+P)%P;
				if(inv==-1) {
					a[i+j]=a[i+j]*inv2%P;
					a[i+j+mid]=a[i+j+mid]*inv2%P;
				}
			}
		}
	}
}
int prime[50010],tot=0,vis[50010];
void sieve() {
	for(int i=2;i<=50000;++i) {
		if(!vis[i]) {
			prime[++tot]=i;
			vis[i]=i;
		}
		for(int j=1;j<=tot;++j) {
			if(i*prime[j]>50000) break;
			vis[i*prime[j]]=vis[i];
			if(i%prime[j]==0) break;
		}
	}
}
int main() {
	#ifdef DEBUG
		freopen("1.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	sieve();
	while(scanf("%d%d",&n,&m)==2){
		memset(a,0,sizeof a);
		int len=1;
		while(len<=m) len<<=1;
		for(int i=1;i<=m;++i) a[i]=(vis[i]==i);
		for(int i=0;i<len;++i) res[i]=1;
		fwt_xor(len,a,1);
		for(;n;n>>=1) {
			if(n&1) {
				for(int i=0;i<len;++i)
					res[i]=(res[i]*a[i])%P;
			}
			for(int i=0;i<len;++i)
				a[i]=(a[i]*a[i])%P;
		}
		fwt_xor(len,res,-1);
		printf("%lld\n",res[0]);
	}
}
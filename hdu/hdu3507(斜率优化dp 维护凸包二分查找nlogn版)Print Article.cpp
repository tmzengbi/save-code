#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
using namespace std;
const int maxn=5e5+10;
typedef long long ll;
int n,m;ll c[maxn];
ll f[maxn];
struct Node{
	ll x,y;
	Node(ll x=0,ll y=0):x(x),y(y){}
}s[maxn];
int Index=0;
double getxy(Node &x,Node &y){
	if(x.x==y.x) return x.y>y.y?-2e9:2e9;
	return 1.0*(x.y-y.y)/(x.x-y.x);
}
Node work(ll x){
	int l=0,r=Index;
	while(l<r){
		int mid=(l+r)>>1;
		if(x>getxy(s[mid],s[mid+1])) l=mid+1;
		else r=mid;
	}
	return s[l];
}
int main(){
	while(scanf("%d%d",&n,&m)==2&&n){
		for(int i=1;i<=n;++i){
			scanf("%lld",&c[i]);
			c[i]+=c[i-1];
		}
		Index=0;
		for(int i=1;i<=n;++i){
			Node tmp=work(c[i]);
			f[i]=tmp.y-tmp.x*c[i]+m+c[i]*c[i];
			Node add(2*c[i],f[i]+c[i]*c[i]);
			while(Index&&getxy(s[Index-1],s[Index])>=getxy(s[Index],add)) --Index;
			s[++Index]=add;
		}
		printf("%lld\n",f[n]);
	}
}
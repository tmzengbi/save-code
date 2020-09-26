#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
struct Node{
	int x,y;
	ll c;
	bool operator<(const Node&rhs)const{
		return x<rhs.x;
	}
}p[maxn];
struct Node2{
	int x;ll f;
	Node2(int x=0,ll f=0):x(x),f(f){};
}s[maxn];
int n,top=0;
ll f[maxn];
double calc(const Node2 &x,const Node2 &y){
	return 1.0*(x.f-y.f)/(x.x-y.x);
}
Node2 work(int x){
	int l=0,r=top;
	while(l<r){
		int mid=(l+r)>>1;
		if(calc(s[mid],s[mid+1])>x) l=mid+1;
		else r=mid;
	}
	return s[l];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%lld",&p[i].x,&p[i].y,&p[i].c);
	sort(p+1,p+n+1);
	ll ans=0;
	for(int i=1;i<=n;++i){
		const Node2 &tmp=work(p[i].y);
		f[i]=-1LL*tmp.x*p[i].y+tmp.f+1LL*p[i].x*p[i].y-p[i].c;
		ans=max(ans,f[i]);
		const Node2 &add=Node2(p[i].x,f[i]);
		if(calc(s[top],add)<0) continue;
		while(top&&calc(s[top-1],s[top])<calc(s[top],add))
			--top;
		s[++top]=add;
	}
	printf("%lld\n",ans);

}
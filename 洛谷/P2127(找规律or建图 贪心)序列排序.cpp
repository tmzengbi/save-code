#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int n,a[maxn],b[maxn];
ll res=0;
int vis[maxn],nxt[maxn];
void dfs(ll &sum,int &minn,int &cnt,int u){
	vis[u]=1;
	sum+=a[u];
	minn=min(minn,a[u]);
	++cnt;
	if(vis[nxt[u]]) return;
	dfs(sum,minn,cnt,nxt[u]);
}
int find(int x){
	return lower_bound(b+1,b+n+1,x)-b;
}
int main() {
	int mmin=2e9;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
		mmin=min(mmin,a[i]);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		nxt[i]=find(a[i]);
	for(int i=1;i<=n;++i){
		ll sum=0;int minn=2e9,cnt=0;
		if(!vis[i]){
			dfs(sum,minn,cnt,i);
			sum-=minn;
			res+=sum+min(1LL*(cnt-1)*mmin+2LL*(mmin+minn),1LL*(cnt-1)*minn);
		}
	}
	printf("%lld\n",res);
}
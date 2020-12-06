#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=200010;
int n,m,a[maxn],nxt[maxn],pre[maxn],vis[maxn];
priority_queue<pii>q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		nxt[i]=i+1;
		scanf("%d",&a[i]);
		q.push(make_pair(a[i],i));
		pre[i]=i-1;
	}
	if(m>n/2){
		puts("Error!");
		return 0;
	}
	nxt[n]=1;pre[1]=n;
	ll ans=0;
	int cnt=0;
	while(cnt<m){
		auto x=q.top();q.pop();
		int now=x.second,pree=pre[pre[now]],nxtt=nxt[nxt[now]];
		if(vis[now]) continue;
		ans+=x.first;
		vis[pre[now]]=vis[nxt[now]]=1;
		a[now]=a[pre[now]]+a[nxt[now]]-x.first;
		q.push(make_pair(a[now],now));
		nxt[pree]=now;
		nxt[now]=nxtt;pre[now]=pree;
		pre[nxtt]=now;
		++cnt;
	}
	printf("%lld\n",ans);
}

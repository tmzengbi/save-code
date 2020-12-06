#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pii;
const int maxn=1e5+10;
int n,m,v[maxn],vis[maxn],pre[maxn],nxt[maxn];
ll val[maxn];
priority_queue<pii,vector<pii>,greater<pii> >q;
int main() {
	#ifdef DEBUG
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
	}
	val[0]=1e9;
	for(int i=1;i<n;++i){
		val[i]=v[i+1]-v[i];
		nxt[i]=i+1;
		pre[i]=i-1;
		q.push(make_pair(val[i],i));
	}
	nxt[n-1]=0;
	int cnt=0;
	ll ans=0;
	while(cnt<m){
		auto x=q.top();q.pop();
		if(vis[x.second]) continue;
		int now=x.second,pree=pre[pre[now]],nxtt=nxt[nxt[now]];
		vis[pre[now]]=vis[nxt[now]]=1;
		ans+=x.first;
		val[now]=val[pre[now]]+val[nxt[now]]-val[now];
		q.push(make_pair(val[now],now));
		nxt[pree]=now;
		pre[now]=pree;nxt[now]=nxtt;
		pre[nxtt]=now;
		++cnt;
	}
	printf("%lld\n",ans);
}
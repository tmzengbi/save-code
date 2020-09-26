#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int n,c[maxn],son[maxn],siz[maxn],ans[maxn];
int cnt[maxn],sum=0;
vector<int>edges[maxn];
void dfs1(int u,int fa){
	siz[u]=1;
	for(int v:edges[u]){
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void update(int col,int opt){
	if(opt==1&&cnt[col]==0) sum++;
	cnt[col]+=opt;
	if(opt==-1&&cnt[col]==0) sum--;
}
void count(int u,int fa,int opt){
	update(c[u],opt);
	for(int v:edges[u]){
		if(v==fa) continue;
		count(v,u,opt);
	}
}
void dfs(int u,int fa,bool keep){
	for(int v:edges[u]){
		if(v==fa||v==son[u]) continue;
		dfs(v,u,false);
	}
	if(son[u]) 
		dfs(son[u],u,true);
	update(c[u],1);
	for(int v:edges[u]){
		if(v==fa||v==son[u]) continue;
		count(v,u,1);
	}
	ans[u]=sum;
	if(!keep) count(u,fa,-1);

}
int main(){
	#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	dfs1(1,1);
	dfs(1,1,true);
	int q;scanf("%d",&q);
	while(q--){
		int ask;scanf("%d",&ask);
		printf("%d\n",ans[ask]);
	}
}
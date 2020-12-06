#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
int n,q,a[maxn];
int sumv[maxn],pre[maxn];
vector<pii>p[maxn];
int ans[maxn];
inline int lowbit(int x){return x&-x;}
void update(int x,int v){
	for(;x<=n;x+=lowbit(x)){
		sumv[x]+=v;
	}
}
int query(int x){
	int res=0;
	for(;x;x-=lowbit(x)){
		res+=sumv[x];
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int l,r;scanf("%d%d",&l,&r);
		p[r].push_back(make_pair(l,i));
	}
	for(int i=1;i<=n;++i){
		update(i,1);
		if(pre[a[i]]) update(pre[a[i]],-1);
		pre[a[i]]=i;
		for(auto x:p[i]){
			ans[x.second]=query(i)-query(x.first-1);
		}
	}
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
}
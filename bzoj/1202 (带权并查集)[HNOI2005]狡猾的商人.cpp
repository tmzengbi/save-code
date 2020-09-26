#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
int t,n,m;
int pre[maxn],sum[maxn];
int find(int x){
	if(x==pre[x]) return x;
	int rt=find(pre[x]);
	sum[x]+=sum[pre[x]];
	return pre[x]=rt;
}
bool merge(int x,int y,int d){
	if(find(x)==find(y)) return sum[y]-sum[x]==d;
	int k=sum[x]-sum[y]+d;
	x=find(x),y=find(y);
	if(x>y){swap(x,y);k=-k;}
	pre[y]=x;sum[y]=k;
	return true;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			pre[i]=i,sum[i]=0;
		bool ok=1;
		for(int i=1;i<=m;++i){
			int u,v,d;scanf("%d%d%d",&u,&v,&d);
			if(!merge(u-1,v,d)){
				ok=0;
			}
		}
		if(!ok) puts("false");
		else puts("true");
	}
}
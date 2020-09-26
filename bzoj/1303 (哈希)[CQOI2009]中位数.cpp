#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,b,a[maxn],t;
unordered_map<int,int>mp;
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==b) t=i;
	}
	ll ans=1;
	for(int i=t-1;i;--i){
		static int now=0;
		now+=a[i]>b?1:-1;
		if(!mp.count(now)) mp[now]=0;
		++mp[now];
		if(now==0) ++ans;
	}
	for(int i=t+1;i<=n;++i){
		static int now=0;
		now+=a[i]>b?1:-1;
		if(mp.count(-now)){
			ans+=mp[-now];
		}
		if(now==0) ++ans;
	}
	printf("%lld\n",ans);
}
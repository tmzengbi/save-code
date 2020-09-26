#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n,k,a[maxn],to;
map<int,int>mp;
int main(){
	scanf("%d%d",&n,&k);
	to=(1<<k)-1;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		a[i]=a[i]^a[i-1];
		mp[a[i]]=mp[a[i]^to]=0;
	}
	ll ans=1LL*(n+1)*n/2;
	for(int i=1;i<=n;++i){
		if(mp[a[i]]+(a[i]==0)<mp[a[i]^to]+((a[i]^to)==0)){
			ans-=mp[a[i]]+(a[i]==0);
			++mp[a[i]];
		} else {
			ans-=mp[a[i]^to]+((a[i]^to)==0);
			++mp[a[i]^to];
		}
	}
	printf("%lld\n",ans);
}
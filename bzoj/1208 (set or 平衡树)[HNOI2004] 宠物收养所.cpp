#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int maxn=8e4+10;
const int P=1000000;
set<int>s[2];
int n;
int solve(set<int>&s,int k){
	int sum=0x7fffffff;
	auto it=s.upper_bound(k);
	if(it!=s.end()) sum=*it-k;
	if(it!=s.begin()){
		if(k-*(--it)<=sum) sum=k-*it;
		else ++it;
	}
	s.erase(it);
	return sum;
}
int main(){
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int opt,k;scanf("%d%d",&opt,&k);
		if(s[opt^1].empty()) s[opt].insert(k);
		else{
			int sum=solve(s[opt^1],k);
			assert(sum>=0);
			ans=(ans+sum)%P;
		}
	}
	printf("%lld\n",ans);
}
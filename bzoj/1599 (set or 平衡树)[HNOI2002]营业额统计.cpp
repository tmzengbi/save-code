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
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int maxn=3e4+5000;
int n,a[maxn];
set<int>s;
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	ans=a[1];
	s.insert(a[1]);
	for(int i=2;i<=n;++i){
		auto it=s.upper_bound(a[i]);
		int sum=2e9;
		if(it!=s.end()){
			sum=min(sum,*it-a[i]);
		}
		if(it!=s.begin()){
			sum=min(sum,a[i]-*(--it));
		}
		s.insert(a[i]);
		ans+=sum;
	}
	printf("%d\n",ans);
}
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
const int maxn=1e3+10;
int dp[maxn][33];
int n,m,k,t,w[110],v[110],a[33],b[33];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i) scanf("%d",&w[i]);
		for(int i=1;i<=n;++i) scanf("%d",&v[i]);
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;++i){
			for(int j=m;j>=v[i];--j){
				int d;
				for(d=1;d<=k;++d){
					a[d]=dp[j][d];
					b[d]=dp[j-v[i]][d]+w[i];
				}
				a[d]=b[d]=-1;
				int z=1,x=1,y=1;
				while(z<=k&&(x<=k||y<=k)){
					if(a[x]<b[y]){
						dp[j][z]=b[y++];
					} else {
						dp[j][z]=a[x++];
					}
					if(dp[j][z]!=dp[j][z-1]) ++z;
				}
			}
		}
		printf("%d\n",dp[m][k]);
	}
}
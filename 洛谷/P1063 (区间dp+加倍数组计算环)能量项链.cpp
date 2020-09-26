 #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e2+10;
int n,dp[maxn][maxn],a[maxn];
int dfs(int l,int r){
	if(l+1==r) return a[l]*a[l+1]*a[l+2];
	if(l==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	for(int k=l;k<r;++k)
		dp[l][r]=max(dfs(l,k)+dfs(k+1,r)+a[l]*a[k+1]*a[r+1],dp[l][r]);
	return dp[l][r];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=n+1;i<=2*n;++i)
		a[i]=a[i-n];
	memset(dp,-1,sizeof dp);
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dfs(i,i+n-1));
	}
	printf("%d\n",ans);
}
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
const int maxn=2e3+10;
int n,h,d,t[maxn][maxn],dp[maxn][maxn],maxv[maxn];
int main(){
	scanf("%d%d%d",&n,&h,&d);
	for(int i=1;i<=n;++i){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int num;scanf("%d",&num);
			++t[num][i];
		}
	}
	int ans=0;
	for(int i=h;i>=1;--i){
		for(int j=1;j<=n;++j){
			dp[i][j]=dp[i+1][j]+t[i][j];
			if(h-i>=d){
				dp[i][j]=max(dp[i][j],maxv[d+i]+t[i][j]);
			}
			maxv[i]=max(maxv[i],dp[i][j]);
		}
		ans=max(ans,maxv[i]);
	}
	printf("%d\n",ans);
}
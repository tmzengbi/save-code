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
const int maxn=330+10;
int t,n,dp[maxn];
int main(){
	dp[0]=1;
	for(int i=1;i<=17;++i){
		int w=i*i;
		for(int j=w;j<=300;++j){
			dp[j]+=dp[j-w];
		}
	}
	while(scanf("%d",&n)==1&&n){
		printf("%d\n",dp[n]);
	}
}
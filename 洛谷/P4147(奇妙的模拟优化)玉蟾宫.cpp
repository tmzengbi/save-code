#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<functional>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int n,m,h[maxn][maxn],l[maxn][maxn],r[maxn][maxn],dpp[maxn][maxn],dp[maxn][maxn];
char s[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			char ss[3];scanf("%s",ss);
			s[i][j]=ss[0];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j]=='F'){
				h[i][j]=h[i-1][j]+1;
				l[i][j]=l[i][j-1]+1;
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=m;j;--j){
			if(s[i][j]=='F'){
				r[i][j]=r[i][j+1]+1;
			}
		}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j]=='F'){
				if(s[i-1][j]!='F'){
					dp[i][j]=l[i][j];
					dpp[i][j]=r[i][j];
				} else {
					dp[i][j]=min(dp[i-1][j],l[i][j]);
					dpp[i][j]=min(dpp[i-1][j],r[i][j]);
				}
				ans=max(ans,(dp[i][j]+dpp[i][j]-1)*h[i][j]*3);
			}
		}
	printf("%d\n",ans);
}
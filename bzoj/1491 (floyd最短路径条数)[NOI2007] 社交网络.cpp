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
const int maxn=1e2+10;
int n,m,mp[maxn][maxn];
long long c[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=m;++i){
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		mp[u][v]=mp[v][u]=d;
		c[u][v]=c[v][u]=1;
	}
	for(int i=1;i<=n;++i)
		mp[i][i]=0;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if(mp[i][j]>mp[i][k]+mp[k][j]){
					mp[i][j]=mp[i][k]+mp[k][j];
					c[i][j]=c[i][k]*c[k][j];
				} else if(mp[i][j]==mp[i][k]+mp[k][j]){
					c[i][j]+=c[i][k]*c[k][j];
				}
			}
	for(int k=1;k<=n;++k){
		double ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(k!=i&&k!=j&&mp[i][k]+mp[k][j]==mp[i][j]){
					ans+=1.0*c[i][k]*c[k][j]/c[i][j];
				}
		printf("%.3lf\n",ans);
	}
}
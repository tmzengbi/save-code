#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t,k;
int n,m;
int res[2010][2010];
int main() {
	scanf("%d%d",&t,&k);
	res[0][0]=1;
	for(int i=1;i<=2000;++i) {
		res[i][0]=res[i][i]=1;
		for(int j=1;j<i;j++)
			res[i][j]=(res[i-1][j]+res[i-1][j-1])%k;
	}
	for(int i=0;i<=2000;++i) {
		for(int j=0;j<=i;++j) {
			res[i][j]=!res[i][j];
			if(i>0) res[i][j]+=res[i-1][j];
			if(j>0) res[i][j]+=res[i][j-1];
			if(i!=j&&i>0&&j>0) res[i][j]-=res[i-1][j-1];
		}
	}
	while(t--) {
		scanf("%d%d",&n,&m);
		printf("%d\n",res[n][min(n,m)]);
	}
}
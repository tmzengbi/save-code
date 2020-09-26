#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<double,double>pii;
int n;
pii p[22];
double dp[1<<15][22];
double dis(pii a,pii b)
{
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double dfs(int x,int pre)
{
	if(x==0) return 0.0;
	if(dp[x][pre]) return dp[x][pre];
	double sum=2e18;
	for(int i=1;i<=n;i++)
		if(x&(1<<i-1))
			sum=min(sum,dis(p[pre],p[i])+dfs(x^(1<<i-1),i));
	return dp[x][pre]=sum;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&p[i].first,&p[i].second);
	printf("%.2lf\n",dfs((1<<n)-1,0));
//	system("pause");
}
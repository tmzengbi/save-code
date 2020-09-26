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
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=510;
map<pii,ll>M;
int k,a,b,t;      
ll c[33];
ll dfs(pii now)
{
	if(now.second<=0) return 0;
	if(!now.first) return 1;
	if(M.count(now)) return M[now];
	ll sum=0;
	if(now.second>=(1<<(now.first-1)))
		sum=c[now.first-1]+2*dfs(make_pair(now.first-1,now.second-(1<<(now.first-1)))); 
	else sum=dfs(make_pair(now.first-1,now.second));
	return M[now]=sum;
}
ll solve(int x)
{
	M.clear();
	return dfs(make_pair(k,x));
}
int main()
{
	int cas=0;
	c[0]=1;
	for(int i=1;i<=30;i++)
		c[i]=c[i-1]*3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&k,&a,&b);
		a=(1<<k)-a+1;
		b=(1<<k)-b+1;
		printf("Case %d: ",++cas);
		printf("%lld\n",solve(a)-solve(b-1));
	}
//	system("pause");
}
/*
3 0 1 1 3 1 8 3 3 7
*/
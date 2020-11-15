#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll n,m,a[22],sum=0,ans=0;
void dfs(int dep,int cho)
{
	if(cho==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(dep>n) return;
	dfs(dep+1,cho);
	sum^=a[dep];
	dfs(dep+1,cho+1);
	sum^=a[dep];
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0);
	printf("%lld\n",ans);
//	system("pause");
}
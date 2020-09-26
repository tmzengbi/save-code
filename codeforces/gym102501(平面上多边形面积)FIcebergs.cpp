#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
struct Node
{
	ll x,y;
}p[maxn];
ll calc(const Node&a,const Node&b)
{
	return a.x*b.y-a.y*b.x;
}
int main()
{
	int t;scanf("%d",&t);
	ll ans=0;
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld%lld",&p[i].x,&p[i].y);
		ll sum=0;
		for(int i=0;i<n;i++)
			sum+=calc(p[i],p[(i+1)%n]);
		ans+=abs(sum);
	}
	printf("%lld\n",ans/2);
//	system("pause");
}
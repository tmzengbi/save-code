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
int mp[2020][2020],n;
int main()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mp[i][j]);
			if(mp[i][j]) ans++;
		}
	ans*=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			ans+=max(mp[i][j]-mp[i][j-1],0)+max(mp[i][j]-mp[i][j+1],0);
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
			ans+=max(mp[i][j]-mp[i-1][j],0)+max(mp[i][j]-mp[i+1][j],0);
	}
	printf("%lld\n",ans);
//	system("pause");
}
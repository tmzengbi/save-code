#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<random>
#include<bitset>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=1e3+10;
bitset<maxn>mp[maxn];
int t,n;
int main()
{
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int num;scanf("%d",&num);
			mp[i].reset();
			mp[i][i]=1;
			for(int ii=1;ii<=num;ii++)
			{
				int k;scanf("%d",&k);
				mp[i][k]=1;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++) if(mp[i][k]==1)
				mp[i]|=mp[k];
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
				if(mp[j][i]) cnt++;
			ans+=1.0/cnt;
		}
		printf("Case #%d: %.5lf\n",++cas,ans);
	}
}
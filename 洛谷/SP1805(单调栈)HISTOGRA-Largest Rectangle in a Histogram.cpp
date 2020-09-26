#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int Index,h[maxn],n;
pii s[maxn];
ll ans[maxn],sum=0;
int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		Index=0;sum=0;
		for(int i=1;i<=n;i++) scanf("%d",&h[i]),ans[i]=-h[i];
		h[n+1]=0;
		for(int i=1;i<=n+1;i++)
		{
			while(Index&&s[Index-1].first>h[i])
			{
				int hi=s[--Index].first,id=s[Index].second;
				ans[id]+=(ll)hi*(i-id);
			}
			s[Index++]=make_pair(h[i],i);
		}
		Index=0;
		for(int i=n;i>=0;i--)
		{
			while(Index&&s[Index-1].first>h[i])
			{
				int hi=s[--Index].first,id=s[Index].second;
				ans[id]+=(ll)hi*(id-i);
			}
			s[Index++]=make_pair(h[i],i);
		}
		for(int i=1;i<=n;i++)
			sum=max(sum,ans[i]);
		printf("%lld\n",sum);
	}
}
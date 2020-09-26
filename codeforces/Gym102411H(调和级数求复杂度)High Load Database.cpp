#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int maxn=2e5+10;
const int N=1e6+10;
int n,a[maxn],q,ans[N],sum[maxn],Max;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),Max=max(Max,a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	scanf("%d",&q);
	while(q--)
	{
		int k;scanf("%d",&k);
		if(ans[k]){printf("%d\n",ans[k]);continue;}
		if(k<Max){printf("Impossible\n");continue;}
		int to=k,s=1;
		while(to<sum[n])
		{
			auto d=upper_bound(sum+1,sum+n+1,to)-sum;
			to=k+sum[d-1];
			s++;
		}
		printf("%d\n",ans[k]=s);
	}
//	system("pause");
}
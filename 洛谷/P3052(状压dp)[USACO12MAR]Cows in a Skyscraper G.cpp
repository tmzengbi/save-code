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
const int maxn=1<<18;
int n,w,dp[maxn],res[maxn],v[19];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	memset(dp,0x3f,sizeof dp);
	memset(res,128,sizeof res);
	dp[0]=0;res[0]=0;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				if(res[i]>=v[j])
				{
					if(dp[i|(1<<j)]>dp[i])
					{
						dp[i|(1<<j)]=dp[i];
						res[i|(1<<j)]=res[i]-v[j];
					}
					else if(dp[i|(1<<j)]==dp[i]) res[i|(1<<j)]=max(res[i|(1<<j)],res[i]-v[j]);
				}
				else if(dp[i|(1<<j)]>dp[i]+1)
				{
					dp[i|(1<<j)]=dp[i]+1;
					res[i|(1<<j)]=w-v[j];
				}
				else if(dp[i|(1<<j)]==dp[i]+1)
					res[i|(1<<j)]=max(res[i|(1<<j)],w-v[j]);
			}
		}
	printf("%d\n",dp[(1<<n)-1]);
//	for(int i=0;i<(1<<n);i++)
//		printf("%d %d\n",i,dp[i]);
//	system("pause");
}
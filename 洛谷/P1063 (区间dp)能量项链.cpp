#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,a[110],dp[110][110];
int add(int a1,int a2)
{
	if(a1+a2<=N)	return a1+a2;
	return (a1+a2)%N;
}
int selfadd(int n)
{
	return add(n,1);
}
int main()
{
	memset(dp,0,sizeof dp);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(int k=1;k<N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=i;;j=selfadd(j))
			{
				if(j==add(k,i))	break;
				dp[i][add(i,k)]=max(dp[i][j]+dp[selfadd(j)][add(i,k)]+a[i]*a[selfadd(j)]*a[selfadd(add(i,k))],dp[i][add(i,k)]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;i++)
		ans=max(ans,dp[i][add(i,N-1)]);
	printf("%d\n",ans);

//	while(1);;
}
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e9;
template<typename T>
T min(T a,T b,T c)
{
	return min(min(a,b),c);
}
int dp[55][55][3],n,c,rd[55],d[55][55],w[55];
int tot_w(int now,int to,int l,int r)
{
	if(now>to)swap(now,to);
	int t=d[now][to],sum=0;
	for(int i=1;i<l;i++)
		sum+=w[i];
	for(int i=r+1;i<=n;i++)
		sum+=w[i];
	return sum*t;
}
int main()
{
	memset(dp,0,sizeof dp);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&rd[i],&w[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			d[i][j]=rd[j]-rd[i];
	int ans=0;bool flag=false;	
	if(c==1)
	{	
		flag=true;
		for(int i=1;i<n;i++)
			ans+=tot_w(i,i+1,1,i);
	}
	if(c==n)
	{
		flag=true;
		for(int i=n;i>1;i--)
			ans+=tot_w(i,i-1,i,n);
	}
	if(flag){printf("%d\n",ans);return 0;}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			dp[i][j][1]=dp[i][j][2]=maxn;
	for(int i=1;i<=n;i++)
		dp[i][i][1]=dp[i][i][2]=0;
	for(int k=0;k<n;k++)
		for(int i=(c-k)>=0?c-k:0;i<=c&&i+k<=n;i++)
		{
			if(i>0)	dp[i-1][i+k][1]=min(dp[i][i+k][1]+tot_w(i,i-1,i,i+k),dp[i][i+k][2]+tot_w(i+k,i-1,i,i+k),dp[i-1][i+k][1]);
			if(i<n)	dp[i][i+k+1][2]=min(dp[i][i+k][2]+tot_w(i+k,i+k+1,i,i+k),dp[i][i+k][1]+tot_w(i,i+k+1,i,i+k),dp[i][i+k+1][2]);
		}
	ans=min(dp[1][n][1],dp[1][n][2]);
/*		for(int j=i+1;j<=n;j++)
			cout<<i<<" "<<j<<"\t"<<min(dp[i][j][1],dp[i][j][2])<<endl;
*/
	printf("%d\n",ans);
//	system("pause");
}
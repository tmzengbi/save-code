#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
template<typename T> 
T max(T a,T b,T c,T d)
{
	return max(max(a,b),max(c,d));
}
int n,x,y,z,M[10][10],dp[10][10][10][10];
int main()
{
	scanf("%d%d%d%d",&n,&x,&y,&z);
	while(x&&y&&z)
	{
		M[x][y]=z;
		scanf("%d%d%d",&x,&y,&z);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
				{
					dp[i][j][k][l]=max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]);
					if(i==k&&j==l) dp[i][j][k][l]+=M[i][j];
					else dp[i][j][k][l]+=M[i][j]+M[k][l];
				}
	printf("%d\n",dp[n][n][n][n]);
//	system("pause");
}
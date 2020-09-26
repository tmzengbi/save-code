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
const int maxn=710;
int dp[maxn][maxn];
int Next[maxn];
char s[maxn];
int getNext(char *s1,int len)
{
	Next[0]=-1;Next[1]=0;
	int j;
	for(int i=1;i<len;i++)
	{
		j=Next[i];
		while(j&&s1[i]!=s1[j]) j=Next[j];
		Next[i+1]=s1[i]==s1[j]?j+1:0;
	}
	int sum=0,i=len;
	int d=i-Next[i];
	if(i%d==0&&i>d) sum=d;
	return sum;
}
int dfs(int l,int r)
{
	if(dp[l][r]) return dp[l][r];
	if(l==r) return dp[l][r]=1;
	int sum=r-l+1;
	for(int i=l;i<r;i++)
		sum=min(sum,dfs(l,i)+dfs(i+1,r));
	int d=getNext(s+l,r-l+1);
	if(d) sum=min(sum,dfs(l,l+d-1));
	return dp[l][r]=sum;
}
int main()
{
	int n;
	scanf("%d%s",&n,s);
	printf("%d\n",dfs(0,n-1));
//	for(int i=0;i<n;i++)	
//		for(int j=0;j<n;j++)
//			printf("%d %d %d\n",i,j,dp[i][j]);
//	system("pause");
}
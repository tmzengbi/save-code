#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int now[10];
const int maxn=125*125*125;
char ss[15][6][5],s[15][6];
double dp[maxn];
const double eps=1e-7;
int Pow(int a,int b)
{
	int sum=1;
	for(;b;b>>=1)
	{
		if(b&1) sum=sum*a;
		if(b) a=a*a;
	}
	return sum;
}
int getnum()
{
	int sum=0;
	for(int i=0;i<9;i++)
		sum+=Pow(5,i)*now[i];
	return sum;
}
double dfs(int x)
{
	if(x==0) return 1.0;
	if(!(fabs(dp[x]+1.0)<eps)) return dp[x];
	double sum=0;int cnt=0;
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
		{
			if(!now[i]||!now[j]) continue;
			if(s[i][now[i]-1]==s[j][now[j]-1])
			{
				now[i]--;now[j]--;
				int k=getnum();
				cnt++;sum+=dfs(k);
				now[i]++;now[j]++;
			}
		}
	if(cnt==0) return dp[x]=0;
	return dp[x]=sum/cnt;
}
int main()
{
	while(scanf("%s",ss[0][0])==1)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<4;j++)
			{
				if(i||j) scanf("%s",ss[i][j]);
				s[i][j]=ss[i][j][0];
			}
		for(int i=0;i<maxn;i++)
			dp[i]=-1.0;
		for(int i=0;i<9;i++) now[i]=4;
	//	printf("%d %d\n",getnum(),maxn-1);
		printf("%lf\n",dfs(maxn-1));
	//	system("pause");
	}
}
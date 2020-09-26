#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1<<12,P=100000000;
int N,M,Map[13][13],k[13],dp[13][maxn];
bool t[13][maxn];
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&Map[i][j]);
			k[i]+=(Map[i][j]<<(M-j));
		}
	for(int j=1;j<=N;j++)
		for(int i=0;i<(1<<M);i++)
		{
			if((i&k[j])==i)
			{
				bool flag=true;
				int tmpi=i;
				while(tmpi)
				{
					if((tmpi&3)==3){flag=false;break;}
					tmpi>>=1;
				}
				if(flag)t[j][i]=true;
			}
		}
	for(int i=0;i<(1<<M);i++)
		if(t[1][i]) dp[1][i]=1;
	for(int s=1;s<N;s++)
	{
		for(int i=0;i<(1<<M);i++)
		{
			if(!t[s][i]) continue;
			int ii=(~i)&(maxn-1);
			for(int j=ii;;j=(j-1)&ii)
			{
				if(t[s+1][j]) dp[s+1][j]=(dp[s+1][j]+dp[s][i])%P;
				if(j==0) break;
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<M);i++)
		ans=(ans+dp[N][i])%P;
	printf("%d\n",ans);
//	system("pause");

}
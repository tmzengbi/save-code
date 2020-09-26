#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,m,K,Map[150][150],ans=1e9;
int min(int a,int b,int c){return min(min(a,b),c);}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=1e9;int sum=0;
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&Map[i][j]);
				if(Map[i][j]) sum++;
			}
		for(int i=1;i<=n;i++)
		{
			int tmp_ans=0;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int sum=0;
				for(int k=1;k<=m;k++)
					sum=sum+(Map[i][k]^Map[j][k]);
				tmp_ans+=min(sum,m-sum);
			}
			ans=min(tmp_ans,ans);
		}
		for(int i=1;i<=m;i++)
		{
			int tmp_ans=0;
			for(int j=1;j<=m;j++)
			{
				if(i==j) continue;
				int sum=0;
				for(int k=1;k<=n;k++)
					sum=sum+(Map[k][i]^Map[k][j]);
				tmp_ans+=min(sum,n-sum);
			}
			ans=min(tmp_ans,ans);
		}
		ans=min(ans,sum,n*m-sum);
		if(ans>K) ans=-1;
		printf("%d\n",ans);
	} 
}
/*
5 5 5
1 1 1 0 1 
0 1 1 1 1
1 0 1 1 1
1 1 1 0 0
1 1 1 0 1

5 5 10
0 1 1 1 1
1 0 1 1 1 
1 1 0 1 1
1 1 1 0 1
1 0 1 0 0

5 5 10
1 1 0 1 1
1 1 0 1 1
0 0 0 0 1
1 0 0 0 0
0 1 0 0 0
*/
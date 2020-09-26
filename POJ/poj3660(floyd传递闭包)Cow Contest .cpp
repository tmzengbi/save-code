#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int floyd[110][110],inout[110][2],N,M;
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		floyd[u][v]=1;
	}
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(floyd[i][k]&&floyd[k][j]) floyd[i][j]=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			inout[i][1]+=floyd[i][j];
			inout[j][0]+=floyd[i][j];
		}
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(inout[i][0]+inout[i][1]==N-1)
			ans++;
	}
	printf("%d\n",ans);
}
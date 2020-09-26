#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,M,a[510],b[510],f[510][510],pre[510][510];
void print(int n,int id)
{
	if(n==0)return;
	print(n-1,pre[n][id]);
	if(pre[n][id]!=id) 
		printf("%d ",b[id]);
}
void solve()
{
	for(int i=1;i<=N;i++)
	{
		int val=0,id=0;
		for(int j=1;j<=M;j++)
		{
			f[i][j]=f[i-1][j];
			pre[i][j]=j;
			if(a[i]==b[j]&&f[i][j]<val+1)
			{
				f[i][j]=val+1;
				pre[i][j]=id;
			}
			if(a[i]>b[j]&&val<f[i][j])
			{
				val=f[i][j];
				id=j;
			}
		}
	}
	int Max=0,id=0;
	for(int i=1;i<=M;i++)
	{
		if(Max<f[N][i])
		{
			Max=f[N][i];
			id=i;
		}
	}
	printf("%d\n",Max);
	print(N,id);
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",a+i);
	scanf("%d",&M);
	for(int j=1;j<=M;j++) scanf("%d",b+j);
	solve();
//	system("pause");
}
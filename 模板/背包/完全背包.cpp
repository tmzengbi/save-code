#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int f[210],w[210],c[210],M,N;
int main()
{
	scanf("%d%d",&M,&N);
	for(int i=1;i<=N;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=N;i++)
		for(int j=w[i];j<=M;j++)
			f[j]=max(f[j],f[j-w[i]]+c[i]);
	printf("max=%d\n",f[M]);
//	system("pause");
}
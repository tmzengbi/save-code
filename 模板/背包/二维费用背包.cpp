#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int M1,M2,N,f[110][161];
struct Node
{
	int m1,m2,c;
}n[1010];
int main()
{
	scanf("%d%d%d",&M1,&M2,&N);
	for(int i=1;i<=N;i++)
		scanf("%d%d%d",&n[i].m1,&n[i].m2,&n[i].c);
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=N;i++)
		for(int j=M1;j>=0;j--)
			for(int k=M2;k>=0;k--)
			{
				int t1=n[i].m1+j,t2=n[i].m2+k;
				if(t1>M1) t1=M1;
				if(t2>M2) t2=M2;
				f[t1][t2]=min(f[t1][t2],f[j][k]+n[i].c);
			}
	printf("%d\n",f[M1][M2]);
//	system("pause");
}
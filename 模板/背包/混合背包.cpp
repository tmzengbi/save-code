#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int f[210],w[110],c[110],M,N,mod[110];
int main()
{
	int cnt=0;
	scanf("%d%d",&M,&N);
	for(int i=1;i<=N;i++)
	{
		int V,W,S;
		scanf("%d%d%d",&V,&W,&S);
		if(S==0) {cnt++;mod[cnt]=1;w[cnt]=V;c[cnt]=W;continue;}
		for(int j=1;j<=S;j<<=1)
		{
			cnt++;
			w[cnt]=V*j;c[cnt]=W*j;
			S-=j;
		}
		if(S){cnt++;w[cnt]=V*S;c[cnt]=W*S;}
	}
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		if(mod[i]==0)
			for(int k=M;k>=w[i];k--)
				f[k]=max(f[k],f[k-w[i]]+c[i]);
		else
		{
			for(int k=w[i];k<=M;k++)
				f[k]=max(f[k],f[k-w[i]]+c[i]);
		}
	}
	printf("%d\n",f[M]);

//	system("pause");
}
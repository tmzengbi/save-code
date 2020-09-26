#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int f[6010],w[2510],c[2510],M,N;
int main()
{
	int cnt=0;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		int V,W,S;
		scanf("%d%d%d",&V,&W,&S);
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
		for(int k=M;k>=w[i];k--)
			f[k]=max(f[k],f[k-w[i]]+c[i]);
	}
	printf("%d\n",f[M]);

//	system("pause");
}
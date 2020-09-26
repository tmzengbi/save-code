#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int N,a[100010];
long long sum=0,ans1=0,ans2=0;
bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	if(N==1) printf("0\n");
	else
	{
		sort(a+1,a+N+1,cmp);
		for(int i=1;i<=N/2;i++) sum+=a[i]*2;
		if(N%2==0) sum-=a[N/2];
		sum-=a[N/2+1];
		for(int i=N;i>N/2+1;i--) sum-=a[i]*2;
		if(N%2) sum+=a[N/2+2];
		ans1=sum;
		sum=0;
		sort(a+1,a+N+1);
		for(int i=1;i<=N/2;i++) sum-=a[i]*2;
		if(N%2==0) sum+=a[N/2];
		sum+=a[N/2+1];
		for(int i=N;i>N/2+1;i--) sum+=a[i]*2;
		if(N%2) sum-=a[N/2+2];
		ans2=sum;
		printf("%lld\n",max(ans1,ans2));
	}
	system("pause");
}
/*
6
3 4 5 6 7 7
*/
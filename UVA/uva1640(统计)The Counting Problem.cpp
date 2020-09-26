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
const int maxn=1e5+10;
int mul[15]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int tx[15]={0,1,20,300,4000,50000,600000,7000000,80000000},ty[15]={1,1,10,190,2890,38890,488890,5888890,68888890};
void solve(int x,int a[])
{
//	int a[10];
	memset(a,0,sizeof(int)*10);
	if(x<0) return;
	int tmp[10]={0},now=0,cnt=0,d[15],Index=0;
	{
		int tmp=x;
		do
		{
			d[Index++]=tmp%10;
			tmp/=10;
		}while(tmp);
	}
	while(now*10+9<=x)
		now=now*10+9,cnt++;
	a[0]+=ty[cnt];
	for(int i=1;i<10;i++) a[i]+=tx[cnt];
	if(now==x) return;
//	while(now+mul[cnt]>x) cnt--;
	for(int i=cnt;i>=0;i--)
	{
		for(;now+mul[i]<=x;now+=mul[i])
		{
			int m=((now+mul[i])/mul[i])%10;
			tmp[m]++;
			for(int k=0;k<10;k++) a[k]+=tmp[k]*mul[i]+((i)?i*mul[i-1]:0);
			tmp[m]--;
		}
		tmp[d[i]]++;
	}
}
int main()
{
	int x,y,a[10],b[10];
	while(scanf("%d%d",&x,&y)==2&&(x||y))
	{
		if(x>y) swap(x,y);
		solve(x-1,a);solve(y,b);
		printf("%d",b[0]-a[0]);
		for(int i=1;i<10;i++)
			printf(" %d",b[i]-a[i]);
		puts("");
	}
//	system("pause");
}
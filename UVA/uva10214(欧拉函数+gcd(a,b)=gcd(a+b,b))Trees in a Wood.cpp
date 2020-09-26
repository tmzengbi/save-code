#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=2000;
int auler[2010],n,m,bk[2010];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	auler[1]=1;
	for(int i=2;i<=maxn;i++) if(!auler[i])
		for(int j=i;j<=maxn;j+=i)
		{
			if(!auler[j]) auler[j]=j;
			auler[j]=auler[j]/i*(i-1);
		}
	while(scanf("%d%d",&n,&m)==2&&(n||m))
	{
		if(n>m) swap(n,m);
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			bk[i]=m/i;
			sum+=(ll)bk[i]*auler[i];
			for(int j=bk[i]*i+1;j<=m;j++)
				if(gcd(i,j)==1) sum++;
		}
		sum=sum*4+4;
		ll del=(ll)(n*2+1)*(m*2+1)-1;
		double realans=(double)sum/del;
		printf("%.7lf\n",realans);
	}
	//system("pause");
}
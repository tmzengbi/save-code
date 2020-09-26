#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<double,double>pdd;
const double eps=1e-8;
int t,n,m,dp[1<<18],siz[1<<18],d[20][20];
pdd p[20];
inline int lowbit(int x){return x&(-x);}
double calc(pdd x,pdd y)
{
	return x.first*y.second-x.second*y.first;
}
double calc(double A,double B,pdd x)
{
	return A*x.first*x.first+B*x.first;
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<(1<<18);i++)
		siz[i]=siz[i^lowbit(i)]+1;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].first,&p[i].second);
		memset(d,0,sizeof d);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				double co[6]={p[i].first*p[i].first,p[i].first,p[i].second,p[j].first*p[j].first,p[j].first,p[j].second};
				pdd ma[2];
				ma[0]=make_pair(co[0],co[1]);
				ma[1]=make_pair(co[3],co[4]);
				pdd ma2[2];
				ma2[0]=make_pair(co[0],co[2]);
				ma2[1]=make_pair(co[3],co[5]);
				pdd ma1[2];
				ma1[0]=make_pair(co[2],co[1]);
				ma1[1]=make_pair(co[5],co[4]);
				if(fabs(calc(ma[0],ma[1]))<eps) continue;
				double A=calc(ma1[0],ma1[1])/calc(ma[0],ma[1]),B=calc(ma2[0],ma2[1])/calc(ma[0],ma[1]);
				if(A>0||fabs(A)<eps) continue;
				int s=(1<<i-1)^(1<<j-1);
				for(int k=1;k<=n;k++)
					if(i==k||j==k) continue;
					else if(fabs(calc(A,B,p[k])-p[k].second)<eps) s=s^(1<<k-1);
				d[i][j]=s;
			}
		memset(dp,0x3f,sizeof dp);
		dp[0]=0;
		int now=0;
		for(int i=1;i<(1<<n);i++)
		{
			if(!(i&i-1)) now++;
			dp[i]=dp[i^(1<<now-1)]+1;
			for(int j=1;j<now;j++)
				if(d[j][now]) dp[i]=min(dp[(i^(1<<now-1)|d[j][now])^(d[j][now])]+1,dp[i]);
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
//	system("pause");
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
set<int> s;
vector<int> ys[100010];
int vis[100010];
void yss()
{
	for(int i=1;i<=10000;i++)
	{
		for(int j=1;j<=i;j++)
			if(i%j==0) ys[i].push_back(j);
	}
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	yss();
/*
	for(int i=1;i<=10000;i++)
	{
		int sum=0;double ans;
//		printf("%d ",i);
		int fz=0,fm=1,len=ys[i].size();
		for(int j=0;j<ys[i].size();j++)
		{
			sum+=ys[i][j];
			int k=ys[i][j];
			fz=fz*k+fm;fm=fm*k;
			int r=gcd(fz,fm);
			fz=fz/r;fm=fm/r;
		}
//		ans=double(sum)/ys[i].size();
		ans=double(len)*fm/fz;
		if((ans-(int)ans)==0)
			printf("%d %lf\n",i,ans);
//		printf("\n");
	}
*/

	while(true)
	{
		int k;double meyong;scanf("%d%lf",&k,&meyong);
		int sum=0;double ans=0;
		int len=ys[k].size();
		for(int i=0;i<ys[k].size();i++)
		{
//			printf("%d ",ys[k][i]);
			sum+=ys[k][i];
		}
		ans=(double)sum/len;
		printf("%d %lf\n",k,ans);
	}

	system("pause");
}
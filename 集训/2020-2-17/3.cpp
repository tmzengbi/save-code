#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int n;
double ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		ans+=1.0/i;
	printf("%.12lf\n",ans);
}
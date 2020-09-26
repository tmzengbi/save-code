#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
double a[10010],s0=1.0,s1=0.0;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		s0=1.0;s1=0.0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			s1=s1+(s0-s1)*a[i];s0=s0*(1-a[i]);
//			cout<<s0<<" "<<s1<<endl;
			if(s0<=s1)	break;
		}
		printf("%.12lf\n",s1);
	}
//	while(1);
}
/*
2
3
0.100000 0.200000 0.900000
3
0.100000 0.300000 0.800000

2 4
0.1 0.2 0.3 0.4
*/
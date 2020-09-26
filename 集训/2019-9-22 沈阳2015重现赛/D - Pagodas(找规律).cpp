#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		int n,i,j;
		scanf("%d%d%d",&n,&i,&j);
		int r=gcd(i,j);
		printf("Case #%d: ",cas);
		if((n/r)%2)	printf("Yuwgna\n");
		else printf("Iaka\n");
	}
//	system("pause");
}
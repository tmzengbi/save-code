#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int t,n,a,b,c;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&n);
		int Max=max(max(a,b),c);
		n-=Max-a+Max-b+Max-c;
		if(n<0) printf("NO\n");
		else
		{
			if(n%3) printf("NO\n");
			else printf("YES\n");
		}
	}
//	system("pause");
}

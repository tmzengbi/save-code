#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		while(n%2==0) n=n/2;
		while(n%5==0) n=n/5;
		if(n>1) printf("Yes\n");
		else printf("No\n");
	}
}
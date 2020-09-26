#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);getchar();
	for(int i=1;i<=n;i++)
	{
		char ch;scanf("%c",&ch);
		if(ch=='G') ans++;
	}
	printf("%d\n",ans);
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int k,a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	sort(a+1,a+11);
	int ans=0;
	for(int i=1;i<=10;i++)
		if(k+30>=a[i]) ans++;
		else break;
	printf("%d\n",ans);
}
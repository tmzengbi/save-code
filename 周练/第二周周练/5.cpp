#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[100010];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		printf("%d ",a[r--]);
		if(l>r) break;
		printf("%d ",a[l++]);
	}
}
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[15],vis[15],ans=0;
bool check(int dep)
{
	for(int i=1;i<dep;i++)
		if(abs(a[dep]-a[i])==dep-i)return false;
	return true;
}
void print()
{
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void dfs(int dep)
{
	if(!check(dep-1))	return;
	if(dep>n)
	{
		if(ans<3)
			print();
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[dep]=i;vis[i]=true;
			dfs(dep+1);
			vis[i]=false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	memset(vis,false,sizeof vis);
	dfs(1);
	printf("%d",ans);
	system("pause");
}
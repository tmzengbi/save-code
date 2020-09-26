#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,a[210],ans=0;
/*void print(int x)
{
	for(int i=1;i<x;i++)
		printf("%d ",a[i]);
	printf("\n");
}
*/
void dfs(int x,int sum)
{
	if(sum>n)return;
	if(x==k+1&&sum==n)
	{
//		print(x);
		ans++;
		return;
	}
	if(x>k)return;
	for(int i=a[x-1];i<=n;i++)
	{
		if((n-sum)<i*(k-x+1))	break;
		if((n-sum)>n*(k-x+1))	break;
		a[x]=i;
		dfs(x+1,sum+i);
	}
}
int main()
{
	a[0]=1;
	scanf("%d%d",&n,&k);
	dfs(1,0);
	printf("%d\n",ans);
	system("pause");
}
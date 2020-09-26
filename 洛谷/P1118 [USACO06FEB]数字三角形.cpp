#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int N,SUM,mul[15],a[15],vis[15];
void dfs(int x,int sum)
{
	if(x==1+N&&sum==SUM)
	{
//		print();
		for(int i=1;i<x;i++)
			printf("%d ",a[i]);
//		cout<<endl;
		exit(0);
	}
	if(sum>SUM)	return;
	if(x>N)	return;
	for(int i=1;i<=N;i++)
	{
		if((sum+i*mul[x-1])>SUM)	break;
		if(vis[i])	continue;
		a[x]=i;vis[i]=true;
		dfs(x+1,sum+i*mul[x-1]);
		vis[i]=false;
	}
}
int main()
{
	memset(vis,false,sizeof vis);
	a[0]=1;
	scanf("%d%d",&N,&SUM);
	mul[0]=mul[N-1]=1;
	for(int i=1;i<N-1;i++)
		mul[i]=mul[i-1]*(N-i)/i;
	dfs(1,0);

//	system("pause");
}
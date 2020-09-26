#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
struct N
{
	int a,rank,c;
}k[50010];
bool vis[50010];
bool cmp1(N n1,N n2)
{
	return n1.a<n2.a;
}
bool cmp2(N n1,N n2)
{
	return n1.c<n2.c;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,false,sizeof vis);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			k[i].c=i;
			scanf("%d",&k[i].a);
		}
		sort(k+1,k+n+1,cmp1);
		int Index=1;k[1].rank=1;
		for(int i=2;i<=n;i++)
		{
			if(k[i].a==k[i-1].a)	k[i].rank=Index;
			else k[i].rank=++Index;
		}
		sort(k+1,k+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(!vis[k[i].rank])
			{
				printf("%d ",k[i].a);
				vis[k[i].rank]=true;
			}
		}
		printf("\n");

	}	
//	system("pause");
}
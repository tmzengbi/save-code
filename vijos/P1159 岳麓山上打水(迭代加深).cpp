#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int q,p,idt=1,a[110],b[110];
bool vis[110];
void print()
{
	printf("%d ",idt);
	for(int i=1;i<=idt;i++)
		printf("%d ",b[i]);

	exit(0);
}
bool dp()
{
	int Dp[20010]={0};
	Dp[0]=1;
	for(int i=1;i<=idt;i++)
	{
		for(int j=0;j<=q;j++)
		{
			if(Dp[j]==1)
			{
				for(int k=1;;k++)
				{
					if((j+k*b[i])==q) return true;
					else if((j+k*b[i])>q) break;
					Dp[j+k*b[i]]=1;
				}
			} 
		}
	}
//	for(int i=1;i<=q;i++)
//		cout<<Dp[i]<<" ";
//	cout<<endl;
	
	return false;
}
bool dfs(int dep)
{
	if(dep>idt)
	{
		if(dp())
		{
			print();
			return true;
		}
		else return false;
	}
	int ok=false;
	for(int i=1;i<=p;i++)
	{
		if(!vis[i]&&a[i]>b[dep-1])
		{
			vis[i]=true;
			b[dep]=a[i];
			if(dfs(dep+1)) ok=true;
			vis[i]=false;
		}
	}
	return ok;
}
int main()
{
	scanf("%d%d",&q,&p);
	for(int i=1;i<=p;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+p+1);
	b[0]=0;
	while(1)
	{
		if(dfs(1)) break;
		idt++;
	}

}
/*
16
3
3
5
7
*/
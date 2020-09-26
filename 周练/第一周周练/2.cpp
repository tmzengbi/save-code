#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,a[2010],ans=0;
bool vis[2010];
int main()
{
	memset(vis,false,sizeof vis);
	scanf("%d",&N);
	for(int i=1;i<=N*2;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=N*2;i++)
	{
		if(!vis[i])
		{
			for(int j=i+1;j<=N*2;j++)
			{
				if(a[i]==a[j]) {vis[j]=true;break;}
				if(!vis[j]) ans++;
			}
		}
	}
	printf("%d\n",ans);
}
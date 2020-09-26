#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int s1[1000010],s2[1000010],Index1=0,Index2=0,sum[1000010],ans[1000010];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int mod,k;
		scanf("%d",&mod);
		if(mod==1)
		{
			scanf("%d",&k);
			s1[++Index1]=k;
			sum[Index1]=k+sum[Index1];
			ans[Index1]=max(ans[Index1-1],sum[Index1]);
		}
		else if(mod==2)
		{
			if(Index1) Index1--;
		}
		else if(mod==3)
		{
			if(Index1) s2[++Index2]=s1[Index1--];
		}
		else if(mod==4)
		{
			if(Index2)
			{
				s1[++Index1]=s2[Index2--];
				sum[Index1]=s1[Index1]+sum[Index1-1];
				ans[Index1]=max(ans[Index1-1],sum[Index1]);
			}
		}
		else if(mod==5)
		{
			scanf("%d",&k);
			if(k>Index1) k=Index1;
			printf("%d\n",ans[k]);
		}
/*
		else if(mod==6) 
		{
			for(int i=1;i<=Index1;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
		else if(mod==7)
		{
			for(int i=1;i<=Index1;i++)
				printf("%d ",sum[i]);
			printf("\n");
		}
		else if(mod==8)
		{
			for(int i=1;i<=Index1;i++)
				printf("%d ",s1[i]);;
			printf("cur ");
			for(int i=Index2;i;i--)
				printf("%d ",s2[i]);
			printf("\n");
		}
*/
	}
//	system("pause");
}
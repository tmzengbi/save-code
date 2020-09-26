#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,m,sum=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=m;j++)
		{
			int a;scanf("%d",&a);
			sum+=a*a;
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);

//	system("pause");
}
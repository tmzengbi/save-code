#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int f[3]={-1,0,1};
int t,a[3];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<3;i++)
			scanf("%d",&a[i]);
		ll ans=1e18L;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
				{
					int a1=a[0]+f[i],a2=a[1]+f[j],a3=a[2]+f[k];
					ans=min(ans,(ll)abs(a1-a2)+abs(a1-a3)+abs(a2-a3));
				}
		printf("%lld\n",ans);
	}
//	system("pause");
}
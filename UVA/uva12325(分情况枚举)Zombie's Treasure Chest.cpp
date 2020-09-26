#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
ll T,n,a[2],b[2];
const int Max=1000000;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int cas=0;
	scanf("%lld",&T);
	while(T--)
	{
		ll ans=0;
		scanf("%lld%lld%lld%lld%lld",&n,&a[0],&b[0],&a[1],&b[1]);
		if(n/a[0]<=Max)
		{
			for(ll i=0;i<=n/a[0];i++)
			{
				ll d=n-a[0]*i,sum=b[0]*i;
				sum+=d/a[1]*b[1];
				if(sum>ans) ans=sum;
			}
		}
		else if(n/a[1]<=Max)
		{
			for(ll i=0;i<=n/a[1];i++)
			{
				ll d=n-a[1]*i,sum=b[1]*i;
				sum+=d/a[0]*b[0];
				if(sum>ans) ans=sum;
			}
		}
		else
		{
			ll tmp[2]={a[1]*b[0],a[0]*b[1]};
			if(tmp[0]<tmp[1])
			{
				for(ll i=0;i<a[1];i++)
				{
					ll d=n-a[0]*i,sum=b[0]*i;
					sum+=d/a[1]*b[1];
					if(sum>ans) ans=sum;
				}
			}
			else
			{
				for(ll i=0;i<a[0];i++)
				{
					ll d=n-a[1]*i,sum=b[1]*i;
					sum+=d/a[0]*b[0];
					if(sum>ans) ans=sum;
				}
			}	
		}
		printf("Case #%d: %lld\n",++cas,ans);
	}
//	system("pause");
}

/*
2
100 1 1 2 2
100 34 34 5 3
*/
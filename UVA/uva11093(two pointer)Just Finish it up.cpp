#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int a[maxn],b[maxn],c[maxn],t,n,cas=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) c[i]=a[i]-b[i];
		ll sum=0;
		for(int i=1;i<=n;i++)
			sum+=c[i];
		printf("Case %d: ",++cas);
		if(sum<0) printf("Not possible\n");
		else
		{
			printf("Possible from station ");
			int l=1,r=1;ll s=0;
			while(l+n!=r)
			{
				s+=c[r++];
				while(s<0) s-=c[l++];
			}
			printf("%d\n",l);
		}
	}
//	system("pause");
}
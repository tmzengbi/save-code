#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
ll n,a[33],k[33][33],pre[33][33],cnt=0,ans[33];
ll ser(int l,int r)
{
	if(k[l][r]) return k[l][r];
	if(l==r) return a[l];
	if(l>r) return 1;
	ll Max=0,root;
	for(int i=l;i<=r;i++)
	{
		ll k1=ser(l,i-1)*ser(i+1,r)+a[i];
		if(Max<k1)
		{
			Max=k1;
			root=i;
			pre[l][r]=i;
		}
	}
	return (k[l][r]=Max);
}
void putpre(int l,int r)
{
	if(l==r){printf(" %lld",l);return;}
	if(l>r) return;
	int i=pre[l][r];
	printf(" %lld",i);
	putpre(l,i-1);
	putpre(i+1,r);
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	printf("%lld\n",ser(1,n));
	printf("%lld",pre[1][n]);
	putpre(1,pre[1][n]-1);putpre(pre[1][n]+1,n);
	printf("\n");
//	system("pause");
}
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
#include<bitset>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100010;
const int Block=510;
const int P=10007;
int a[maxn],belong[maxn],le[Block],ri[Block],tagmul[Block],tagadd[Block];
int n,bk;
//遇事不决可以释放tag
void release(int block)
{
	for(int i=le[block];i<=ri[block];i++)
		a[i]=(a[i]*tagmul[block]+tagadd[block])%P;
	tagmul[block]=1;tagadd[block]=0;
}
void maintain(int l,int r,int c,int opt)
{
	release(belong[l]);
	for(int i=l;i<=min(r,ri[belong[l]]);i++)
	{
		if(opt) a[i]=a[i]*c%P;
		else a[i]=(a[i]+c)%P;
	}
	if(belong[l]!=belong[r])
	{
		release(belong[r]);
		for(int i=le[belong[r]];i<=r;i++)
			if(opt) a[i]=a[i]*c%P;
			else a[i]=(a[i]+c)%P;
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
	{
		if(opt)
		{
			tagmul[i]=tagmul[i]*c%P;
			tagadd[i]=tagadd[i]*c%P;
		}
		else tagadd[i]=(tagadd[i]+c)%P;
	}
}
int main()
{
	scanf("%d",&n);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;
		tagmul[i]=1;
	}
	for(int cas=1;cas<=n;cas++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		switch(opt)
		{
		case 0:maintain(l,r,c,0);break;
		case 1:maintain(l,r,c,1);break;
		case 2:printf("%lld\n",((ll)a[r]*tagmul[belong[r]]+tagadd[belong[r]])%P);break;
		}
	}
//	system("pause");
}
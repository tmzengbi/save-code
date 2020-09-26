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
const int maxn=50010;
const int Block=510;
int belong[maxn],tag[Block],a[maxn],n,bk;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bk+1;
	for(int cas=1;cas<=n;cas++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt==0)
		{
			for(int i=l;i<=min(r,belong[l]*bk);i++) a[i]+=c;
			if(belong[l]!=belong[r])
				for(int i=(belong[r]-1)*bk+1;i<=r;i++) a[i]+=c;
			for(int i=belong[l]+1;i<=belong[r]-1;i++) tag[i]+=c;
		}
		else printf("%d\n",tag[belong[r]]+a[r]);
	}
//	system("pause");
}
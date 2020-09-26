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
int belong[maxn],tag[Block],a[maxn],n,bk,b[Block][Block],numofblocks;
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("a1c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bk=(int)sqrt(n);
	numofblocks=n/bk;
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/bk+1;
		b[belong[i]][i-(belong[i]-1)*bk]=a[i];
	}
	for(int i=1;i<=numofblocks;i++)
		sort(b[i]+1,b[i]+bk+1);
	for(int cas=1;cas<=n;cas++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt==0)
		{
			for(int i=l;i<=min(r,belong[l]*bk);i++) a[i]+=c;
			if(belong[l]<=numofblocks)
			{
				for(int i=(belong[l]-1)*bk+1;i<=belong[l]*bk;i++)
					b[belong[l]][i-(belong[l]-1)*bk]=a[i];
				sort(b[belong[l]]+1,b[belong[l]]+bk+1);
			}
			if(belong[l]!=belong[r])
			{
				for(int i=(belong[r]-1)*bk+1;i<=r;i++) a[i]+=c;
				if(belong[r]<=numofblocks)
				{
					for(int i=(belong[r]-1)*bk+1;i<=belong[r]*bk;i++)
						b[belong[r]][i-(belong[r]-1)*bk]=a[i];
					sort(b[belong[r]]+1,b[belong[r]]+bk+1);
				}
			}
			for(int i=belong[l]+1;i<=belong[r]-1;i++) tag[i]+=c;
		}
		else
		{
			c=c*c;
			int ans=0;
			for(int i=l;i<=min(r,belong[l]*bk);i++) if(a[i]+tag[belong[i]]<c) ans++;
			if(belong[l]!=belong[r])
				for(int i=(belong[r]-1)*bk+1;i<=r;i++) if(a[i]+tag[belong[i]]<c) ans++;
			for(int i=belong[l]+1;i<=belong[r]-1;i++)
			{
				int now=c-tag[i];
				ans+=lower_bound(b[i]+1,b[i]+bk+1,now)-b[i]-1;
			}
			
			printf("%d\n",ans);
		}
	}
//	system("pause");
}
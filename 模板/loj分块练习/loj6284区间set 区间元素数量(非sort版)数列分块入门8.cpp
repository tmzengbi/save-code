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
int a[maxn],belong[maxn],le[Block],ri[Block],tag[Block];
int n,bk,numofblocks;
void release(int block)
{
	if(tag[block]==-1) return;
	for(int i=le[block];i<=ri[block];i++) a[i]=tag[block];
	tag[block]=-1;
}
int maintain(int l,int r,int c)
{
	int ans=0;
	release(belong[l]);
	for(int i=l;i<=min(r,ri[belong[l]]);i++)
	{
		if(a[i]==c) ans++;
		else a[i]=c;
	}
	if(belong[l]!=belong[r])
	{
		release(belong[r]);
		for(int i=le[belong[r]];i<=r;i++)
		{
			if(a[i]==c) ans++;
			else a[i]=c;
		}
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
	{
		if(tag[i]==-1)
		{
			for(int j=le[i];j<=ri[i];j++)
			{
				if(a[j]==c) ans++;
				a[j]=c;
			}
		}
		else if(tag[i]==c) ans+=bk;
		tag[i]=c;
	}
	return ans;
}
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bk=(int)sqrt(n);
	numofblocks=n/bk;
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;	
		tag[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		printf("%d\n",maintain(l,r,c));
	}
//	system("pause");
}
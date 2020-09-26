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
int a[maxn],belong[maxn],le[Block],ri[Block],tag[Block],b[Block][Block];
int n,bk,numofblocks;
void release(int block)
{
	if(tag[block]==-1) return;
	for(int i=le[block];i<=ri[block];i++) a[i]=tag[block];
	tag[block]=-1;
}
void maintainarrayb(int block)
{
	for(int i=le[block],j=1;i<=ri[block];i++,j++)
		b[block][j]=a[i];
	sort(b[block]+1,b[block]+bk+1);
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
	if(belong[l]<=numofblocks)
		maintainarrayb(belong[l]);
	if(belong[l]!=belong[r])
	{
		release(belong[r]);
		for(int i=le[belong[r]];i<=r;i++)
		{
			if(a[i]==c) ans++;
			else a[i]=c;
		}
		if(belong[r]<=numofblocks)
			maintainarrayb(belong[r]);
	}
	for(int i=belong[l]+1;i<=belong[r]-1;i++)
	{
		if(tag[i]==-1)
			ans+=upper_bound(b[i]+1,b[i]+bk+1,c)-lower_bound(b[i]+1,b[i]+bk+1,c);
		else if(tag[i]==c) ans+=bk;
		tag[i]=c;
	}
	return ans;
}
inline int read()
{
    int x=0,f=1;
	char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("out.txt","w",stdout);
/*
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
*/
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	bk=(int)sqrt(n);
	numofblocks=n/bk;
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/bk+1;
		b[belong[i]][i-(belong[i]-1)*bk]=a[i];
	}
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;	
		tag[i]=-1;
	}
	for(int i=1;i<=numofblocks;i++)
		sort(b[i]+1,b[i]+bk+1);
	for(int i=1;i<=n;i++)
	{
		int l,r,c;
//		scanf("%d%d%d",&l,&r,&c);
		l=read();r=read();c=read();
		printf("%d\n",maintain(l,r,c));
	}
//	system("pause");
}
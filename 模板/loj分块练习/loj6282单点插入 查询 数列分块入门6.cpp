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
int a[maxn],siz[Block],bk,numofblocks,n;
vector<int>b[Block];
int main()
{
	scanf("%d",&n);
	bk=(int)sqrt(n);numofblocks=n/bk;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int block=(i-1)/bk+1;
		b[block].push_back(a[i]);
		siz[block]++;
	}
	for(int cas=1;cas<=n;cas++)
	{
		int opt,l,r,c;
		scanf("%d%d%d%d",&opt,&l,&r,&c);
		if(opt==0)
		{
			int now=0,nowblocks=1;
			while(now+siz[nowblocks]<l) now+=siz[nowblocks++];
			b[nowblocks].insert(b[nowblocks].begin()+l-now-1,r);
			siz[nowblocks]++;
		}
		else
		{
			int now=0,nowblocks=1;
			while(now+siz[nowblocks]<r) now+=siz[nowblocks++];
			printf("%d\n",b[nowblocks][r-now-1]);
		}
	}
//	system("pause");
}
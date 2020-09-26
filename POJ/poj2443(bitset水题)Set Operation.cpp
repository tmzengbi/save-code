#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<bitset>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=1e4+10;
bitset<1010>b[maxn];
int n,q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int num;scanf("%d",&num);
		for(int ii=1;ii<=num;ii++) 
		{
			int k;scanf("%d",&k);
			b[k][i]=1;
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if((b[x]&b[y]).any()) puts("Yes");
		else puts("No");
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e7;
int ans[maxn+10];
void presol()
{
	int to=maxn/2+1;
	for(int i=1;i<=to;i++)				//c
		for(int j=i+i;j<=maxn;j+=i)		//a
		{
			int b=j-i;
			if((j^b)==i) ans[j]++;
		}
	for(int i=1;i<=maxn;i++)
		ans[i]+=ans[i-1];
}
int main()
{
	presol();
	int t,x;scanf("%d",&t);
	while(t--)
	{
		static int cas=0;
		scanf("%d",&x);
		printf("Case %d: %d\n",++cas,ans[x]);
	}
//	system("pause");
}
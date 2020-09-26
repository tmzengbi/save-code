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
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
const int maxn=1010*1010;
int t,n,Index=0;
ull a,b;
pii k[maxn];
map<pii,int>mp;
int calc(int m)
{
	int x=a%m;ll sum=1;
	for(;b;b>>=1)
	{
		if(b&1) sum=sum*x%m;
		if(b)x=x*x%m;
	}
	return (int)sum;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		Index=0;
		scanf("%llu%llu%d",&a,&b,&n);
		pii now(1%n,1%n);
		mp.clear();
		while(!mp.count(now))
		{
			k[Index++]=now;
			mp[now]=1;
			int f=now.second,s=now.first+now.second;
			now.first=f;now.second=s%n;
		}
		int c=calc(Index);
		if(!c) c+=Index;
		printf("%d\n",k[c-1].first);
	}
//	system("pause");
}
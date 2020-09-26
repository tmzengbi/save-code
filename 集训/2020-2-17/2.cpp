#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n,s,k;
map<int,int>M;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		M.clear();
		scanf("%d%d%d",&n,&s,&k);
		for(int i=1;i<=k;i++)
		{
			int num;scanf("%d",&num);
			M[num]=1;
		}
		int now1=s,now2=s;
		while(now1&&M.find(now1)!=M.end())
			now1--;
		while(now2<=n&&M.find(now2)!=M.end())
			now2++;
		int ans=2e9;
		if(now2<=n) ans=min(ans,now2-s);
		if(now1) ans=min(ans,s-now1);
		printf("%d\n",ans);

	}
//	system("pause");
}
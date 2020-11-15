#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
using namespace std;
const int maxn=1e5+10;
int n,m,k,dis[maxn],ans[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		dis[i]=x+abs(y-m-1);
//		printf("%d\n",dis[i]);
	}
	sort(dis+1,dis+k+1);
	for(int i=1;i<=k;i++)
		ans[i]=max(ans[i-1]+1,dis[i]);
	printf("%d\n",ans[k]);
//	system("pause");
}
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
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int f[33],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		int s=0;
		for(int j=0;j<=30;j++)
			if(k&(1<<j)) s=max(s,f[j]+1);
		for(int j=0;j<=30;j++)
			if(k&(1<<j)) f[j]=s;
	}
	int ans=0;
	for(int i=0;i<=30;i++)
		ans=max(ans,f[i]);
	printf("%d\n",ans);
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1<<10;
int mp[110],n,m,all,dp[110][60][60],num[1<<10];
vector<int>p(66);
bool le[maxn];
char mm[110][12];
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	scanf("%d%d",&n,&m);
	all=(1<<m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",mm[i]+1);
		for(int j=1;j<=m;j++)
			mp[i]|=((mm[i][j]=='P')?1:0)<<j-1;
	}
	int cnt=0;
	for(int i=0;i<all;i++)
	{
		int pre=-100;
		bool ok=1;
		for(int j=0;j<=10;j++)
			if(i&(1<<j))
			{
				num[i]++;
				if(j-pre<3) ok=false;
				pre=j;
			}
		le[i]=ok;
		if(ok) p[cnt++]=i;
	}
	if(n==1)
	{
		int ans=0;
		for(int i=0;i<cnt;i++)
			if((p[i]|mp[1])==mp[1]) ans=max(ans,num[p[i]]);
		printf("%d\n",ans);
		return 0;
	}
	for(int i=0;i<cnt;i++)
		for(int j=0;j<cnt;j++)
		{
			if((p[i]|mp[2])!=mp[2]||(p[j]|mp[1])!=mp[1]) continue;
			if(p[i]&p[j]) continue;
			dp[2][i][j]=max(dp[2][i][j],num[p[i]]+num[p[j]]);
		}
	int ans=0;
	for(int i=3;i<=n;i++)
		for(int j=0;j<cnt;j++)
			for(int k=0;k<cnt;k++)
				for(int s=0;s<cnt;s++)
				{
					if((p[s]|mp[i])!=mp[i]||(p[k]|mp[i-1])!=mp[i-1]||(p[j]|mp[i-2])!=mp[i-2]) continue;
					if((p[s]&p[k])||(p[s]&p[j])||p[j]&p[k]) continue;
					dp[i][s][k]=max(dp[i][s][k],dp[i-1][k][j]+num[p[s]]);
					ans=max(ans,dp[i][s][k]);
				}
	printf("%d\n",ans);
//	system("pause");
}
/*
18 4
PPPP
HPPH
PHPP
PHPP
PHPP
HPHP
PPHP
HPPH
PPHP
PPPP
PPPP
PPPP
PPPH
PPPH
PPHP
PPHP
PPPP
PHHH

*/
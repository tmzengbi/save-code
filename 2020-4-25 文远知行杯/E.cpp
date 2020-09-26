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
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
const int P=1e9+7;
bool vis[16];
int fac[1010],siz[16],member[16][1010],cnt[1010],Maxsize=0,ans=0;
int Pow(int a,int b)
{
	ll sum=1,z=a;
	for(;b;b>>=1)
	{
		if(b&1) sum=sum*z%P;
		if(b) z=z*z%P;
	}
	return (int)sum;
}
int inv(int x)
{
	return Pow(x,P-2);
}
int solve()
{
	memset(cnt,0,sizeof cnt);
	int sum=0,ct=0;
	for(int i=1;i<=m;i++)
		if(!vis[i]) sum+=siz[i],cnt[siz[i]]++;
		else ct++;
	sum=fac[sum];
	for(int i=1;i<=m;i++)
		if(!vis[i]) sum=(ll)sum*inv(fac[siz[i]])%P;
	for(int i=1;i<=Maxsize;i++)
		if(cnt[i]) sum=(ll)sum*inv(fac[cnt[i]])%P;
	int f=1;
	if(ct&1) f=-1;
	return sum*f;
}
void dfs(int now)
{
	if(now==m+1)
	{
		ans=(ans+solve())%P;
		return;
	}
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=1000;i++)
		fac[i]=(ll)fac[i-1]*i%P;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&siz[i]);
		for(int j=1;j<=siz[i];j++)
			scanf("%d",&member[i][j]);
		Maxsize=max(Maxsize,siz[i]);
	}
	dfs(1);
	printf("%d\n",ans);
	system("pause");
}
/*
15 14
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
2 14 15
*/
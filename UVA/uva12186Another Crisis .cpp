#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=100000;
int N,T;
vector<int>edges[maxn];
int getNum(int num)
{
	return (num*T-1)/100+1;
}
int dp(int u)
{
	int len=edges[u].size();
	if(len==0) return 1;
	int a[len],sum=0;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		a[i]=dp(v);
	}
	sort(a,a+len);
	for(int i=0;i<getNum(len);i++) sum+=a[i];
	return sum;
}
void solve()
{
	printf("%d\n",dp(0));
}
int main()
{
	while(scanf("%d%d",&N,&T)==2)
	{
		if(N==0&&T==0) break;
		for(int i=0;i<=N;i++)
			edges[i].clear();
		for(int i=1;i<=N;i++)
		{
			int v;scanf("%d",&v);
			edges[v].push_back(i);
		}
		solve();
	}
//	system("pause");
}
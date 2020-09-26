#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,a[14].cnt=0;
vector<int> apx[401];
void getapx()
{
	for(int i=1;i<=400;i++)
	{
		for(int j=1;j<=13;j++)
			if(i%j==0) apx[i].push_back(j);
	}
}
bool dfs(int dep,int sum)
{
	if(dep==n) return true;
	if(apx[sum].empty()) return false;
	for(int i=apx[sum].size()-1;i>=0;i--)
	{
		int k=apx[sum][i];
		if(a[k])
		{
			a[k]--;
			if(dfs(dep+1,sum-k)) return true;
			a[k]++;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	getapx();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		a[k]++;
		sum+=k;
	}
	bool win=false;
	if(dfs(1,sum)) win=true;
	if(win) printf("Ye5\n");
	else printf("N0\n");
	system("pause");
}
/*
37
5 6 7 8 9 10 11 12 13 3 4 5 6 7 8 11 12 13 4 5 7 8 9 10 11 12 13 4 5 6 7 8 9 10 11 12 13
*/
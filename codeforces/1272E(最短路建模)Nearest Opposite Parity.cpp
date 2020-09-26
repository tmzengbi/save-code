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
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=2e9;
int n,a[maxn];
vector<int>edges[maxn];
vector<int>odd,even;
int d[maxn],ans[maxn];
queue<int>q;
void solve(vector<int>&from,vector<int>&to)
{
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) d[i]=inf;
	for(int s:from){q.push(s);d[s]=0;}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:edges[u])
			if(d[v]==inf)
			{
				d[v]=d[u]+1;
				q.push(v);
			}
	}
	for(int t:to)
		ans[t]=(d[t]==inf)?-1:d[t]; 
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);a[i]=k;
		int le=i-k,ri=i+k;
		if(le>0) edges[le].push_back(i);
		if(ri<=n) edges[ri].push_back(i);
		if(k&1) odd.push_back(i);
		else even.push_back(i);
	}
	solve(odd,even);
	solve(even,odd);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
//	system("pause");
}
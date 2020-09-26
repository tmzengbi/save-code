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
const int maxn=2020;
const int Min=-2e9;
struct Queue
{
	int head,tail;
	pii que[maxn];
	Queue(){clear();}
	void clear(){head=0;tail=-1;}
	bool empty(){return head>tail;}
	void pop_back(){--tail;}
	void pop_front(){++head;}
	void push(pii x){que[++tail]=x;}
	pii front(){return que[head];}
	pii back(){return que[tail];}
}q;
int dp[maxn][maxn];
int n,t,m,a[maxn];
struct Node
{
	int i,o,li,lo;
}p[maxn];
int main()
{
	scanf("%d%d%d",&n,&t,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&p[i].i,&p[i].o,&p[i].li,&p[i].lo);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=t;j++)
			dp[i][j]=Min;
	for(int i=0;i<=t;i++) a[i]=Min;
	for(int i=1;i<=m+1;i++)
		for(int j=0;j<=p[i].li;j++) dp[i][j]=-j*p[i].i;
	for(int i=m+2;i<=n;i++)
	{
		for(int j=0;j<=t;j++) a[j]=max(a[j],dp[i-m-1][j]),dp[i][j]=dp[i-1][j];
		q.clear();
		for(int j=0;j<=t;j++)
		{
			int x=a[j]+j*p[i].i;
			while(!q.empty()&&q.front().second<j-p[i].li) q.pop_front();
			while(!q.empty()&&q.back().first<=x) q.pop_back();
			q.push(make_pair(x,j));
			dp[i][j]=max(dp[i][j],q.front().first-j*p[i].i);
		}
		q.clear();
		for(int j=t;j>=0;j--)
		{
			int x=a[j]+j*p[i].o;
			while(!q.empty()&&q.front().second>j+p[i].lo) q.pop_front();
			while(!q.empty()&&q.back().first<=x) q.pop_back();
			q.push(make_pair(x,j));
			dp[i][j]=max(dp[i][j],q.front().first-j*p[i].o);
		}
	}
	int ans=0;
//	for(int j=1;j<=n;j++)
	for(int i=0;i<=t;i++)
//		printf("%d %d %d\n",j,i,dp[j][i]);
		ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
//	system("pause");
}
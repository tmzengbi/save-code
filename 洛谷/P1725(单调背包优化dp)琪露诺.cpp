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
const int maxn=2e5+10;
const int inf=2e9;
int dp[maxn],n,l,r,a[maxn];
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
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1;i<=n+1;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n+1;i++) dp[i]=-inf;
	dp[1]=0;
	for(int i=l;i<=n+1;i++)
	{
		while(!q.empty()&&q.front().second<i-r) q.pop_front();
		while(!q.empty()&&q.back().first<=dp[i-l]) q.pop_back();
		if(dp[i-l]!=inf) q.push(make_pair(dp[i-l],i-l));
		if(!q.empty()) dp[i]=q.front().first+a[i];
	}
	int ans=-inf;
	for(int i=n+1;i>=n+2-r;i--)
		ans=max(ans,dp[i]);
//	for(int i=1;i<=n+1;i++)
//		printf("%d ",dp[i]);puts("");
	printf("%d\n",ans);
//	system("pause");
}
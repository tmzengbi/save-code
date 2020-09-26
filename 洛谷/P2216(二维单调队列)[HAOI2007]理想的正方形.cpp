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
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e3+10;
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
}q1,q2,qq1[maxn],qq2[maxn];//q1 max q2 min
int a,b,n,m[maxn][maxn],ans=2e9;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)	
		for(int j=1;j<=b;j++)
			scanf("%d",&m[i][j]);
	for(int i=1;i<n;i++)
	{
		q1.clear();q2.clear();
		for(int j=1;j<n;j++)
		{
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));q2.push(make_pair(m[i][j],j));
		}
		for(int j=n;j<=b;j++)
		{
			while(!q1.empty()&&q1.front().second<=j-n) q1.pop_front();
			while(!q2.empty()&&q2.front().second<=j-n) q2.pop_front();
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));q2.push(make_pair(m[i][j],j));
			while(!qq1[j-n+1].empty()&&qq1[j-n+1].back().first<=q1.front().first) qq1[j-n+1].pop_back();
			while(!qq2[j-n+1].empty()&&qq2[j-n+1].back().first>=q2.front().first) qq2[j-n+1].pop_back();
			qq1[j-n+1].push(make_pair(q1.front().first,i));qq2[j-n+1].push(make_pair(q2.front().first,i));
		}
	}
	for(int i=n;i<=a;i++)
	{
		q1.clear();q2.clear();
		for(int j=1;j<n;j++)
		{
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));q2.push(make_pair(m[i][j],j));
		}
		for(int j=n;j<=b;j++)
		{
			while(!q1.empty()&&q1.front().second<=j-n) q1.pop_front();
			while(!q2.empty()&&q2.front().second<=j-n) q2.pop_front();
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));q2.push(make_pair(m[i][j],j));
			while(!qq1[j-n+1].empty()&&qq1[j-n+1].front().second<=i-n) qq1[j-n+1].pop_front();
			while(!qq2[j-n+1].empty()&&qq2[j-n+1].front().second<=i-n) qq2[j-n+1].pop_front();
			while(!qq1[j-n+1].empty()&&qq1[j-n+1].back().first<=q1.front().first) qq1[j-n+1].pop_back();
			while(!qq2[j-n+1].empty()&&qq2[j-n+1].back().first>=q2.front().first) qq2[j-n+1].pop_back();
			qq1[j-n+1].push(make_pair(q1.front().first,i));qq2[j-n+1].push(make_pair(q2.front().first,i));
			ans=min(ans,qq1[j-n+1].front().first-qq2[j-n+1].front().first);
		}
	}
	printf("%d\n",ans);
//	system("pause");
}
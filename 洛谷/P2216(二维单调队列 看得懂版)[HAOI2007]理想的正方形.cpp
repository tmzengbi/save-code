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
}q1,q2;//q1 max q2 min
int a,b,n,k[maxn][maxn],t[maxn][maxn],m[maxn][maxn];
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++)	
		for(int j=1;j<=b;j++)
			scanf("%d",&m[i][j]);
	for(int i=1;i<=a;i++)
	{
		q1.clear();q2.clear();
		for(int j=1;j<n;j++)
		{
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));
			q2.push(make_pair(m[i][j],j));
		}
		for(int j=n,s=1;j<=b;j++,s++)
		{
			while(!q1.empty()&&q1.front().second<=j-n) q1.pop_front();
			while(!q2.empty()&&q2.front().second<=j-n) q2.pop_front();
			while(!q1.empty()&&q1.back().first<=m[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=m[i][j]) q2.pop_back();
			q1.push(make_pair(m[i][j],j));
			q2.push(make_pair(m[i][j],j));
			k[i][s]=q1.front().first;t[i][s]=q2.front().first;
		}
	}
	int ans=2e9;
	for(int j=1;j<=b-n+1;j++)
	{
		q1.clear();q2.clear();
		for(int i=1;i<n;i++)
		{
			while(!q1.empty()&&q1.back().first<=k[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=t[i][j]) q2.pop_back();
			q1.push(make_pair(k[i][j],i));
			q2.push(make_pair(t[i][j],i));
		}
		for(int i=n;i<=a;i++)
		{
			while(!q1.empty()&&q1.front().second<=i-n) q1.pop_front();
			while(!q2.empty()&&q2.front().second<=i-n) q2.pop_front();
			while(!q1.empty()&&q1.back().first<=k[i][j]) q1.pop_back();
			while(!q2.empty()&&q2.back().first>=t[i][j]) q2.pop_back();
			q1.push(make_pair(k[i][j],i));
			q2.push(make_pair(t[i][j],i));
			ans=min(q1.front().first-q2.front().first,ans);
		}
	}
	printf("%d\n",ans);
//	system("pause");
}
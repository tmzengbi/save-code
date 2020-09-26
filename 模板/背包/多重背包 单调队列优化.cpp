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
const int maxn=6010;
struct Queue
{
	int head,tail;
	pii que[maxn];
	Queue(){clear();}
	void clear(){head=0;tail=-1;}
	bool empty(){return head>tail;}
	pii front(){return que[head];}
	pii back(){return que[tail];}
	void push(pii x){que[++tail]=x;}
	void pop_front(){++head;}
	void pop_back(){--tail;}
}q;
int n,m,dp[maxn];
struct Node
{
	int v,w,s;
}p[610];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].v,&p[i].w,&p[i].s);
	for(int i=1;i<=n;i++)
	{
		for(int mod=0;mod<p[i].v;mod++)
		{
			q.clear();
			for(int j=0;j*p[i].v+mod<=m;j++)
			{
				int x=j*p[i].v+mod;
				int v=dp[x]-j*p[i].w;
				while(!q.empty()&&q.front().second<j-p[i].s) q.pop_front();
				while(!q.empty()&&q.back().first<=v) q.pop_back();
				q.push(make_pair(v,j));
				dp[x]=q.front().first+j*p[i].w;
			}
		}
	}
	printf("%d\n",dp[m]);
//	system("pause");
}
//https://ac.nowcoder.com/acm/contest/3007/C
//Dilworth定理
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Node
{
	int x,y,id;
	bool operator<(const Node &rhs)const
	{
		return x<rhs.x||x==rhs.x&&y<rhs.y;
	}
}p[maxn];
int N,b[maxn],d[maxn],ans[maxn];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+N+1);
	for(int i=1;i<=N;i++) b[i]=p[i].y;
	d[1]=b[1];
	int len=1;
	ans[p[1].id]=1;
	for(int i=2;i<=N;i++)
	{
		if(d[len]>b[i]){d[++len]=b[i];ans[p[i].id]=len;}
		else
		{
			int l=1,r=len+1;
			while(l<r)
			{
				int mid=l+r>>1;
				if(d[mid]>b[i]) l=mid+1;
				else r=mid;
			}
			d[l]=b[i];
			ans[p[i].id]=l;
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=N;i++)
		printf("%d ",ans[i]);
//	system("pause");
}
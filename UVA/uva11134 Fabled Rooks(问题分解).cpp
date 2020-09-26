#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<complex>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=5010;
struct Node
{
	int l,r,id;
	Node(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator<(const Node&rhs)const
	{
		return r<rhs.r;
	}
}px[maxn],py[maxn];
multiset<Node>s;
multiset<Node>::iterator it;
bool cmp(const Node &r1,const Node &r2)
{
	return r1.l<r2.l||r1.l==r2.l&&r1.r<r2.r;
}
int n,x[maxn],y[maxn];
int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		s.clear();
		for(int i=1;i<=n;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			px[i]=Node(x1,x2,i);
			py[i]=Node(y1,y2,i);
		}
		sort(px+1,px+n+1,cmp);
		sort(py+1,py+n+1,cmp);
		int Index=1;
		bool win=true;
		for(int i=1;i<=n;i++)
		{
			while(Index<=n&&px[Index].l<=i){s.insert(px[Index]);Index++;}
			if(s.empty())continue;
			it=s.begin();
			if(it->r>=i)
			{
				x[it->id]=i;
				s.erase(it);
			}
			else{win=false;break;}
		}
		if(!s.empty()||!win)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		s.clear();
		Index=1;
		for(int i=1;i<=n;i++)
		{
			while(Index<=n&&py[Index].l<=i){s.insert(py[Index]);Index++;}
			if(s.empty())continue;
			it=s.begin();
			if(it->r>=i)
			{
				y[it->id]=i;
				s.erase(it);
			}
			else{win=false;break;}
		}
		if(!s.empty()||!win)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			printf("%d %d\n",x[i],y[i]);
	}
//	system("pause");
}
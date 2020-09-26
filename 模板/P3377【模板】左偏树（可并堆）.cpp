#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<random>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x7fffffff;
mt19937 rnd(time(NULL));
struct Node
{
	int ch[2],val,len,rt;
	Node(){ch[0]=ch[1]=0;}
}t[maxn];
int Find(int r)
{
	return r==t[r].rt?r:(t[r].rt=Find(t[r].rt));
}
int merge(int x,int y)
{
	if(!(x&&y)) return x|y;
	if(t[x].val>t[y].val) swap(x,y);
	t[x].ch[1]=merge(t[x].ch[1],y);
	t[x].len=t[t[x].ch[1]].len+1;
	if(t[t[x].ch[0]].len<t[t[x].ch[1]].len) swap(t[x].ch[0],t[x].ch[1]);
	t[t[x].ch[0]].rt=t[t[x].ch[1]].rt=t[x].rt;
	return x;
}
void pop(int x)
{
	t[x].val=-1;
	int ls=t[x].ch[0],rs=t[x].ch[1];
	t[ls].rt=ls;t[rs].rt=rs;
	t[x].rt=merge(ls,rs);
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) t[i].rt=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i].val);
	while(m--)
	{
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			scanf("%d",&y);
			if(t[x].val==-1||t[y].val==-1) continue;
			if(Find(x)!=Find(y)) merge(Find(x),Find(y));
		}
		else
		{
			if(t[x].val==-1) puts("-1");
			else
			{
				int rt=Find(x);
				printf("%d\n",t[rt].val);
				pop(rt);
			}
		}
	}
}
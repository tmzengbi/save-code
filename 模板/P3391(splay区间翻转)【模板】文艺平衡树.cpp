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
int Index=0,rt=1;
struct Node
{
	int val,siz,fa,tag,ch[2];
	Node(){fa=ch[0]=ch[1]=siz=tag=0;}
}t[maxn];
int Get(int x)
{
	return t[t[x].fa].ch[1]==x;
}
void connect(int ch,int fa,int r)
{
	t[ch].fa=fa;
	t[fa].ch[r]=ch;
}
void up(int o)
{
	t[o].siz=t[t[o].ch[0]].siz+t[t[o].ch[1]].siz+1;
}
void down(int o)
{
	if(t[o].tag)
	{
		swap(t[o].ch[0],t[o].ch[1]);
		t[t[o].ch[0]].tag^=1;t[t[o].ch[1]].tag^=1;
		t[o].tag=0;
	}
}
void rotate(int x)
{
	int o=t[x].fa,fa=t[o].fa,d=Get(x),ch=t[x].ch[d^1];
	connect(x,fa,Get(o));
	connect(o,x,d^1);
	connect(ch,o,d);
	up(o);up(x);
}
void splay(int x,int to)
{
	bool ok=(to==rt);
	to=t[to].fa;
	while(true)
	{
		int fa=t[x].fa;
		if(fa!=to)
		{
			int ffa=t[fa].fa;
			if(ffa!=to)
			{
				if(Get(fa)==Get(x)){rotate(fa);rotate(x);}
				else{rotate(x);rotate(x);}
			}
			else rotate(x);
		}
		else break;
	}
	if(ok) rt=x;
}
void Find(int r,int x)
{
	int o=r;
	while(true)
	{
		down(o);
		if(t[t[o].ch[0]].siz>=x) o=t[o].ch[0];
		else
		{
			x-=t[t[o].ch[0]].siz+1;
			if(!x) break;
			o=t[o].ch[1];
		}
	}
	splay(o,r);
}
int a[maxn];
int build(int l,int r)
{
	if(l>r) return 0;
	int mid=(l+r)>>1,now=++Index;
	t[now].val=a[mid];t[now].siz=1;
	int le=build(l,mid-1),ri=build(mid+1,r);
	connect(le,now,0);connect(ri,now,1);
	up(now);
	return now;
}
void rotatetree(int l,int r)
{
	if(l>r) swap(l,r);
	int le=l,ri=r+2;
	Find(rt,le);Find(t[rt].ch[1],ri-t[t[rt].ch[0]].siz-1);
	int rch=t[rt].ch[1];
	t[t[rch].ch[0]].tag^=1;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=i;
	build(0,n+1);
//	dfs(rt);
	for(int i=1;i<=m;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		rotatetree(l,r);
//		dfs(rt);puts("");
	}
	dfs(rt);
}
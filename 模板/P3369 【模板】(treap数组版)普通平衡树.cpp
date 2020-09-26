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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x7fffffff;
int n,m;
mt19937 rnd(time(NULL));
int Index=0,rt=0;
struct Node
{
	int v,val,n,siz;
	int ch[2];
	Node(){n=siz=0;ch[0]=ch[1]=0;}
	int cmp(int x)
	{
		if(x==val) return -1;
		return x>val;
	}
}t[maxn];
inline void pushup(int o)
{
	t[o].siz=t[o].n+t[t[o].ch[0]].siz+t[t[o].ch[1]].siz;
}
void rotate(int &o,int d)
{
	int k=t[o].ch[d^1];t[o].ch[d^1]=t[k].ch[d];t[k].ch[d]=o;
	pushup(o);pushup(k);o=k;
}
void insert(int &o,int x)
{
	if(!o)
	{
		o=++Index;
		Node &now=t[o];
		now.n=now.siz=1;now.val=x;
		now.v=rnd();
		return;
	}
	int d=t[o].cmp(x);Node &now=t[o];
	if(d==-1){++now.n;++now.siz;return;}
	insert(now.ch[d],x);
	if(now.v<t[now.ch[d]].v) rotate(o,d^1);
	pushup(o);
}
void erase(int &o,int x)
{
	int d=t[o].cmp(x);
	Node &now=t[o];
	if(d==-1)
	{
		if(now.n>1){--now.n;--now.siz;}
		else if(!now.ch[0]) o=now.ch[1];
		else if(!now.ch[1]) o=now.ch[0];
		else
		{
			int d2=t[now.ch[0]].v>t[now.ch[1]].v;
			rotate(o,d2);
			erase(t[o].ch[d2],x);
		}
	}
	else erase(now.ch[d],x);
	if(o) pushup(o);
}
int findkth(int o,int x)
{
	Node &now=t[o];
	if(t[now.ch[0]].siz>=x) return findkth(now.ch[0],x);
	if(t[now.ch[0]].siz+now.n>=x) return now.val;
	return findkth(now.ch[1],x-t[now.ch[0]].siz-now.n);
}
int findrank(int o,int x)
{
	Node &now=t[o];int d=now.cmp(x);
	if(d==-1) return t[now.ch[0]].siz;
	if(d==0) return findrank(now.ch[0],x);
	return findrank(now.ch[1],x)+t[now.ch[0]].siz+now.n;
}
int findpre(int o,int x)
{
	int ans=-inf;
	while(o)
	{
		Node &now=t[o];
		if(now.cmp(x)==1) ans=now.val,o=now.ch[1];
		else o=now.ch[0];
	}
	return ans;
}
int findnext(int o,int x)
{
	int ans=inf;
	while(o)
	{
		Node &now=t[o];
		if(now.cmp(x)==0) ans=now.val,o=now.ch[0];
		else o=now.ch[1];
	}
	return ans;
}
int main()
{
	rt=0;
	scanf("%d",&n);
	while(n--)
	{
		int opt,x;scanf("%d%d",&opt,&x);
		if(opt==1) insert(rt,x);
		if(opt==2) erase(rt,x);
		if(opt==3) printf("%d\n",findrank(rt,x)+1);
		if(opt==4) printf("%d\n",findkth(rt,x));
		if(opt==5) printf("%d\n",findpre(rt,x));
		if(opt==6) printf("%d\n",findnext(rt,x));
	}
}
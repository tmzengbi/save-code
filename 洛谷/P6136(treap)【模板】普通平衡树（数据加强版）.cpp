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
const int maxn=1e6+10;
const int inf=2147483647;
mt19937 rnd(time(NULL));
int Index=0;
struct Node
{
	int v,val,n,siz;
	Node *ch[2];
	Node(){n=siz=0;}
	int cmp(int x)
	{
		if(x==val) return -1;
		return val<x;
	}
}dizhi[maxn<<1],*rt,*null;
inline void up(Node *o)
{
	o->siz=o->ch[0]->siz+o->ch[1]->siz+o->n;
}
void rotate(Node *&o,int d)
{
	Node *k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;
	up(o);up(k);o=k;
}
void insert(Node *&o,int v)
{
	if(o==null)
	{
		o=&dizhi[++Index];
		o->ch[0]=o->ch[1]=null;
		o->v=rnd();o->val=v;
		o->n=o->siz=1;
		return;
	}
	int d=o->cmp(v);
	if(d==-1){++o->n;++o->siz;return;}
	insert(o->ch[d],v);
	if(o->ch[d]->v>o->v) rotate(o,d^1);
	up(o);
}
void erase(Node *&o,int v)
{
	int d=o->cmp(v);
	if(d==-1)
	{
		if(o->n>1){--o->siz;--o->n;return;}
		else if(o->ch[0]==null) o=o->ch[1];
		else if(o->ch[1]==null) o=o->ch[0];
		else
		{
			int d2=(o->ch[0]->v>o->ch[1]->v);
			rotate(o,d2);
			erase(o->ch[d2],v);
		}
	}
	else erase(o->ch[d],v);
	if(o!=null) up(o);
}
int findrank(Node *o,int x)
{
	if(o==null) return 0;
	int d=o->cmp(x);
	if(d==-1) return o->ch[0]->siz;
	else if(d==0) return findrank(o->ch[0],x);
	else return findrank(o->ch[1],x)+o->ch[0]->siz+o->n;
}
int findpre(Node *o,int x)
{
	int sol=-inf;
	while(o!=null)
	{
		int d=o->cmp(x);
		if(d==1){sol=o->val;o=o->ch[1];}
		else o=o->ch[0];
	}
	return sol;
}
int findkth(Node *o,int x)
{
	if(o->ch[0]->siz>=x) return findkth(o->ch[0],x);
	if(o->ch[0]->siz+o->n>=x) return o->val;
	return findkth(o->ch[1],x-o->ch[0]->siz-o->n);
}
int findnext(Node *o,int x)
{
	int sol=inf;
	while(o!=null)
	{
		int d=o->cmp(x);
		if(d==0){sol=o->val;o=o->ch[0];}
		else o=o->ch[1];
	}
	return sol;
}
int n,m;
int main()
{
	rt=null=&dizhi[0];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int num;scanf("%d",&num);
		insert(rt,num);
	}
	int last=0,ans=0;
	while(m--)
	{
		int opt,x;
		scanf("%d%d",&opt,&x);x^=last;
		if(opt==1) insert(rt,x);
		else if(opt==2) erase(rt,x);
		else if(opt==3) last=findrank(rt,x)+1;//printf("%d\n",last=findrank(rt,x)+1);
		else if(opt==4) last=findkth(rt,x);//printf("%d\n",last=findkth(rt,x));
		else if(opt==5) last=findpre(rt,x);//printf("%d\n",last=findpre(rt,x));
		else last=findnext(rt,x);//printf("%d\n",last=findnext(rt,x));
		if(opt>=3) ans=ans^last;
	}
	printf("%d\n",ans);
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;
mt19937 rnd(time(NULL));
int Index=0;
struct Node
{
	Node *ch[2];
	int v,k,siz,n;
	int cmp(int x)
	{
		if(x==v) return -1;
		return x<v?0:1;
	}
}node[1000010],*null;
void up(Node *o)
{
	o->siz=o->ch[0]->siz+o->ch[1]->siz+o->n;
}
void rotate(Node *&o,int d)
{
	Node *k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	up(o);up(k);
	o=k;
}
void insert(Node *&o,int v)
{
	if(o==null)
	{
		o=&node[++Index];
		o->ch[0]=o->ch[1]=null;
		o->v=v;o->k=rnd();
		o->siz=o->n=1;
		return;
	}
	int d=o->cmp(v);
	if(d==-1) {o->n++;o->siz++;return;}
	insert(o->ch[d],v);
	if(o->ch[d]->k>o->k) rotate(o,d^1);
	up(o);
}
void del(Node *&o,int v)
{
	int d=o->cmp(v);
	if(d==-1)
	{
		if(o->n>1) {o->n--;o->siz--;}
		else if(o->ch[0]==null) o=o->ch[1];
		else if(o->ch[1]==null) o=o->ch[0];
		else
		{
			int d2=o->ch[0]->k>o->ch[1]->k?1:0;
			rotate(o,d2);
			del(o->ch[d2],v);
		}
	}
	else if(o->ch[d]!=null) del(o->ch[d],v);
	if(o!=null) up(o);
}
int Find(Node *o,int v)
{
	while(o)
	{
		int d=o->cmp(v);
		if(d==-1) return 1;
		o=o->ch[d];
	}
	return 0;
}
int getrank(Node *o,int v)
{
	int d=o->cmp(v);
	if(d==-1) return o->ch[0]->siz+1;
	if(d==0) return getrank(o->ch[0],v);
	if(d==1) return getrank(o->ch[1],v)+o->ch[0]->siz+o->n;
}
int indexrank(Node *o,int r)
{
	if(r>o->ch[0]->siz&&r<=o->ch[0]->siz+o->n) return o->v;
	else if(r<=o->ch[0]->siz) return indexrank(o->ch[0],r);
	else return indexrank(o->ch[1],r-o->ch[0]->siz-o->n);
}
/*
void print(Node *o)
{
	if(o==null) return;
	printf("son %d is:",o->v);
	if(o->ch[0]!=null) printf("left %d ",o->ch[0]->v);
	if(o->ch[1]!=null) printf("right %d ",o->ch[1]->v);
	printf("%d",o->siz);
	puts("");
	print(o->ch[0]);
	print(o->ch[1]);
}
*/
int Find_pre(Node *o,int v)
{
	int sol=0;
	while(o!=null)
	{
		if(o->cmp(v)==1) {sol=o->v;o=o->ch[1];}
		else o=o->ch[0];
	}
	return sol;
}
int Find_Next(Node *o,int v)
{
	int sol=v;
	while(o!=null)
	{
		if(!o->cmp(v)) {sol=o->v;o=o->ch[0];}
		else o=o->ch[1];
	}
	return sol;
}
int main()
{
	null=&node[0];
	Node *rt=null;
	null->siz=0;
	int x,y,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&x,&y);
		if(x==1) insert(rt,y);
		if(x==2) if(Find(rt,y)) del(rt,y);
		if(x==3) if(Find(rt,y)) printf("%d\n",getrank(rt,y));
		if(x==4) printf("%d\n",indexrank(rt,y));
		if(x==5) printf("%d\n",Find_pre(rt,y));
		if(x==6) printf("%d\n",Find_Next(rt,y));
	}
}
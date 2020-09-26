#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
int pre[maxn],siz[maxn],cnt=0,tot=0;
int Find(int r)
{
	return r==pre[r]?r:pre[r]=Find(pre[r]);
}
void merge(int r1,int r2)
{
	r1=Find(r1);r2=Find(r2);
	if(siz[r1]>siz[r2]) swap(r1,r2);
	pre[r1]=r2;
	siz[r2]+=siz[r1];
}
void check(int x,int y)
{
//	tot++;
	if(Find(x)==Find(y)){cnt++;return;}
	merge(x,y);
//	cnt++;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int x,y;
	while(scanf("%d",&x)==1)
	{
		scanf("%d",&y);
		for(int i=0;i<maxn;i++)
		{
			siz[i]=1;
			pre[i]=i;
		}
//		tot=0;
		cnt=0;
		check(x,y);
		while(scanf("%d",&x)==1&&x!=-1)
		{
//			tot++;
			scanf("%d",&y);
			check(x,y);
		}
//		printf("%d\n",tot-cnt);
		printf("%d\n",cnt);
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=20010;
const int maxm=100010;
int n,m,pre[maxn],e[maxn];
struct Node
{
	int a,b,v;
}p[maxm];
bool cmp(const Node&r1,const Node&r2)
{
	return r1.v>r2.v;
}
int Find(int r)
{
	return r==pre[r]?r:(pre[r]=Find(pre[r]));
}
void merge(int r1,int r2)
{
	r1=Find(r1),r2=Find(r2);
	pre[r1]=r2;
}
bool check(int r1,int r2)
{
	return Find(r1)==Find(r2);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].v);
	for(int i=1;i<=n;i++) pre[i]=i;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=p[i].a,y=p[i].b;
		if(check(x,y))
		{
			printf("%d\n",p[i].v);
			return 0;
		}
		if(!e[x]) e[x]=y;
		else merge(e[x],y);
		if(!e[y]) e[y]=x;
		else merge(e[y],x);
	}
	puts("0");
//	system("pause");
}
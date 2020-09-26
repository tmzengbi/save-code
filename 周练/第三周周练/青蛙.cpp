#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n,x[1010],y[1010],pre[1010];
struct Node
{
	int x,y;
	double d;
	Node(){}
	Node(int x,int y,double d):x(x),y(y),d(d){}
}d[1000010];
bool cmp(Node n1,Node n2)
{
	return n1.d<n2.d;
}
double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int finddad(int r)
{
	return r==pre[r]?r:(pre[r]=finddad(pre[r]));
}
int main()
{
	int Index=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			d[++Index]=Node(i,j,dist(x[i],y[i],x[j],y[j]));
	sort(d+1,d+Index+1,cmp);Index=0;
	while(finddad(1)!=finddad(2))
	{
		Index++;
		int a=finddad(d[Index].x),b=finddad(d[Index].y);
		if(a!=b) pre[a]=b;
	}
	printf("%.3lf\n",d[Index].d);

//	system("pause");
}
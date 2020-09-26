#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=3.1415926;
int N,vis[7],X1,X2,Y1,Y2,ans=2e9;
struct node
{
	int x,y;
	node(){}
}nd[7],b[7];
double del(double a1,double a2)
{
	if(a1>a2)return a1-a2;
	else return 0.0;
}
double dis(node n1,node n2)
{
	return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
int ar()
{
	double sum=0,r[7],sum_area=(double)abs((X1-X2)*(Y1-Y2));
	for(int i=1;i<=N;i++)
	{
		r[i]=(double)min(min(abs(b[i].x-X1),abs(b[i].x-X2)),min(abs(b[i].y-Y1),abs(b[i].y-Y2)));
		for(int j=1;j<i;j++)
			r[i]=min(r[i],del(dis(b[i],b[j]),r[j]));
		sum+=pi*r[i]*r[i];
	}
	sum=sum_area-sum;
	if((sum-(int)sum)>=0.5)	return (int)sum+1;
	else return (int)sum;
}
void dfs(int x)
{
	if(x>N)
	{
		ans=min(ans,ar());
		return;
	}	
	for(int i=1;i<=N;i++)
	{
		if(!vis[i])
		{
			b[x]=nd[i];vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
int main()
{
	scanf("%d",&N);
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	for(int i=1;i<=N;i++)
		scanf("%d%d",&nd[i].x,&nd[i].y);
	dfs(1);
	printf("%d\n",ans);
	system("pause");
}
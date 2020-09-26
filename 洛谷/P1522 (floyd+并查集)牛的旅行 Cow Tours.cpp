#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int Max=0x3f3f3f3f;
int N,pre[155];
double dis[155][155];
char rel[155][155];
struct Node
{
	int x,y;
}node[155];
double cpute_dist(Node x,Node y)
{
	long long dist_2=(x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
	return sqrt(dist_2);
}
int findfa(int now)
{
	if(now==pre[now]) return now;
	else pre[now]=findfa(pre[now]);
	return pre[now];
}
void merge(int x,int y)
{
	x=findfa(x);y=findfa(y);
	if(x!=y) pre[x]=y;
}
void solve()
{
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
			{
				if(dis[i][j]>(dis[i][k]+dis[k][j]))
					dis[i][j]=dis[i][k]+dis[k][j];
			}
	double maxDis[155]={0},ans=0x3f3f3f3f,ans2=0;
	for(int i=1;i<=N;i++)
	{
		maxDis[i]=0;
		for(int j=1;j<=N;j++)
			if(dis[i][j]>0&&dis[i][j]<Max)
			{
				merge(i,j);
				maxDis[i]=max(maxDis[i],dis[i][j]);
				ans2=max(maxDis[i],ans2);
			}
	}

/*		{	
			if(dis[i][j]!=Max) maxDis[i]=max(maxDis[i],dis[i][j]);
			ans2=max(ans2,maxDis[i]);
		}
*/
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{

			int fi=findfa(i),fj=findfa(j);
			if(fi!=fj)	ans=min(ans,maxDis[i]+maxDis[j]+cpute_dist(node[i],node[j]));
/*			

			if(dis[i][j]==Max)
				ans=min(maxDis[i]+maxDis[j]+cpute_dist(node[i],node[j]),ans);
*/
		}

	ans=max(ans,ans2);
	printf("%.6lf\n",ans);
/*
	for(int i=1;i<=N;i++)
		printf("%d ",pre[i]);
*/
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d%d",&node[i].x,&node[i].y);
		pre[i]=i;
	}
	for(int i=1;i<=N;i++)
		scanf("%s",rel[i]+1);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(rel[i][j]=='1') dis[i][j]=cpute_dist(node[i],node[j]);
			else if(i==j) dis[i][j]=0;
			else dis[i][j]=Max;
	solve();
}
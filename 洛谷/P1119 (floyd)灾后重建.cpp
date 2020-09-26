#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2e8;
int N,M,dis[210][210],t[210];
void update(int k)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if((dis[i][k]+dis[k][j])<dis[i][j])
				dis[i][j]=dis[i][k]+dis[k][j];
		}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dis[i][j]=maxn;
	for(int i=0;i<N;i++)
		scanf("%d",&t[i]);
	for(int i=0;i<M;i++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		dis[u][v]=dis[v][u]=d;
	}
	int Q,now=0;;
	scanf("%d",&Q);
	while(Q--)
	{
		int x,y,T;
		scanf("%d%d%d",&x,&y,&T);
		while(now<N&&t[now]<=T)
		{
			update(now);now++;
		}
		if(t[x]>T||t[y]>T||dis[x][y]==maxn) printf("-1\n");
		else	printf("%d\n",dis[x][y]);
		
	}
//	system("pause");
}
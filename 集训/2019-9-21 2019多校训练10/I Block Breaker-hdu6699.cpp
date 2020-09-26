#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
int T,map[2010][2010][2],q,m,n;		//0表示左右 1表示上下
bool vis[2010][2010];
void drop(int x,int y,int &sum)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+fx[i],ny=y+fy[i];
		if(nx<1||nx>m||ny<1||ny>n)	continue;
		if(i==1||i==3) map[nx][ny][0]++;
		else map[nx][ny][1]++;
		if(map[nx][ny][0]&&map[nx][ny][1]&&(!vis[nx][ny]))
		{
			vis[nx][ny]=true;
			sum++;
			drop(nx,ny,sum);
		}		
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&m,&n,&q);
/*		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				map[i][j]=0;
*/
		memset(map,0,sizeof map);
		memset(vis,false,sizeof vis);
		while(q--)
		{
			int x,y,sum=1;
			scanf("%d%d",&x,&y);
			if(vis[x][y])	{printf("0\n");continue;}
			vis[x][y]=true;
/*			for(int i=0;i<4;i++)
			{
				int nx=x+fx[i],ny=y+fy[i];
				if(nx<1||nx>m||ny<1||ny>n)	continue;
				if(i==1||i==3) map[nx][ny][0]++;
				else map[nx][ny][1]++;
				if(map[nx][ny][0]&&map[nx][ny][1]&&(!vis[nx][ny]))
				{
					vis[nx][ny]=true;
					sum++;
				}
			}		
*/			
			drop(x,y,sum);
			printf("%d\n",sum);
		}
	}
//	while(1);
}
/*
2
2 2 3
1 1
1 2
2 2
4 4 6
1 1
1 2
2 1
2 2
4 4
3 3
*/
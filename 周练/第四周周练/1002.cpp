#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int s[1010][1010],n,m,sx,sy;
const int fx[8]={2,2,1,1,-1,-1,-2,-2},fy[8]={1,-1,2,-2,2,-2,1,-1};
struct Node
{
    int x,y;
    Node(int x,int y):x(x),y(y){}
};
void bfs()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=-1;
	queue<Node>q;
	q.push(Node(sx,sy));
	s[sx][sy]=0;
	while(!q.empty())
	{
		Node o=q.front();q.pop();
		for(int i=0;i<8;i++)
		{
			int nx=o.x+fx[i],ny=o.y+fy[i];
			if(nx<1||ny<1||nx>n||ny>m) continue;
			if(s[nx][ny]==-1)
			{
				s[nx][ny]=s[o.x][o.y]+1;
				q.push(Node(nx,ny));
			}
		}
	}
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&sx,&sy);
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%-5d",s[i][j]);
		printf("\n");
	}
//	system("pause");
}
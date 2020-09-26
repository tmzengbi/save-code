#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m;
int map[110][110],d[110][110],ans=0;
int dfs(int x,int y)
{
	if(d[x][y])	return d[x][y];
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m)	continue;
		if(map[x][y]>map[nx][ny])
			d[x][y]=max(d[x][y],dfs(nx,ny)+1);
	}
	return d[x][y];
}
int main()
{
	memset(d,0,sizeof d);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,dfs(i,j));
	printf("%d\n",ans+1);
//	system("pause");
}
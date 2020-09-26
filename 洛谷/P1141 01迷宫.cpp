#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char map[1010][1010];
int vis[1010][1010],n,m,sum[1000010],cnt=0,mk[1010][1010];
void dfs(int x,int y)
{
	char ch=map[x][y];
	mk[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>n)	continue;
		if(map[nx][ny]==ch)	continue;
		if(!vis[nx][ny])
		{
			sum[cnt]++;
			vis[nx][ny]=true;
			dfs(nx,ny);
		}
	}
}
int main()
{
	memset(vis,false,sizeof vis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				vis[i][j]=true;
				sum[++cnt]=1;
				dfs(i,j);
			}
		}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",sum[mk[x][y]]);
	}
//	system("pause");
}
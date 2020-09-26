#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
int N,M;
char Mp[310][310];
bool vis[310][310];
void dfs(int x,int y)
{
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx=x+fx[i],ny=y+fy[i];
		if(nx<1||nx>N||ny<1||ny>M||vis[nx][ny]) continue;
		if(Mp[nx][ny]=='1')
			dfs(nx,ny);
	}
}
int main()
{
	scanf("%d%d",&N,&M);getchar();
	for(int i=1;i<=N;i++)
		scanf("%s",Mp[i]+1);
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i=x1;i<=x2;i++)
			for(int j=y1;j<=y2;j++)
				Mp[i][j]='1';
		int ans=0;
		memset(vis,false,sizeof vis);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				if(Mp[i][j]=='1'&&!vis[i][j]){ans++;dfs(i,j);}
		printf("%d\n",ans);
	}
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int fx[4]={1,1,-1,-1},fy[4]={1,-1,1,-1};
int T,M,N,vis[1010][1010][4],cnt=0,ans=0;
bool dfs(int x,int y,int dir)
{
	if(vis[x][y][dir]==2) return false;
	if(vis[x][y][dir]==1) return true;
	if((x==1&&y==1)||(x==N&&y==M)||(x==N&&y==1)||(x==1&&y==M)) {vis[x][y][dir]=2;return false;}
	vis[x][y][dir]=1;
	if(x==1)
	{
		if(dir==2) 
		{
//			vis[x][y][dir]=1;
			if(dfs(x,y,0)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
		if(dir==3)
		{
			if(dfs(x,y,1)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
	}
	if(x==N)
	{
		if(dir==0)
		{
			if(dfs(x,y,2)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
		if(dir==1)
		{
			if(dfs(x,y,3)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
	}//const int fx[4]={1,1,-1,-1},fy[4]={1,-1,1,-1};
	if(y==1)
	{
		if(dir==1)
		{
			if(dfs(x,y,0)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
		if(dir==3)
		{
			if(dfs(x,y,2)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
	}
	if(y==M)
	{
		if(dir==0)
		{
			if(dfs(x,y,1)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
		if(dir==2)
		{
			if(dfs(x,y,3)) return 1;
			else {vis[x][y][dir]=2;return 0;}
		}
	}
	cnt++;
	if(!dfs(x+fx[dir],y+fy[dir],dir)) {vis[x][y][dir]=2;return false;}
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&N,&M);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				for(int k=0;k<4;k++)
				{
					cnt=0;
					if((i==1&&(k==2||k==3))||(i==N&&(k==0||k==1))||(j==1&&(k==1||k==3)||(j==M&&(k==0||k==2))))continue;
					if(vis[i][j][k]==0&&dfs(i,j,k))
						ans+=cnt;
				}
		printf("%d\n",ans);
	}
	system("pause");
	
}//const int fx[4]={1,1,-1,-1},fy[4]={1,-1,1,-1};

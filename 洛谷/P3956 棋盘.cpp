#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int drx[4]={0,1,0,-1},dry[4]={1,0,-1,0};
int map[110][110],cos[110][110],m,n,ans=2e9;
bool win=false;
void dfs(int x,int y,int cost,bool mag,int c)	//x,y表示当前位置
{
	if(x==m&&y==m)
	{	
		win=true;
		ans=min(ans,cost);
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+drx[i],ny=y+dry[i];
		if(nx<1||nx>m||ny<1||ny>m)	continue;
		if(mag)
		{
			if(map[nx][ny]!=-1)
			{
				int tmp=cost;
				if(map[nx][ny]!=c)tmp++;
				if(tmp<cos[nx][ny])
				{
					cos[nx][ny]=tmp;
					dfs(nx,ny,tmp,false,map[nx][ny]);
				}
			}
		}
		else
		{
			if(map[nx][ny]==-1)
				dfs(nx,ny,cost+2,true,map[x][y]);
			else
			{
				int tmp=cost;
				if(map[nx][ny]!=c)tmp++;;
				if(tmp<cos[nx][ny])
				{
					cos[nx][ny]=tmp;
					dfs(nx,ny,tmp,false,map[nx][ny]);
				}
			}
		}


	}

}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			map[i][j]=-1;
			cos[i][j]=2e9;
		}
	cos[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
	}
	dfs(1,1,0,false,map[1][1]);
	if(!win)	ans=-1;
	printf("%d\n",ans);
//	printf("\n");
/*	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",cos[i][j]);
		cout<<endl;
	}
*/
//	system("pause");

}

/*
5 13
1 1 0 
1 2 0 
2 2 1 
3 1 0 
4 1 0 
5 1 0 
3 3 0 
3 4 0 
5 2 0 
5 3 0 
5 4 0
5 5 0
4 5 1
*/
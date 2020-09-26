#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s[33][33];
const int fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
void dfs(int x,int y)
{
	s[x][y]=3;
	for(int i=0;i<4;i++)
	{
		int nx=x+fx[i],ny=y+fy[i];
		if(nx<0||ny<0||nx>n+1||ny>n+1) continue;
		if(s[nx][ny]==1||s[nx][ny]==3) continue;
		dfs(nx,ny);
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&s[i][j]);
	dfs(0,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]==0) s[i][j]=2; 
			if(s[i][j]==3) s[i][j]=0;
			printf("%d",s[i][j]);
			if(j<n) printf(" ");
		}
		printf("\n");
	}
//	system("pause");
}
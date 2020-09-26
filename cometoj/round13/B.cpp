#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
char M[410][410],dir[100010];
struct Now
{
	int x,y;
}now;
bool checkout(int x,int y)
{
	if(x<1||x>n||y>m||y<1) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&M[i][j]);
			if(M[i][j]=='@') {now.x=i;now.y=j;}
		}
	}
	getchar();
	scanf("%s",dir+1);
	int len=strlen(dir+1);
	queue<Now> q;
	q.push(now);
	bool win=true;
	for(int i=1;i<=len;i++)
	{
		M[now.x][now.y]='.';
		if(dir[i]=='W') now.x--;
		if(dir[i]=='S')	now.x++;
		if(dir[i]=='A')	now.y--;
		if(dir[i]=='D')	now.y++;
		if(checkout(now.x,now.y)){win=false;break;}
		q.push(now);
		if(M[now.x][now.y]=='o') continue;
		q.pop();
		M[now.x][now.y]='@';
	}
	if(!win) printf("GG\n");
	else
	{
		while(!q.empty())
		{
			Now N=q.front();q.pop();
			M[N.x][N.y]='X';
		}
		M[now.x][now.y]='@';
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",M[i][j]);
			printf("\n");
		}
	}
}
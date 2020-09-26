#include<iostream>
using namespace std;
const int dir1[9]={0,-1,-1,-1,0,0,1,1,1};
const int dir2[9]={0,1,0,-1,1,-1,1,0,-1};
char p[105][105];
int m,n;
void dfs(int l,int r);
int main()
{
	while(true)
	{
		cin>>m>>n; 
		if(m==0&&n==0)	break;
		int ans=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>p[i][j];
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(p[i][j]=='*')	continue;
				else if(p[i][j]=='@')
				{
					dfs(i,j);
					ans++;
				}
			}
		cout<<ans<<endl;
	
	}
}
void dfs(int l,int r)
{
	for(int i=1;i<=8;i++)
	{
		int new_l=l+dir1[i],new_r=r+dir2[i];
		if(new_l>m||new_l<1||new_r>n||new_r<1)	continue;
		if(p[new_l][new_r]=='*')	continue;
		else if(p[new_l][new_r]=='@')
		{
			p[new_l][new_r]='*';
			dfs(new_l,new_r);
		}
	}
}

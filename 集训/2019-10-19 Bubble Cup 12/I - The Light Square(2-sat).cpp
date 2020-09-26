#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=4010;
char s1[2010][2010],s2[2010][2010],s3[2010];
int N,s[maxn<<1],cnt=0,ans=0;
bool vis[maxn<<1];
vector<int> edges[maxn<<1];
void addedge(int u,int a,int v,int b)
{
	u=u*2+a;v=v*2+b;
	edges[u].push_back(v);
	edges[v].push_back(u);
}
bool dfs(int u)
{
	if(vis[u^1]) return false;
	if(vis[u]) return true;
	vis[u]=true;
	s[cnt++]=u;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(!dfs(v)) return false;
	}
	return true;
}
bool twosat()
{
	for(int i=0;i<N*4;i+=2)
	{
		if(!vis[i]&&!vis[i^1])
		{
			cnt=0;
			if(!dfs(i))
			{
				while(cnt) vis[s[--cnt]]=false;
				if(!dfs(i+1)) return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%s",s1[i]);
	for(int i=0;i<N;i++) scanf("%s",s2[i]);
	scanf("%s",s3);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			s1[i][j]-='0';
			s2[i][j]-='0';
		}

	for(int i=0;i<N;i++) s3[i]-='0';
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			int k=s1[i][j]^s2[i][j];
			if(k)
			{
				if(s3[i]==0&&s3[j]==0){printf("-1\n");return 0;}
				if(s3[i]==0&&s3[j]==1) vis[i*2+1]=true;
				if(s3[i]==1&&s3[j]==0) vis[(j+N)*2+1]=true;
				if(s3[i]==1&&s3[j]==1)
				{
					addedge(i,0,j+N,1);
					addedge(i,1,j+N,0);
				}
			}
			else 
			{
				if(s3[i]==1&&s3[j]==0) vis[(j+N)*2]=true;
				if(s3[i]==0&&s3[j]==1) vis[i*2]=true;
				if(s3[i]==1&&s3[j]==1)
				{
					addedge(i,0,j+N,0);
					addedge(i,1,j+N,1);
				}
			}
		}
	if(twosat())
	{
/*
		for(int i=0;i<N*4;i++)
			if(vis[i]) printf("%d ",i);
		printf("\n");
*/
		for(int i=0;i<N*4;i++)
			if(vis[i]&&i%2) ans++;
		printf("%d\n",ans);
		for(int i=0;i<N*4;i++)
			if(vis[i]&&i%2)
			{
				if(i/2>=N) printf("col %d\n",i/2-N);
				else printf("row %d\n",i/2);
			}
	}
	else printf("-1\n");
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1010;
struct Node
{
	int a,b;
}n[maxn];
int N,M,num[maxn];
bool vis[maxn][2];
vector<int>line[maxn];
int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(vis,0,sizeof vis);
		memset(num,0,sizeof num);
		for(int i=1;i<=N;i++) line[i].clear();
		for(int i=1;i<=M;i++)
		{
			scanf("%d%d",&n[i].a,&n[i].b);
			num[n[i].a]++;num[n[i].b]++;
			line[n[i].a].push_back(i);
			line[n[i].b].push_back(i);
		}
		bool Find=true,win=true;
		while(Find)
		{
			Find=false;
			for(int i=1;i<=N;i++)
			{
				if(num[i]==1&&!vis[i][1])
				{
					vis[i][1]=true;
					Find=true;
					for(int j=0;j<line[i].size();j++)
					{
						int l=line[i][j];
						if(!vis[l][0])
						{
							vis[l][0]=true;
							num[n[l].a]--;num[n[l].b]--;
						}
					}
				}
				if(num[i]==0&&!vis[i][1]){win=false;break;}
			}
		}
		if(win) printf("Yes\n");
		else printf("No\n");
//		system("pause");
	}
}
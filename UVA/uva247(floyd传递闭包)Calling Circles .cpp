#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
map<string,int> m;
int main()
{
	int N,M,Cas=0;
	while(scanf("%d%d",&N,&M)&&(N||M))
	{
		if(Cas) cout<<endl;
		string s[26];
		int cnt=0,dir[26][26];
		memset(dir,0,sizeof dir);
		m.clear();
		for(int i=1;i<=M;i++)
		{
			string a,b;
			cin>>a>>b;
			if(m.find(a)==m.end()) {m[a]=++cnt;s[cnt]=a;}
			if(m.find(b)==m.end()) {m[b]=++cnt;s[cnt]=b;}
			dir[m[a]][m[b]]=1;
		}
		for(int k=1;k<=N;k++)
			for(int i=1;i<=N;i++)
				for(int j=1;j<=N;j++)
					dir[i][j]=dir[i][j]||(dir[i][k]&&dir[k][j]);
		bool vis[26];
		memset(vis,false,sizeof vis);
		printf("Calling circles for data set %d:\n",++Cas);
		for(int i=1;i<=N;i++)
		{
			if(!vis[i])
			{
				cout<<s[i];
				for(int j=i+1;j<=N;j++)
				{
					if(!vis[j]&&dir[i][j]&&dir[j][i])
					{
						vis[j]=true;
						cout<<", "<<s[j];
					}
				}
				cout<<endl;
			}
		}
	}
}
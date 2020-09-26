#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		int N,M,x,y,ans=0;
		char Map[55][55];
		cin>>N>>M;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cin>>Map[i][j];
				if(Map[i][j]=='S'){x=i;y=j;}
			}
			getchar();
		}
		for(int i=1;i<=M;i++)
			if(Map[x][i]=='#'){ans=-1;break;} 
		for(int i=1;i<=N;i++)
			if(Map[i][y]=='#'){ans=-1;break;}
		if(ans!=-1)
			ans=M+N-2;
		printf("%d\n",ans);

	}
}
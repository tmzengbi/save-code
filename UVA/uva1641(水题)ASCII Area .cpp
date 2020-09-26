#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
int h,w;
char s[110][110];
int main()
{
	while(scanf("%d%d",&h,&w)==2)
	{
		int cnt=0,ans=0;
		for(int i=0;i<h;i++) scanf("%s",s[i]);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				if(s[i][j]!='.') ans++,cnt++;
				else if(cnt&1) ans+=2;
			}
		printf("%d\n",ans/2);
	}
//	system("pause");
}
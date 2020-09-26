#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int T,ans,vis[27];
char s[1010];
int main()
{
	scanf("%d",&T);getchar();
	for(int ii=1;ii<=T;ii++)
	{
		memset(vis,0,sizeof vis);
		ans=2e8;
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			int l=s[i]-'a'+1;
			if(!vis[l])
				vis[l]=i;
			else 
			{
				ans=min(ans,i-vis[l]); 
				vis[l]=i;
			}
		}
		if(ans==2e8) printf("Case #%d: -1\n",ii);
		else printf("Case #%d: %d\n",ii,ans);
	}
//	while(1);
}
/*
2 abcecba abc
*/
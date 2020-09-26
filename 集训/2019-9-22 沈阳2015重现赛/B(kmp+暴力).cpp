#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,len1,len2;
char s[510][2010];
void getNext(int Next[],char *b)
{
	int i=1,j=0;
	Next[0]=-1;
	while(i<=len1)
	{
		if(j==0||b[i]==b[j])
			Next[i++]=j++;
		else j=Next[j-1]+1;
	}
	
}
bool KMP(int Next[],char *a,char *b)
{
	for(int i=1,j=1;i<=len2;i++)
	{
		while(j&&a[i]!=b[j]) j=Next[j-1]+1;
		if(j==0) j=1;
		else if(a[i]==b[j])	j++;
		if(j==len1+1) return true;
	}
	return false;

}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d",&N);getchar();
		for(int i=1;i<=N;i++)
			scanf("%s",s[i]+1);
		int Next[2010],win=-1;
		bool vis[510];
		memset(vis,false,sizeof vis);
		for(int i=1;i<=N;i++)
		{
			len1=strlen(s[i]+1);
			getNext(Next,s[i]);
			for(int j=i+1;j<=N;j++)
			{
				if(vis[j]) continue;
				len2=strlen(s[j]+1);
				if(KMP(Next,s[j],s[i]))  break;
				else
				{
					win=max(win,j);
					vis[j]=true;
				}
			}
		}
		printf("Case #%d: %d\n",cas,win);
	}
//	system("pause");
}
/*
5
4
youyouyouyouyou
lovinyouyouyouyouyou
aboutlovinyouyouyouyouyou
allaboutlovinyouyouyouyouyou

4
x
xxss
xxxs
xxxss
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000010;
int Next[maxn];
char s[maxn];
void getNext()
{
	int len=strlen(s);
	Next[0]=0;
	for(int i=1;i<len;i++)
	{
		int t=Next[i];
		while(t&&s[i]!=s[t]) t=Next[t];
		Next[i+1]=s[i]==s[t]?t+1:0;
	}
}
int main()
{
	while(scanf("%s",s)==1)
	{
		if(s[0]=='.') break;
		getNext();
		int i=strlen(s),ans=1,len=i;
		while(i)
		{
			if(Next[i]>0&&len%(len-Next[i])==0){ans=len/(len-Next[i]);break;}
			else i=Next[i];		
		}
		printf("%d\n",ans);
	}
}
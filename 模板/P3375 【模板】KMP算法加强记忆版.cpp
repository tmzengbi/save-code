#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int Next[1000010];
char s1[1000010],s2[1000010];
void getNext(char *s)
{
	int len=strlen(s),j=0;
	Next[0]=-1;Next[1]=0;
	for(int i=1;i<len;i++)
	{
		j=Next[i];
		while(j&&s[i]!=s[j]) j=Next[j];
		Next[i+1]=s[i]==s[j]?j+1:0;
	}
}
void kmp(char *s1,char *s2)
{
	int len1=strlen(s1),len2=strlen(s2),j=0;
	for(int i=0;i<len1;i++)
	{
		while(j&&s1[i]!=s2[j]) j=Next[j-1]+1;
		if(s1[i]==s2[j]) j++;
		if(j==len2) printf("%d\n",i-len2+2);
	}	
}
int main()
{

	scanf("%s%s",s1,s2);
	getNext(s2);
	kmp(s1,s2);
	int len=strlen(s2);
	for(int i=1;i<=len;i++)
		printf("%d ",Next[i]);
	system("pause");
}
/*
abcdabcdabd
abcdabd
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int N,Next[1000010];
char s[1000010];
void getNext(char *s1)
{
	Next[0]=-1;Next[1]=0;
	int len=strlen(s1),j;
	for(int i=1;i<len;i++)
	{
		j=Next[i];
		while(j&&s1[i]!=s1[j]) j=Next[j];
		Next[i+1]=s1[i]==s1[j]?j+1:0;
	}
}
int main()
{
	int kase=0;
	while(scanf("%d",&N)==1&&N)
	{
		scanf("%s",s);
		getNext(s);
		printf("Test case #%d\n",++kase);
		for(int i=2;i<=N;i++)
		{
			int d=i-Next[i];
			if(i%d==0&&i>d)
				printf("%d %d\n",i,i/d);
		
		}
		printf("\n");
	}
//	system("pause");
}
/*
3 aaa 12 aabaabaabaab
*/
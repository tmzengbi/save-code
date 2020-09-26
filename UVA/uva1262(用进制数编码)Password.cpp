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
typedef pair<int,int>pii;
const int maxn=5e4;
char s1[10][10],s2[10][10];
char ch[10][10];
int Index[10];
int k,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(Index,0,sizeof Index);
		scanf("%d",&k);
		for(int i=0;i<6;i++) scanf("%s",s1[i]);
		for(int i=0;i<6;i++) scanf("%s",s2[i]);
		int Max=1;
		for(int i=0;i<5;i++)
		{
			int t1=0,t2=0;
			for(int j=0;j<6;j++)
				t1|=(1<<(s1[j][i]-'A'));
			for(int j=0;j<6;j++)
				t2|=(1<<(s2[j][i]-'A'));
			int t=t1&t2;
			for(int j=0;j<26;j++)
				if(t&(1<<j)) ch[i][Index[i]++]='A'+j;
			Max=Max*Index[i];
		}
		if(k>Max) printf("NO\n");
		else
		{
			--k;
			char ans[10];
			for(int i=4;i>=0;i--)
			{
				ans[i]=ch[i][k%Index[i]];
				k=k/Index[i];
			}
			for(int i=0;i<5;i++)
				putchar(ans[i]);
			puts("");
		}
	}
//	system("pause");
}
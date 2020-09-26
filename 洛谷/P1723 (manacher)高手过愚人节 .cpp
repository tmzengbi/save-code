#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5000010;
char s[maxn<<2],s0[maxn];
int P[maxn<<2],ans=0,mk=1;
void Manacher(int n)
{
//	memset(P,0,sizeof P);
	ans=0;
	int r=0,c=0;
	for(int i=1;i<=n;i++)
	{
		int ii=c-i+c;
		if(i>r||P[ii]>=r-i)
		{
			if(i>r) P[i]=0;
			else P[i]=r-i;
			while((i-P[i]-1)>=1&&(i+P[i]+1)<=n&&s[i-P[i]-1]==s[i+P[i]+1]) P[i]++;
			c=i;r=c+P[i];

		}
		else P[i]=P[ii];
		ans=max(ans,P[i]);
		
	}
/*
		for(int i=1;i<=n;i++)
			printf("%d ",P[i]);
		printf("\n");
*/
}
int main()
{
	char ch;int Index=0;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);getchar();
	while(n--)
	{
		scanf("%s",s0+1);
		int len=strlen(s0+1);
		s[1]='#';
		for(int i=1;i<=len;i++)
		{
			s[i*2]=s0[i];
			s[i*2+1]='#';
		}
		Manacher(len*2+1);
		printf("%d\n",ans);
	}

//	system("pause");
}
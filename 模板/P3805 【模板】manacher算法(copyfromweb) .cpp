#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=11000010;
char s[maxn<<2],s0[maxn];
int P[maxn<<2],Max=0;
void Manacher(int n)
{
	int r=0,c=0;
	for(int i=1;i<=n;i++)
	{
		int ii=c-i+c,diff=r-i;
		if(diff>=0)
		{
			if(P[ii]<diff) P[i]=P[ii];
			else
			{
				P[i]=diff;
				while((i+P[i]+1)<=n&&(i-P[i]-1)>0&&s[i+P[i]+1]==s[i-P[i]-1]) P[i]++;
				c=i;r=i+P[i];
			}
		}
		else
		{
			P[i]=0;
			while((i+P[i]+1)<=n&&(i-P[i]-1)>0&&s[i+P[i]+1]==s[i-P[i]-1]) P[i]++;
			c=i;r=i+P[i];
		}
		Max=max(Max,P[i]);
		
	}
	for(int i=1;i<=n;i++) cout<<P[i]<<" ";
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%s",s0+1);
	int len=strlen(s0+1);
	s[1]='#';
	for(int i=1;i<=len;i++)
	{
		s[i*2]=s0[i];
		s[i*2+1]='#';
	}
	Manacher(len*2+1);

	printf("%d\n",Max);
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5010;
const int inf=1e7;
int T,st[27][2],ed[27][2],col[maxn][maxn],dp[maxn][maxn];
char s1[maxn],s2[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(st,0,sizeof st);
		memset(ed,0,sizeof ed);
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		for(int i=1;i<=len1;i++)
		{
			int c=s1[i]-'A'+1;
			if(st[c][0]==0)	st[c][0]=i;
			ed[c][0]=i;
		}
		for(int i=1;i<=len2;i++)
		{
			int c=s2[i]-'A'+1;
			if(st[c][1]==0)	st[c][1]=i;
			ed[c][1]=i;
		}
		col[0][0]=0;
		dp[0][0]=0;
		for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{
				if(i>0)
				{
					col[i][j]=col[i-1][j];
					int c=s1[i]-'A'+1;
					if(i==st[c][0]&&(j<st[c][1]||st[c][1]==0))	col[i][j]++;
					if(i==ed[c][0]&&j>=ed[c][1]) col[i][j]--;	
				}
				else if(j>0)
				{
					col[i][j]=col[i][j-1];
					int c=s2[j]-'A'+1;
					if(j==st[c][1]&&(i<st[c][0]||st[c][0]==0)) col[i][j]++;
					if(j==ed[c][1]&&i>=ed[c][0]) col[i][j]--;
				}
				
			}
		}
		for(int i=0;i<=len1;i++)
		{
			for(int j=0;j<=len2;j++)
			{
				int t1=inf,t2=inf;
				if(i>0)	t1=dp[i-1][j]+col[i-1][j];
				if(j>0)	t2=dp[i][j-1]+col[i][j-1];
//				cout<<i<<" "<<j<<"\t"<<t1<<" "<<t2<<endl;
				if(i!=0||j!=0) dp[i][j]=min(t1,t2);
			}
		}
/*		for(int i=0;i<=len1;i++)
				{
					for(int j=0;j<=len2;j++)
						cout<<i<<" "<<j<<"\t"<<col[i][j]<<endl;
					cout<<endl;
				}
*/
/*		for(int i=1;i<=26;i++)
			cout<<char(i+'A'-1)<<"\t"<<st[i][0]<<" "<<st[i][1]<<" "<<ed[i][0]<<" "<<ed[i][1]<<endl;
*/
/*		for(int i=0;i<=len1;i++)
				{
					for(int j=0;j<=len2;j++)
						cout<<i<<" "<<j<<"\t"<<dp[i][j]<<endl;
					cout<<endl;
				}		
*/
		cout<<dp[len1][len2]<<endl;

	}
//	system("pause");
}
/*
1 AAABBCY ABBBCDEEY 

2 AAABBCY ABBBCDEEY GBBY YRRGB
*/
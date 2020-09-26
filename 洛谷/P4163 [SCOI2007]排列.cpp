#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=10;const int D=1010;
int dp[1<<M][D],d,bit[1<<M];
char num[11];
int main()
{
	int t;
	scanf("%d",&t);getchar();
	while(t--)
	{
		memset(bit,0,sizeof bit);
		memset(dp,0,sizeof dp);
		scanf("%s%d",num,&d);
		int len=strlen(num);
		dp[0][0]=1;
		for(int i=0;i<(1<<len);i++)
		{
			for(int k=0;k<len;k++)
				if(i&1)	bit[i]++;
		}
//		for(int i=0;i<len;i++)
//			dp[1<<i][(num[i]-'0')%d]=1;
		for(int i=0;i<(1<<len);i++)
		{
			for(int j=0;j<len;j++)
			{
				if(i&(1<<j))	continue;
				for(int k=0;k<d;k++)
					dp[i|(1<<j)][(k*10+num[j]-'0')%d]+=dp[i][k];
			}
		}
//		cout<<dp[(1<<len)-1][0]<<endl;
//		for(int i=0;i<d;i++)
//			cout<<i<<" "<<dp[(1<<len)-1][i]<<endl;
		int ans=dp[(1<<len)-1][0];
		int to[11]={0};
		for(int i=0;i<10;i++)
			to[num[i]-'0']++;
		for(int i=0;i<10;i++)
			for(int j=2;j<=to[i];j++)
				ans/=j;
		printf("%d\n",ans);
	}
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,dp[1010];
char s[1010];
bool hw(int l,int r)
{
	bool y=true;
	while(l<r)
	{
		if(s[l]!=s[r]){y=false;break;}
		l++;r--;
	}
	return y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=0;i<=n;i++)
			dp[i]=i;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(hw(j,i))	dp[i]=min(dp[i],dp[j-1]+1);
			}
		}
		cout<<dp[n]<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<dp[i]<<" ";
	//	cout<<endl;
	}
//	system("pause");

}
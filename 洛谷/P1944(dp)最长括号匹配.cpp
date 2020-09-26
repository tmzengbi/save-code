#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e6+10;
int n,dp[maxn],Index=0,p[maxn];
char s[maxn],c[maxn];
int main()
{
	scanf("%s",c+1);
	n=strlen(c+1);
	int Max=0;pii ans;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='('||c[i]=='[') p[Index]=i,s[Index++]=c[i];
		else if(Index)
		{
			if(s[--Index]==(c[i]==']'?'[':'(')) 
			{
				dp[i]=dp[p[Index]-1]+i-p[Index]+1;
				if(Max<dp[i]){Max=dp[i];ans=make_pair(i-dp[i]+1,i);}
			}
			else Index=0;
		}
	}
	for(int i=ans.first;i<=ans.second;i++)
		printf("%c",c[i]);
//	system("pause");
}
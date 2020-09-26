#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int t,n[4];
char s[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(n,0,sizeof n);
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='U') n[0]++;
			if(s[i]=='R') n[1]++;
			if(s[i]=='L') n[2]++;
			if(s[i]=='D') n[3]++;
		}
		int k1=min(n[0],n[3]),k2=min(n[1],n[2]);
		if(k1==0) k2=min(k2,1);
		if(k2==0) k1=min(k1,1);
		printf("%d\n",2*(k1+k2));
		for(int i=1;i<=k1;i++) putchar('U');
		for(int i=1;i<=k2;i++) putchar('R');
		for(int i=1;i<=k1;i++) putchar('D');
		for(int i=1;i<=k2;i++) putchar('L');
		puts("");
	}
//	system("pause");
}
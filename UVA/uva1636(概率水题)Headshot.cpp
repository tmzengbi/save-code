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
const int maxn=110;
char s[maxn];
int main()
{
	while(scanf("%s",s)==1)
	{
		int n=strlen(s);
		pii sh(0,0),ro(0,n);
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') ro.first++,sh.second++;
			if(s[i]=='0'&&s[(i+1)%n]=='0') sh.first++;
		}
		int ck1=sh.first*ro.second,ck2=sh.second*ro.first;
		if(ck1==ck2) printf("EQUAL\n");
		else if(ck1>ck2) printf("SHOOT\n");
		else printf("ROTATE\n");
	}
}
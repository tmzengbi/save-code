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
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
//stack
pii s[maxn];
int Index;
//main
int n,l,a[maxn],p[maxn],t;
char ss[maxn];
bool cmp(const pii&a,const pii&b,const pii&c)
{
	return abs((ll)(b.second-a.second)*(c.first-b.first))<=abs((ll)(c.second-b.second)*(b.first-a.first));
}
double calc(const pii&a,const pii&b)
{
	return (double)(b.second-a.second)/(b.first-a.first);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&l);
		scanf("%s",ss+1);
		Index=0;
		for(int i=1;i<=n;i++) a[i]=ss[i]-'0';
		for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
		int mk=0;
		pii ans;double ct=0;
		int len=2e9;
		for(int i=l;i<=n;i++)
		{
			pii preadd(i-l,p[i-l]);
			if(Index<2) s[Index++]=preadd;
			else
			{
				while(Index>=2&&!cmp(s[Index-2],s[Index-1],preadd)) Index--;
				s[Index++]=preadd;	
			}
			mk=min(mk,Index-1);
			while(mk+1<Index)
			{
				if(cmp(s[mk],make_pair(i,p[i]),s[mk+1])) mk++;
				else break;
			}
			double it=calc(s[mk],make_pair(i,p[i]));
			if(ct<it||ct==it&&len>i-s[mk].first)
			{
				ct=it;
				len=i-s[mk].first;
				ans=make_pair(s[mk].first,i);
			}

//			printf("%lf %d %d\n",it,s[mk].first,i); 
		}
		printf("%d %d\n",ans.first+1,ans.second);
	}
//	system("pause");
}
/*
100
17 5
00101011011011010

2 17 5 00101011011011010 20 4 11100111100111110000
*/
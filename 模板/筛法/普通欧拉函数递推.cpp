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
#include<bitset>
using namespace std;
typedef long long ll;
const int maxn=3e3+10;
int n;
int auler[maxn];
void sieve()
{
	auler[1]=1;
	for(int i=2;i<=maxn;i++) if(!auler[i])
		for(int j=i;j<=maxn;j+=i)
		{
			if(!auler[j]) auler[j]=j;
			auler[j]=auler[j]/i*(i-1);
		}
}
int main()
{
	sieve();
	for(int i=1;i<=10;i++)
		printf("%d %d\n",i,auler[i]);
	system("pause");
}
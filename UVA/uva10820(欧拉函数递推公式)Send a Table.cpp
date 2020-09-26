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
const int maxn=5e4;
int euler[maxn+10];
void presolve()
{
	euler[1]=1;
	for(int i=2;i<=maxn;i++) if(!euler[i])
	{
		for(int j=i;j<=maxn;j+=i)
		{
			if(!euler[j]) euler[j]=j;
			euler[j]=euler[j]/i*(i-1);
		}
	}
	for(int i=2;i<=maxn;i++)
		euler[i]+=euler[i-1];
}
int n;
int main()
{
	presolve();
	while(scanf("%d",&n)==1&&n)
	{
		printf("%d\n",(euler[n]-euler[1])*2+1); 
	}
}
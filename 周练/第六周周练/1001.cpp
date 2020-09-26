#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector<int>f[3];
int N,p[2],sum=0,tot=0;

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		char s[3];int k;
		scanf("%s %d",s,&k);
		if(strcmp(s,"11")==0) sum+=k,tot++;
		if(strcmp(s,"01")==0) f[0].push_back(k);
		if(strcmp(s,"10")==0) f[1].push_back(k);
		if(strcmp(s,"00")==0) f[2].push_back(k);
	}
	for(int i=0;i<2;i++) sort(f[i].begin(),f[i].end(),greater<int>());
	int lar=f[0].size()>f[1].size()?1:0,k=0;
	for(int i=0;i<f[lar].size();i++,k++)
		sum+=f[lar][i]+f[lar^1][i];
	for(int i=k;i<f[lar^1].size();i++)
		f[2].push_back(f[lar^1][i]);
	sort(f[2].begin(),f[2].end(),greater<int>());
	for(int i=0;i<tot&&i<f[2].size();i++)
		sum+=f[2][i];
	printf("%d\n",sum);
	
//	system("pause");
}
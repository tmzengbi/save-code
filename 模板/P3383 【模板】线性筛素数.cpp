#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector> 
using namespace std;
vector <int> ss;
int shu[10000010];
int main()
{
	memset(shu,0,sizeof shu);
	int N,m;
	scanf("%d%d",&N,&m);
	for(int i=2;i<=10000000;i++)
	{
		if(!shu[i]){shu[i]=i;ss.push_back(i);}
		for(int j=0;i*ss[j]<=10000000;j++)
		{
			shu[i*ss[j]]=ss[j];
			if(i%ss[j]==0)	break;
		}
	}
	while(m--)
	{
		int k;
		scanf("%d",&k);
		if(shu[k]==k)
			printf("Yes\n");
		else printf("No\n");
	}
}

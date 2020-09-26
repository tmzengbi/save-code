#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace  std;
vector<int> v;
int T,N,M,num[10010],k[10010];
void eular()
{
	memset(k,0,sizeof k);
	for(int i=2;i<=10000;i++)
	{
		if(k[i]==0){k[i]=i;num[i]=1;v.push_back(i);}
		for(int j=0;j<v.size();j++)
		{
			if(v[j]*i<=10000){k[i*v[j]]=v[j];num[i*v[j]]=num[i]+1;}
			if(i%v[j]==0)	break;
		}
	}
}
int main()
{
	memset(num,0,sizeof num);
	scanf("%d",&T);
	eular();
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&N,&M);
		int sum=0,ans=0;
		for(int i=1;i<=N;i++)
		{
			sum=0;
			for(int j=1;j<=M;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				sum+=num[tmp];
			}
			ans=ans^sum;
		}
		if(ans==0)	printf("Case #%d: NO\n",tt);
		else printf("Case #%d: YES\n",tt);
	}
//	system("pause");
}
/*
5 
2 2
2 3 
2 3 

2 2 
4 9 
8 5 

3 3 
2 3 5 
3 9 2 
8 8 3 

3 3 
3 4 5 
4 5 6 
5 6 7 

2 3 
4 5 
6 7 
8 9
*/
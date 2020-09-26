#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=20010;
int pre[maxn],d[maxn],T;
int Find(int r)
{
	if(r==pre[r]) return r;
	int t=Find(pre[r]);
	d[r]+=d[pre[r]];
	return pre[r]=t;
}
void merge(int u,int v)
{
	d[u]=abs(u-v)%1000;
	pre[u]=v;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) d[i]=0;
		for(int i=1;i<=n;i++) pre[i]=i;
		char mod[2];
		while(scanf("%s",mod)==1)
		{
			if(mod[0]=='O') break;
			if(mod[0]=='E')
			{
				int x;scanf("%d",&x);
				Find(x);
				printf("%d\n",d[x]);
//				for(int i=1;i<=n;i++)
//					printf("%d ",d[i]);
//				printf("\n");
			}
			if(mod[0]=='I')
			{
				int x,y;scanf("%d%d",&x,&y);
				merge(x,y);
			}
		}
	}
//	system("pause");
}
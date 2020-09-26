#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge
{
	int u,v,d;
	bool operator <(const Edge E) const
	{
		return d<E.d; 
	}
}edge[5010];
int pre[110],N,M;;
int findroot(int a)
{
	if(pre[a]==a) return a;
	else pre[a]=findroot(pre[a]);
	return pre[a];
}
void merge(int a,int b)
{
	a=findroot(a);b=findroot(b);
	if(a!=b) pre[a]=b;
}
bool kru(int s,int &r)
{
	for(int i=1;i<=N;i++) pre[i]=i;
	int cnt=0;
	for(int i=s;i<=M;i++)
	{
		int u=edge[i].u,v=edge[i].v;
		u=findroot(u);v=findroot(v);
		if(u!=v)
		{
			cnt++;
			merge(u,v);
		}
		if(cnt==N-1){r=i;return true;}
	}
	return false;
}
int main()
{

	while(scanf("%d%d",&N,&M))
	{
		if(N==0&&M==0) break;
		for(int i=1;i<=N;i++) pre[i]=i;
		for(int i=1;i<=M;i++)
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].d);
		sort(edge+1,edge+M+1);
		int ans=1e9;
		for(int i=1;i<=M;i++)
		{
			int r;
			if(kru(i,r)) ans=min(edge[r].d-edge[i].d,ans);
			else break;
		}
		if(ans==1e9) ans=-1;
		printf("%d\n",ans);
	}
}
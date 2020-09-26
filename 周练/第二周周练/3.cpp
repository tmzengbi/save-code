#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	int v,rank;
}a[100010];
bool cmp(Node N1,Node N2)
{
	return N1.v<N2.v;
}
int main()
{
	int N;scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i].v);
		a[i].rank=i;
	}
	sort(a+1,a+N+1,cmp);
	int ans=0;
	bool vis[100010];
	memset(vis,false,sizeof vis);
	for(int i=1;i<=N;i++)
	{
		int tmp=i;
		while(a[tmp].rank!=tmp)
		{
			swap(a[tmp],a[a[tmp].rank]);
			tmp=a[tmp].rank;
			ans++;
		}
	}
	printf("%d\n",ans);

}
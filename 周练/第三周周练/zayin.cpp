#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	int c,d;
	bool operator < (const Node N) const
	{
		return c>N.c;
	}
}p[100010];
int n,m,b[100010];
long long ans=0;
priority_queue<Node>q;
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp2(Node N1,Node N2)
{
	return N1.d<N2.d;
}
int main()
{
	bool win=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=m;i++) scanf("%d%d",&p[i].c,&p[i].d);
	sort(b+1,b+n+1,cmp);
	sort(p+1,p+m+1,cmp2);
	int k=m;
	for(int i=1;i<=n;i++)
	{
		while(p[k].d>=b[i]&&k)
		{
			q.push(p[k]);
			k--;
		}
		if(q.empty()){win=false;break;}
		Node s=q.top();q.pop();
		ans+=s.c;
	}
	if(win) printf("%lld\n",ans);
	else printf("-1\n");
	system("pause");
}
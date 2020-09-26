#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
using namespace std;
int T,a[4];
const int maxn=210;
struct Node
{
	int f[3],dist;
	bool operator <(const Node &N)const
	{
		return dist>N.dist;
	}
};
int ans[maxn];
bool vis[maxn][maxn];
void solve()
{
	memset(ans,-1,sizeof ans);
	memset(vis,false,sizeof vis);
	priority_queue<Node>q;
	Node s;s.dist=0;
	int f[3]={0,0,a[2]};
	memcpy(s.f,f,sizeof(int)*3);
	while(!q.empty()) q.pop();
	q.push(s);
	while(!q.empty())
	{
		Node u=q.top();q.pop();
		if(vis[u.f[0]][u.f[1]]) continue;
		for(int k=0;k<3;k++)
		{
			if(ans[u.f[k]]<0||ans[u.f[k]]>u.dist)
				ans[u.f[k]]=u.dist;
		}
		if(ans[a[3]]!=-1) break;
		vis[u.f[0]][u.f[1]]=1;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				Node v=u;
				if(i==j) continue;
				if(v.f[i]==0) continue;
				if(v.f[j]==a[j]) continue;
				int d=v.f[i]+v.f[j];
				if(d>a[j]){v.dist+=a[j]-v.f[j];v.f[j]=a[j];v.f[i]=d-a[j];}
				else{v.dist+=v.f[i];v.f[j]=d;v.f[i]=0;}
				q.push(v);
			}
	}
	for(int i=a[3];i>=0;i--)
		if(ans[i]!=-1)
		{
			printf("%d %d\n",ans[i],i);
			break;
		}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<4;i++) scanf("%d",&a[i]);
		solve();
	}
//	system("pause");
}
/*
2 2 3 4 2 96 97 199 62
*/
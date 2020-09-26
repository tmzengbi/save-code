#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
struct Node
{
	int u,d;
	Node(int u,int d):u(u),d(d){}
	bool operator < (const Node N)const
	{
		return d>N.d;
	}
};
int n,m,t[110],dis[1100000];	//t指打补丁的时间
char s1[110][21],s2[110][21];	//s1打补丁前 s2打补丁后
bool vis[1100000];				//其他都是写dijkstra的辅助数组
struct Solve
{
    int N,M;
	void init(int N,int M)		//初始化
	{
		this->N=N;this->M=M;
		memset(vis,false,sizeof vis);
	}
	bool check(int x,int now)	//状态now能否打上第x个补丁
	{
		int tmp=now;
		for(int i=0;i<N;i++)
		{
			int j=N-i-1;
			if(s1[x][i]!='0')
			{
				if(s1[x][i]=='-'&&((now>>j)&1)) return false;
				if(s1[x][i]=='+'&&((now>>j)&1)==0) return false;
			}
		}
		return true;
	}
	void change(int x,int &now)	//状态now打上补丁x后变成什么状态
	{
		for(int i=0;i<N;i++)
		{
			int j=N-i-1;
			if(s2[x][i]=='+') now=now|(1<<j);
			if(s2[x][i]=='-') now=now&(~(1<<j));
		}
	}
	void showmethedata()		//debug用的函数
	{
		for(int i=0;i<(1<<N);i++)
			printf("%d %d\n",i,dis[i]);
	}
	int dij()					//dijkstra堆优化板子
	{
		priority_queue<Node>q;
		q.push(Node( (1<<N)-1,0));
		for(int i=0;i<(1<<N);i++)
			dis[i]=1e8;
		dis[(1<<N)-1]=0;
		while(!q.empty())
		{
			Node e=q.top();q.pop();
			if(e.u==0) return dis[0];
			if(vis[e.u]) continue;
			vis[e.u]=true;
			for(int i=1;i<=M;i++)//枚举m个补丁找边
			{
				int v=e.u;
				if(check(i,v))
				{
					change(i,v);
					if(t[i]+dis[e.u]<dis[v])
					{
						dis[v]=dis[e.u]+t[i];
						q.push(Node(v,dis[v]));
					}
				}
			}
		}
		return -1;
	}

}solver;
int main()
{
	int T=0;
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
//		if(T) printf("\n");
		solver.init(n,m);
		for(int i=1;i<=m;i++)
			scanf("%d %s %s",&t[i],s1[i],s2[i]);
		printf("Product %d\n",++T);
		int ans=solver.dij();
		if(ans>=0) printf("Fastest sequence takes %d seconds.\n\n",ans);
		else printf("Bugs cannot be fixed.\n\n");
	}
//	system("pause");
}
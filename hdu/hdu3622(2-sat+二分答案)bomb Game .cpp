#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=210;
const double prec=0.00001;
int N,M,a1[maxn],a2[maxn],b1[maxn],b2[maxn];
struct two_sat
{
	int N,c,s[maxn];
	bool mark[maxn];
	vector<int> edges[maxn];
	void init(int N)
	{
		this->N=N;
		memset(mark,0,sizeof mark);
		for(int i=0;i<2*N;i++)	edges[i].clear();
	}
	void addedge(int x,int a,int y,int b)
	{
		x=x*2+a;y=y*2+b;
		edges[x].push_back(y^1);
		edges[y].push_back(x^1);
	}
	bool dfs(int u)
	{
		if(mark[u^1]) return false;
		if(mark[u]) return true;
		mark[u]=true;
		s[c++]=u;
		for(int i=0;i<edges[u].size();i++)
		{
			int v=edges[u][i];
			if(!dfs(v)) return false;
		}
		return true;
	}
	bool solve()
	{
		for(int i=0;i<N*2;i+=2)
		{
			if(!mark[i]&&!mark[i+1])
			{
				c=0;
				if(!dfs(i))
				{
					while(c>0) mark[s[--c]]=false;
					if(!dfs(i+1)) return false;
				}
			}
		}
		return true;
	}
}solver;
inline double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		for(int i=0;i<N;i++)
			scanf("%d%d%d%d",&a1[i],&a2[i],&b1[i],&b2[i]);
		double l=0,r=40000.0,mid;
//		while(r-l>=prec)
		for(int t=1;t<=50;t++)
		{
			mid=(l+r)/2;
			solver.init(N);
			for(int i=0;i<N;i++)
				for(int j=i+1;j<N;j++)
				{
					double d1,d2,d3,d4;
					d1=dis(a1[i],a2[i],b1[j],b2[j]);
					d2=dis(a1[i],a2[i],a1[j],a2[j]);
					d3=dis(b1[i],b2[i],b1[j],b2[j]);
					d4=dis(b1[i],b2[i],a1[j],a2[j]);
					if(d1<mid*2) solver.addedge(i,0,j,1);
					if(d2<mid*2) solver.addedge(i,0,j,0);
					if(d3<mid*2) solver.addedge(i,1,j,1);
					if(d4<mid*2) solver.addedge(i,1,j,0);
				}
			if(solver.solve()) l=mid;
			else r=mid;
		}
		printf("%.2lf\n",mid);
	}

}
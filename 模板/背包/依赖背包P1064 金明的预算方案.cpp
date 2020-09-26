#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1010;
struct Node
{
	int v,p;
	Node(int v,int p):v(v),p(p){}
};
vector<int>son[maxn];
vector<int>r;
vector<Node>part[maxn];
int N,M,v[maxn],p[maxn],f[100010],Max=0;
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int m;
		scanf("%d%d%d",&v[i],&p[i],&m);
		if(m) son[m].push_back(i);
		else r.push_back(i);
	}
	for(int i=0;i<r.size();i++)
	{
		int m=r[i];
		memset(f,-1,sizeof f);
		f[0]=0;
		for(int j=0;j<son[m].size();j++)
		{
			int s=son[m][j];
			for(int k=N-v[m];k>=v[s];k--)
				if(f[k-v[s]]!=-1&&f[k]<f[k-v[s]]+v[s]*p[s])
					f[k]=f[k-v[s]]+v[s]*p[s];
		}
		for(int k=0;k<=N-v[m];k++)
			if(f[k]!=-1) part[i].push_back(Node(k+v[m],f[k]+v[m]*p[m]));
	}
	memset(f,0,sizeof f);
	for(int i=0;i<r.size();i++)
		for(int k=N;k>=0;k--)
			for(int j=0;j<part[i].size();j++)
			{
				Node t=part[i][j];
				if(k>=t.v)
					f[k]=max(f[k],f[k-t.v]+t.p);
			}
	int Max=0;
/*
	for(int i=0;i<r.size();i++)
	{
		for(int j=0;j<part[i].size();j++)
		{
			Node t=part[i][j];
			cout<<t.v<<" "<<t.p<<endl;
		}
		cout<<endl;
	}
*/
	for(int i=0;i<=N;i++)
		Max=max(Max,f[i]);
	printf("%d\n",Max);
	
//	system("pause");
}
/*
10 5
8 2 0
4 5 1
3 5 1
4 3 0
5 2 0

10 5
2 2 0
2 3 1
5 1 0
4 5 3
1 1 0
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
map<string,int>M;
int n,m,l,e[210][210];
int pre[maxn];
vector<int>edges[maxn];
int in[maxn],a[maxn];
string s[210];
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++)
	{
		string ss;cin>>ss;
		M[ss]=1;
	}
	int cnt=0;
	for(auto&it:M)
	{
		it.second=++cnt;
		s[cnt]=it.first;
	}
	for(int i=1;i<=m;i++)
	{
		string ss1,ss2;cin>>ss1>>ss2;
//		cout<<M[ss1]<<" "<<M[ss2]<<endl;
		int t1=M[ss1],t2=M[ss2];
		e[t1][t2]=e[t2][t1]=1;
	}
	for(int i=1;i<=l;i++)
	{
		string ss;cin>>ss;
		int t=M[ss];
		a[i]=t;
		for(int j=1;j<=n;j++)
			if(pre[j]&&!e[t][j])
			{
				edges[pre[j]].push_back(i);
				in[i]++;
			}
		pre[t]=i;
	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=l;i++)
		if(!in[i]) q.push(make_pair(a[i],i));
	while(!q.empty())
	{
		pii u=q.top();q.pop();
		cout<<s[u.first]<<" ";
		for(int v:edges[u.second])
		{
			in[v]--;
			if(in[v]==0) q.push(make_pair(a[v],v));
		}
	}
//	system("pause");
}
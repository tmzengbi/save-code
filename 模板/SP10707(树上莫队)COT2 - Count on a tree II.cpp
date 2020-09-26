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
const int maxn=4e4+10;
const int maxq=100010;
int n,m,cnt[maxn],a[maxn],dep[maxn],st[maxn],ed[maxn],Index=0,pos[maxn<<1],pre[maxn][22];
vector<int>edges[maxn];
map<int,int>M;
void dfs(int u,int fa)
{
	pos[++Index]=u;st[u]=Index;
	for(int v:edges[u])
	{
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		pre[v][0]=u;
		for(int i=1;dep[v]-(1<<i)>=0;i++)
			pre[v][i]=pre[pre[v][i-1]][i-1];
		dfs(v,u);
	}
	pos[++Index]=u;ed[u]=Index;
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=20;i>=0&&dep[a]!=dep[b];i--)
		if(dep[a]-(1<<i)>=dep[b]) a=pre[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
		if(pre[a][i]!=pre[b][i]) a=pre[a][i],b=pre[b][i];
	return pre[a][0];
}
struct Node
{
	int l,r,id,add;
}p[maxq];
int belong[maxn<<1],bk,ans[maxq],sum=0,tag[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.l]&1)?rhs1.r<rhs2.r:rhs1.r>rhs2.r);
}
inline void del(int x)
{
	cnt[a[x]]--;
	if(!cnt[a[x]]) sum--;
}
inline void add(int x)
{
	if(!cnt[a[x]]) sum++;
	cnt[a[x]]++;
}
inline void update(int x)
{
	if(tag[x]) del(x);
	else add(x);
	tag[x]^=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n*2;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(!M.count(a[i])) M[a[i]]=++c;
		a[i]=M[a[i]];
	}
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,1);
	for(int i=1;i<=m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(st[u]>st[v]) swap(u,v);
		int r=getlca(u,v);
		if(u==r){p[i].l=st[u];p[i].r=st[v];p[i].id=i;p[i].add=0;}
		else{p[i].l=ed[u];p[i].r=st[v];p[i].id=i;p[i].add=r;}
	}
	sort(p+1,p+m+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(l<p[i].l) update(pos[l++]);
		while(l>p[i].l) update(pos[--l]);
		while(r<p[i].r) update(pos[++r]);
		while(r>p[i].r) update(pos[r--]);
		if(p[i].add) update(p[i].add);
		ans[p[i].id]=sum;
		if(p[i].add) update(p[i].add);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
//	system("pause");
}
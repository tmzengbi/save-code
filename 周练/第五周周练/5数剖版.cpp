#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20010;
int N,Q,a[maxn],First[maxn],belong[maxn],Size[maxn],dep[maxn],cnt=0;
int son[maxn],f[maxn],top[maxn],sumv[maxn<<2];
vector<int>edges[maxn];
void dfs1(int u,int fa)
{
	f[u]=fa;
	Size[u]=1;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v!=fa)
		{
			dep[v]=dep[u]+1;
			dfs1(v,u);
			Size[v]+=Size[u];
			if(Size[v]>Size[son[u]]) son[u]=v;
		}
	}
}
void dfs2(int u,int tp)
{
	First[u]=++cnt;
	belong[cnt]=u;
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==son[u]||v==f[u])continue;
		dfs2(v,v);
	}
}
void build(int o,int l,int r)
{
	if(l==r){sumv[o]=a[belong[l]];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
void update(int o,int l,int r,int q,int v)
{
	if(l==r) {sumv[o]=v;return;}
	int mid=(l+r)>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
	sumv[o]=sumv[o<<1]+sumv[o<<1|1];
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return sumv[o];
	int mid=(l+r)>>1,sum=0;
	if(ql<=mid) sum+=query(o<<1,l,mid,ql,qr);
	if(mid<qr) sum+=query(o<<1|1,mid+1,r,ql,qr);
	return sum;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs1(1,1);dfs2(1,1);
	build(1,1,cnt);
	scanf("%d",&Q);
	while(Q--)
	{
		char mod;int x,y;
		scanf("%s%d%d",&mod,&x,&y);
		if(mod=='Q')
		{
			long long sum=0;
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				sum+=query(1,1,cnt,First[top[x]],First[x]);
				x=f[top[x]];
			}
			if(dep[x]<dep[y])swap(x,y);
			sum+=query(1,1,cnt,First[y],First[x]);
			printf("%lld\n",sum);
		}
		if(mod=='C')
			update(1,1,cnt,First[x],y);
	}
	system("pause");
}
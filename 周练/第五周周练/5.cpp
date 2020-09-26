#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int maxn=20010;
vector<int>edges[maxn];
int val[maxn],N,Q,root,d[maxn],k[maxn],f[maxn],Max=1e9;//求树的重心和树的某些性质
int dep[maxn<<1],first[maxn<<1],dfsIndex[maxn<<1],cnt=0,Log[maxn<<1],st[maxn<<1][20];//求rmq
int dp[maxn],start[maxn],ed[maxn],sumv[maxn<<2],seq[maxn],tot=0,tag[maxn<<2];//dfs序和线段树
inline int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=(shu<<1)+(shu<<3)+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
void build(int o,int l,int r)
{
	if(l==r){sumv[o]=dp[seq[l]];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void pushdown(int o)
{
	if(tag[o]==0) return;
	tag[o<<1]+=tag[o];
	tag[o<<1|1]+=tag[o];
	tag[o]=0;
}
void update(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){tag[o]+=v;return;}
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
}
int Query(int o,int l,int r,int q)
{
	if(q==0) return 0;
	if(l==r) {sumv[o]+=tag[o];tag[o]=0;return sumv[o];}
	int mid=(l+r)>>1;
	pushdown(o);
	if(q<=mid) return Query(o<<1,l,mid,q);
	else return Query(o<<1|1,mid+1,r,q);
}
void Find(int u,int fa)
{
	d[u]=1;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		Find(v,u);
		d[u]+=d[v];
		k[u]=max(d[v],k[u]);
	}
	k[u]=max(k[u],N-d[u]);
	if(Max>k[u]){Max=k[u];root=u;}
}
void rmq(int u,int fa,int depth)
{
	dp[u]=val[u]+dp[fa];
	start[u]=++tot;
	seq[tot]=u;
	//
	dfsIndex[++cnt]=u;
	first[u]=cnt;
	f[u]=fa;
	dep[cnt]=depth;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		rmq(v,u,depth+1);
		dfsIndex[++cnt]=u;
		dep[cnt]=depth;
	}
	ed[u]=tot;
}
void ST()
{
	Log[1]=0;
	for(int i=2;i<=cnt;i++) Log[i]=Log[i/2]+1;
	for(int i=0;i<=Log[cnt];i++)
		for(int j=1;j+(1<<i)-1<=cnt;j++)
		{
			if(i==0) st[j][i]=j;
			else
			{
				int a=st[j][i-1],b=st[j+(1<<(i-1))][i-1];
				st[j][i]=dep[a]<dep[b]?a:b;
			}
			
		}
}
int query(int l,int r)
{
	int dist=Log[r-l+1],a=st[l][dist],b=st[r-(1<<dist)+1][dist];
	return dep[a]<dep[b]?dfsIndex[a]:dfsIndex[b];
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	N=read();
	for(int i=1;i<=N;i++)
		val[i]=read();
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	Find(1,0);rmq(root,0,1);ST();build(1,1,N);
	Q=read();
	while(Q--)
	{
		char o;int a,b;
//		scanf("%s%d%d",&o,&a,&b);
		scanf("%s",&o);
		a=read();b=read();
		if(o=='Q')
		{
			int fa=first[a],fb=first[b];
			if(fa>fb) swap(fa,fb);
			int an=query(fa,fb);
			int ans=Query(1,1,N,start[a])+Query(1,1,N,start[b])-Query(1,1,N,start[an])-Query(1,1,N,start[f[an]]);
			printf("%d\n",ans);
		}
		if(o=='C')
		{
			update(1,1,N,start[a],ed[a],b-val[a]);
			val[a]=b;
		}
	}
//	system("pause");
}
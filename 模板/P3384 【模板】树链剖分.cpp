#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100010;
int N,M,R,P,cnt=0;
int a[maxn],Size[maxn],First[maxn],End[maxn],top[maxn],belong[maxn],son[maxn],f[maxn],dep[maxn];
int sumv[maxn<<2],tag[maxn<<2];
vector<int>edges[maxn];
void dfs1(int u,int fa,int depth)
{
	dep[u]=depth;
	int Max=0;
	Size[u]=1;
	f[u]=fa;
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==fa) continue;
		dfs1(v,u,depth+1);
		Size[u]+=Size[v];
		if(Max<Size[v]){Max=Size[v];son[u]=v;}
	}
}
void dfs2(int u,int tp)
{
	First[u]=++cnt;
	belong[cnt]=u;
	top[u]=tp;
	if(son[u])dfs2(son[u],tp);
	for(int i=0;i<edges[u].size();i++)
	{
		int v=edges[u][i];
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
	End[u]=cnt;
}
void build(int o,int l,int r)
{
	tag[o]=0;
	if(l==r){sumv[o]=a[belong[l]];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%P;
}
void pushdown(int o,int l,int r)
{
	if(tag[o]==0) return;
	int mid=(l+r)>>1;
	tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
	sumv[o<<1]+=tag[o]*(mid-l+1)%P;sumv[o<<1|1]+=tag[o]*(r-mid)%P;
	tag[o]=0;
}
void update(int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){tag[o]+=v;sumv[o]+=v*(r-l+1)%P;return;}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	if(mid>=ql) update(o<<1,l,mid,ql,qr,v);
	if(mid<qr) update(o<<1|1,mid+1,r,ql,qr,v);
	sumv[o]=(sumv[o<<1]+sumv[o<<1|1])%P;
}
int query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return sumv[o];
	int mid=(l+r)>>1;ll sum=0;
	pushdown(o,l,r);
	if(mid>=ql) sum=(sum+query(o<<1,l,mid,ql,qr))%P;
	if(mid<qr) sum=(sum+query(o<<1|1,mid+1,r,ql,qr))%P;
	return sum%P;
}
/*
void pushall(int o,int l,int r)
{
	if(l==r)return;int mid=(l+r)>>1;
	pushdown(o,l,r);
	pushall(o<<1,l,mid);
	pushall(o<<1|1,mid+1,r);
}
*/
int main()
{
	scanf("%d%d%d%d",&N,&M,&R,&P);
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	top[R]=R;
	dfs1(R,R,1);
	dfs2(R,R);
	build(1,1,cnt);
	while(M--)
	{
		int mod;scanf("%d",&mod);
		if(mod==1)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				update(1,1,cnt,First[top[x]],First[x],v);
				x=f[top[x]];
			}
			if(dep[x]<dep[y]) swap(x,y);
			update(1,1,cnt,First[y],First[x],v);
		}
		if(mod==2)
		{
			int x,y;
			ll sum=0;
			scanf("%d%d",&x,&y);
			while(top[x]!=top[y])
			{
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				sum=(sum+query(1,1,cnt,First[top[x]],First[x]))%P;
				x=f[top[x]];
			}
			if(dep[x]<dep[y]) swap(x,y);
			sum=(sum+query(1,1,cnt,First[y],First[x]))%P;
			printf("%lld\n",sum);
		}
		if(mod==3)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			update(1,1,cnt,First[x],End[x],v);
//			pushall(1,1,cnt);
		}
		if(mod==4)
		{
//			pushall(1,1,cnt);
			int x;
			scanf("%d",&x);
			ll sum=query(1,1,cnt,First[x],End[x]);
			printf("%lld\n",sum);
		}
	}
//	system("pause");
}
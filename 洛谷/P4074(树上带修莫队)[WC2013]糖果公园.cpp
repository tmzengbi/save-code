#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int n,m,q;//n->number of nodes,m->types of candies,q->queries
//vector<int>edges[maxn];//edges
struct Edg {
	int Next,to;
}e[maxn<<1];
int head[maxn],ecnt; 
inline void myswap(int &a,int &b){
	if(&a==&b) return;
	a^=b;b^=a;a^=b;
}
inline void add_edge(int u,int v){
	e[++ecnt].to=v;
	e[ecnt].Next=head[u];
	head[u]=ecnt;
}
int a[maxn<<1],fir[maxn],ed[maxn],Index,pre[maxn][22],dep[maxn];//euler and lca
int Log[maxn<<1];
void getpre(int u,int fa){
	a[++Index]=u;fir[u]=Index;
//	for(int v:edges[u])
	for(int i=head[u];i;i=e[i].Next) {
		int v=e[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		pre[v][0]=u;
		for(int i=1;(1<<i)<=dep[v];i++)
			pre[v][i]=pre[pre[v][i-1]][i-1];
		getpre(v,u);
	}
	a[++Index]=u;ed[u]=Index;
}
int getlca(int a,int b){
	if(dep[a]<dep[b]) myswap(a,b);
	for(int i=Log[dep[a]-dep[b]];i>=0&&dep[a]!=dep[b];--i)
		if(dep[a]-(1<<i)>=dep[b]) a=pre[a][i];
	if(a==b) return a;
	for(int i=Log[dep[a]];i>=0;--i)
		if(pre[a][i]!=pre[b][i]) a=pre[a][i],b=pre[b][i];
	return pre[a][0];
}
ll v[maxn],w[maxn];
int c[maxn],belong[maxn<<1],bk;
struct Query {
	int l,r,t,id,lca;
}qy[maxn];
bool cmp(const Query&rhs1,const Query&rhs2) {
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.r]^belong[rhs2.r])?belong[rhs1.r]<belong[rhs2.r]:rhs1.t<rhs2.t);
}
struct Chang {
	int a,b;
}tt[maxn];
ll sum=0;ll ans[maxn];
int cnt[maxn],tag[maxn];
inline void add(int x) {
	cnt[c[x]]++;
	sum+=w[cnt[c[x]]]*v[c[x]];
}
inline void del(int x) {
	sum-=w[cnt[c[x]]]*v[c[x]];
	cnt[c[x]]--;
}
inline void modify(int x) {
	if(tag[x]) del(x);
	else add(x);
	tag[x]^=1;
}
inline int read() {
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
void print(ll x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int main(){
//	scanf("%d%d%d",&n,&m,&q);
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=2;i<=n;i++) Log[i]=Log[i>>1]+1;
	bk=(int)pow(n,0.6667);
	for(int i=1;i<=n*2;i++) belong[i]=(i-1)/bk+1;
	for(int i=1;i<=m;i++) v[i]=read();//scanf("%lld",&v[i]);
	for(int i=1;i<=n;i++) w[i]=read();//scanf("%lld",&w[i]);
	for(int i=1;i<n;i++) { 
		int u,v;//scanf("%d%d",&u,&v);
		u=read();v=read();
//		edges[u].push_back(v);
//		edges[v].push_back(u);
		add_edge(u,v);
		add_edge(v,u);
	}
//	dfs1(1,1);dfs2(1,1);
	getpre(1,1);
	for(int i=1;i<=n;i++) c[i]=read();//scanf("%d",&c[i]);
	int tim=0,qq=0;
	for(int i=1;i<=q;i++) {
		int u,v,opt;
//		scanf("%d%d%d",&opt,&u,&v);
		opt=read();u=read();v=read();
		if(opt==0) {
			tt[++tim].a=u;tt[tim].b=v;
		} else {
			if(fir[u]>fir[v]) myswap(u,v);
			int lca=getlca(u,v);
//			int lca=getMin(u,v);
//			printf("%d\n",lca);
			if(lca==u) {
				qy[++qq].l=fir[u];qy[qq].r=fir[v];
				qy[qq].t=tim;qy[qq].lca=0;
			} else {
				qy[++qq].l=ed[u];qy[qq].r=fir[v];
				qy[qq].t=tim;qy[qq].lca=lca;
			}
			qy[qq].id=qq;
		}
	}
	sort(qy+1,qy+qq+1,cmp);
	int l=1,r=0,ti=0;
	for(int i=1;i<=qq;i++) {
		while(l<qy[i].l) modify(a[l++]);
		while(l>qy[i].l) modify(a[--l]);
		while(r<qy[i].r) modify(a[++r]);
		while(r>qy[i].r) modify(a[r--]);
		while(ti<qy[i].t) {
			int a=tt[++ti].a,b=tt[ti].b;
			if(tag[a]) {
				sum-=w[cnt[c[a]]]*v[c[a]];
				cnt[c[a]]--;cnt[b]++;
				sum+=w[cnt[b]]*v[b];
			}
			myswap(c[a],tt[ti].b);
		}
		while(ti>qy[i].t) {
			int a=tt[ti].a,b=tt[ti].b;
			if(tag[a]) {
				sum-=w[cnt[c[a]]]*v[c[a]];
				cnt[c[a]]--;cnt[b]++;
				sum+=w[cnt[b]]*v[b];
			}
			myswap(c[a],tt[ti--].b);
		}
		if(qy[i].lca) modify(qy[i].lca);
		ans[qy[i].id]=sum;
		if(qy[i].lca) modify(qy[i].lca);
	}
	for(int i=1;i<=qq;i++)
		printf("%lld\n",ans[i]);
//	system("pause");
}
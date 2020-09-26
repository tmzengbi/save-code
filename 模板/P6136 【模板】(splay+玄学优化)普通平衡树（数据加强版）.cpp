#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<random>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int maxn=1e6+1e5+10;
const int inf=0x7fffffff;
mt19937 rnd(time(NULL));
#define rd(a,b) rnd()%((b)-(a)+1)+(a)
struct Node
{
	int val,siz,n;
	int fa,ch[2];
	Node(){ch[0]=ch[1]=fa=n=siz=0;}
	int cmp(int x)
	{
		if(x==val) return -1;
		return x>val;
	}
}t[maxn];
int Index=0,rt=0;
inline void pushup(int o)
{
	t[o].siz=t[o].n+t[t[o].ch[0]].siz+t[t[o].ch[1]].siz;
}
inline int Get(int o)
{
	return t[t[o].fa].ch[1]==o;
}
void connected(int a,int b,int s)
{
	t[a].fa=b;
	t[b].ch[s]=a;
}
void rotate(int x)
{
	int d=Get(x);
	int fa=t[x].fa,ffa=t[fa].fa,ch=t[x].ch[d^1];
	connected(x,ffa,Get(fa));
	connected(fa,x,d^1);
	connected(ch,fa,d);
	pushup(fa);pushup(x);
}
void splay(int x,int to)
{
	bool ok=(to==rt);
	to=t[to].fa;
	while(true)
	{
		int fa=t[x].fa;
		if(fa!=to)
		{
			int ffa=t[fa].fa;
			if(ffa!=to)
			{
				if(Get(x)==Get(fa)){rotate(fa);rotate(x);}
				else{rotate(x);rotate(x);}
			}
			else rotate(x);
		}
		else break;
	}
	if(ok) rt=x;
}
void Find(int r,int x)
{
	int o=r;
	while(true)
	{
		int d=t[o].cmp(x);
		if(d==-1) break;
		if(!t[o].ch[d]) break;
		o=t[o].ch[d];
	}
	splay(o,r);
}
void insert(int x)
{
	if(!rt)
	{
		rt=++Index;t[rt].n=t[rt].siz=1;
		t[rt].val=x;return;
	}
	int o=rt,d;
	while(true)
	{
		d=t[o].cmp(x);
		if(d==-1){++t[o].n;++t[o].siz;splay(o,rt);return;}
		if(!t[o].ch[d]) break;
		o=t[o].ch[d];
	}
	int fa=o;o=++Index;
	connected(o,fa,d);
	t[o].n=t[o].siz=1;t[o].val=x;
	splay(o,rt);
}
void erase(int x)
{
	Find(rt,x);
//	print(rt);
	if(t[rt].n>1){--t[rt].n;--t[rt].siz;return;}
	if(!t[rt].ch[0])
	{
		t[t[rt].ch[1]].fa=0;
		rt=t[rt].ch[1];
		return;
	}
	Find(t[rt].ch[0],inf);
	int k=t[rt].ch[0];
	t[k].fa=0;
	connected(t[rt].ch[1],k,1);
	rt=k;pushup(rt);
}
int findrank(int x)
{
	Find(rt,x);
	return t[t[rt].ch[0]].siz+1;
}
int findkth(int x)
{
	int o=rt;
//	print(rt);
	while(true)
	{
		if(t[t[o].ch[0]].siz>=x) o=t[o].ch[0];
		else if(t[t[o].ch[0]].siz+t[o].n>=x) break;
		else{x=x-t[o].n-t[t[o].ch[0]].siz;o=t[o].ch[1];}
	}
//	print(rt);
	splay(o,rt);
	return t[rt].val;
}
int findpre(int x)
{
	int now=0,o=rt,ans=-inf;
	while(o)
	{
		int d=t[o].cmp(x);
		if(d==1){now=o;ans=t[o].val;o=t[o].ch[1];}
		else o=t[o].ch[0];
	}
//	assert(now);
	if(now) splay(now,rt);
	return ans;
}
int findnext(int x)
{
	int now=0,o=rt,ans=inf;
	while(o)
	{
		int d=t[o].cmp(x);
		if(d==0){now=o;ans=t[o].val;o=t[o].ch[0];}
		else o=t[o].ch[1];
	}
//	assert(now);
	if(now) splay(now,rt);
	return ans;
}
int n,m;
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
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
//	scanf("%d%d",&n,&m);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();//scanf("%d",&k);
		insert(k);
	}
	int last=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int opt,x;
		if(i%2333==0&&rt) findkth(rd(1,t[rt].siz));
//		scanf("%d%d",&opt,&x);
		opt=read();x=read();
		x^=last;
		if(opt==3||opt==5||opt==6) insert(x);
		if(opt==1) insert(x);
		else if(opt==2) erase(x);
		else if(opt==3) last=findrank(x);//printf("%d\n",findrank(x));
		else if(opt==4) last=findkth(x);//printf("%d\n",findkth(x));
		else if(opt==5) last=findpre(x);//printf("%d\n",findpre(x));
		else last=findnext(x);//printf("%d\n",findnext(x));
//		print(rt);
		if(opt==3||opt==5||opt==6) erase(x);
		if(opt>=3) ans^=last;
	}
	printf("%d\n",ans);
//	cout<<(double)clock()/CLOCKS_PER_SEC;
//	system("pause");
}
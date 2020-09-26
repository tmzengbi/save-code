#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+10;
struct Tree
{
	char le,ri;
	int sumv;
	Tree(char le='X',char ri='X',int sumv=0):le(le),ri(ri),sumv(sumv){}
}tr[maxn<<2];
int n,m;
void pushup(int o)
{
	tr[o].sumv=tr[o<<1].sumv+tr[o<<1|1].sumv;
	if(tr[o<<1].ri=='('&&tr[o<<1|1].le==')') ++tr[o].sumv;
	tr[o].le=tr[o<<1].le!='X'?tr[o<<1].le:tr[o<<1|1].le;
	tr[o].ri=tr[o<<1|1].ri!='X'?tr[o<<1|1].ri:tr[o<<1].ri;
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		if(l==1) tr[o].le=tr[o].ri='(';
		else if(l==n) tr[o].le=tr[o].ri=')';
		else tr[o].le=tr[o].ri='X';
		return;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	pushup(o);
}
void update(int o,int l,int r,int q,char v)
{
	if(l==r)
	{
		tr[o].le=tr[o].ri=v;
		return;
	}
	int mid=l+r>>1;
	if(q<=mid) update(o<<1,l,mid,q,v);
	else update(o<<1|1,mid+1,r,q,v);
	pushup(o);
}
Tree merge(const Tree &l,const Tree &r)
{
	Tree tmp;
	tmp.sumv=l.sumv+r.sumv;
	if(l.ri=='('&&r.le==')') ++tmp.sumv;
	tmp.le=l.le!='X'?l.le:r.le;
	tmp.ri=r.ri!='X'?r.ri:l.ri;
	return tmp;
}
Tree query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tr[o];
	int mid=l+r>>1;
	Tree lef,rit;
	if(ql<=mid) lef=query(o<<1,l,mid,ql,qr);
	if(mid<qr) rit=query(o<<1|1,mid+1,r,ql,qr);
	return merge(lef,rit);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==2)
		{
			int l,r;scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,n,l,r).sumv);
		}
		else
		{
			int u;char s[3];
			scanf("%d%s",&u,s);
			update(1,1,n,u,s[0]);
		}
	}
//	system("pause");
}
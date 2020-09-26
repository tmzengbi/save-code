#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int sumv[21][maxn<<2],minv[21][maxn<<2],maxv[21][maxn<<2],addv[21][maxn<<2],setv[21][maxn<<2];
int N,M,Q;
struct Ans
{
	int Sum,Max,Min;
	Ans operator+(const Ans &a)
	{
		Sum+=a.Sum;
		Max=max(Max,a.Max);
		Min=min(Min,a.Min);
		return *this;
	}
	Ans operator+=(const Ans&a)
	{
		return *this+a;
	}
	Ans(int Sum,int Max,int Min):Sum(Sum),Max(Max),Min(Min){}
};
void pushup(int now,int o)
{
	sumv[now][o]=sumv[now][o<<1]+sumv[now][o<<1|1];
	minv[now][o]=min(minv[now][o<<1],minv[now][o<<1|1]);
	maxv[now][o]=max(maxv[now][o<<1],maxv[now][o<<1|1]);
}

void build(int now,int o,int l,int r)
{
	addv[now][o]=setv[now][o]=0;
	if(l==r)
	{
		sumv[now][o]=minv[now][o]=maxv[now][o]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(now,o<<1,l,mid);
	build(now,o<<1|1,mid+1,r);
	pushup(now,o);
}

void pushdown(int now,int o,int l,int r)
{
	if(setv[now][o])
	{
		int mid=(l+r)>>1;
		addv[now][o<<1]=addv[now][o<<1|1]=0;
		setv[now][o<<1]=setv[now][o<<1|1]=setv[now][o];
		sumv[now][o<<1]=setv[now][o]*(mid-l+1);sumv[now][o<<1|1]=setv[now][o]*(r-mid);
		maxv[now][o<<1]=maxv[now][o<<1|1]=minv[now][o<<1]=minv[now][o<<1|1]=setv[now][o];
		setv[now][o]=0;
	}
	if(addv[now][o])
	{
		int mid=(l+r)>>1;
		addv[now][o<<1]+=addv[now][o];addv[now][o<<1|1]+=addv[now][o];
		sumv[now][o<<1]+=addv[now][o]*(mid-l+1);
		sumv[now][o<<1|1]+=addv[now][o]*(r-mid);
		maxv[now][o<<1]+=addv[now][o];maxv[now][o<<1|1]+=addv[now][o];
		minv[now][o<<1]+=addv[now][o];minv[now][o<<1|1]+=addv[now][o];
		addv[now][o]=0;
	}
}
void updateset(int now,int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		setv[now][o]=v;addv[now][o]=0;
		sumv[now][o]=v*(r-l+1);minv[now][o]=maxv[now][o]=v;
		return;
	}
	pushdown(now,o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) updateset(now,o<<1,l,mid,ql,qr,v);
	if(mid<qr) updateset(now,o<<1|1,mid+1,r,ql,qr,v);
	pushup(now,o);
}
void updateadd(int now,int o,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		addv[now][o]+=v;
		sumv[now][o]+=v*(r-l+1);minv[now][o]+=v;maxv[now][o]+=v;
		return;
	}
	pushdown(now,o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) updateadd(now,o<<1,l,mid,ql,qr,v);
	if(mid<qr) updateadd(now,o<<1|1,mid+1,r,ql,qr,v);
	pushup(now,o);
}
Ans query(int now,int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return Ans(sumv[now][o],maxv[now][o],minv[now][o]);
	Ans ans=Ans(0,0,1e9);
	pushdown(now,o,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid) ans+=query(now,o<<1,l,mid,ql,qr);
	if(mid<qr) ans+=query(now,o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d%d%d",&N,&M,&Q)==3)
	{
		for(int i=1;i<=N;i++) build(i,1,1,M);
		while(Q--)
		{
			int mod,x1,x2,y1,y2,v;
			scanf("%d",&mod);
			switch(mod)
			{
			case 1:
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int i=x1;i<=x2;i++) updateadd(i,1,1,M,y1,y2,v);
				break;
			case 2:
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int i=x1;i<=x2;i++) updateset(i,1,1,M,y1,y2,v);
				break;
			case 3:
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				Ans ans=Ans(0,0,1e9);
				for(int i=x1;i<=x2;i++)
					ans+=query(i,1,1,M,y1,y2);
				printf("%d %d %d\n",ans.Sum,ans.Min,ans.Max);
				break;
			}
		}

	}
}
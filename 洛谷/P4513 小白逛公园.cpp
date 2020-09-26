#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
template<typename T>T max(T a,T b,T c)
{
	return max(max(a,b),c);
}
const int Maxn=500010;
int a[Maxn];
struct Node
{
	int sl,sr,sx,sumv;
	bool used;
	Node():used(false){}
}node[Maxn<<2];
int N,M;
inline int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
void pushup(int o)
{
	node[o].sumv=node[o<<1].sumv+node[o<<1|1].sumv;
	node[o].sl=max(node[o<<1].sl,node[o<<1].sumv+node[o<<1|1].sl);
	node[o].sr=max(node[o<<1|1].sr,node[o<<1|1].sumv+node[o<<1].sr);
	node[o].sx=max(node[o<<1].sx,node[o<<1|1].sx,node[o<<1].sr+node[o<<1|1].sl);
}
void build(int o,int l,int r)
{
	node[o].used=true;
	if(l==r)	
	{
		node[o].sumv=node[o].sl=node[o].sr=node[o].sx=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
} 
void change(int o,int l,int r,int q,int v)
{
	if(l==r)
	{
		node[o].sumv=node[o].sl=node[o].sr=node[o].sx=v;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid)	change(o<<1,l,mid,q,v);
	if(mid<q)	change(o<<1|1,mid+1,r,q,v);
	pushup(o);
}
Node query(int o,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
		return node[o];
	int mid=(l+r)>>1;
	Node a1,a2;
	if(ql<=mid)	a1=query(o<<1,l,mid,ql,qr);
	if(mid<qr)	a2=query(o<<1|1,mid+1,r,ql,qr);
	if(!a1.used)	return a2;
	if(!a2.used)	return a1;
	Node a3;
	a3.sumv=a1.sumv+a2.sumv;
	a3.sl=max(a1.sl,a1.sumv+a2.sl);
	a3.sr=max(a2.sr,a2.sumv+a1.sr);
	a3.sx=max(a1.sx,a2.sx,a1.sr+a2.sl);
	a3.used=true;
	return a3;
	
}
int main()
{
	N=read(),M=read();
	for(int i=1;i<=N;i++)
		a[i]=read();
	build(1,1,N);
	for(int i=1;i<=M;i++)
	{
		int t=read(),x=read(),y=read();	
		if(t==1)
		{
			if(x>y)	swap(x,y);
			Node ans=query(1,1,N,x,y);
			printf("%d\n",ans.sx);
		}
		if(t==2)
			change(1,1,N,x,y);
		
/*		cout<<"sumv:\r";
		for(int j=1;j<=20;j++)
			cout<<node[j].sumv<<" ";
		cout<<endl;
		cout<<"sl:\r";
		for(int j=1;j<=20;j++)
			cout<<node[j].sl<<" ";
		cout<<endl;
		cout<<"sr:\r";
		for(int j=1;j<=20;j++)
			cout<<node[j].sr<<" ";
		cout<<endl;
		cout<<"sx:\r";
		for(int j=1;j<=20;j++)
			cout<<node[j].sx<<" ";
		cout<<endl;	
	*/
	}
}

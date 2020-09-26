#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Log[50010],N,Q;
struct St
{
	int Max,Min;
}st[50010][20];
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
void init()
{
	Log[0]=Log[1]=0;
	for(int i=2;i<=N;i++)
		Log[i]=Log[i>>1]+1;
}
void makest(int n)
{
	
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=N;i++)
		{
			if( (i+(1<<j)-1)<=N )
			{
				st[i][j].Max=max(st[i][j-1].Max,st[i+(1<<j-1)][j-1].Max);
				st[i][j].Min=min(st[i][j-1].Min,st[i+(1<<j-1)][j-1].Min);
			}
		}
	}
}
void query(int l,int r)
{
	int blk=Log[r-l+1];
	int Max=max(st[l][blk].Max,st[r-(1<<blk)+1][blk].Max);
	int Min=min(st[l][blk].Min,st[r-(1<<blk)+1][blk].Min);
	printf("%d\n",Max-Min);
}
int main()
{
	N=read(),Q=read();
	init();
	for(int i=1;i<=N;i++)
		st[i][0].Max=st[i][0].Min=read();
	makest(Log[N]);
	while(Q--)
	{
		int L=read(),R=read();
		query(L,R);
	}
}


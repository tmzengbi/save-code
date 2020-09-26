#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int st[100010][20],Pow[21],a[100010],Log[100010];
int n,m;
int read()
{
	int shu=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
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
void stinit()
{
	int i=1,k=1;
	for(i=1;i<=n;i++)
		st[i][0]=a[i];
	for(k=1;k<=Log[n];k++)
	{
		for(i=1;i+Pow[k]-1<=n;i++)
			st[i][k]=max(st[i][k-1],st[i+Pow[k-1]][k-1]);
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=3;j++)
			cout<<st[i][j]<<" ";
		cout<<endl;
	}*/ 
}
int query(int l,int r)
{
	int k=Log[r-l+1];
	return max(st[l][k],st[r-Pow[k]+1][k]);
}
int main()
{
	Pow[0]=1;	
	n=read();m=read();
	Log[0]=-1; 
	for(int i=1;i<=n;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=Log[n];i++)
		Pow[i]=Pow[i-1]<<1;
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l,r;
	stinit();
	while(m--)
	{
		l=read();r=read();
		printf("%d\n",query(l,r));
//		cout<<query(l,r)<<endl;
	}
}

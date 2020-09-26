#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Log[100010],m,n,st[100010][20],power[20],a[100010];
int query(int l,int r)
{
	int d=r-l+1;int k=Log[d];
	return min(st[l][k],st[r-power[k]+1][k]);
}
int main()
{	
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	Log[0]=Log[1]=0;
	for(int i=2;i<=m;i++)
		Log[i]=Log[i/2]+1;
	for(int i=0;i<=Log[m];i++)
		power[i]=(1<<i);
//	for(int i=1;i<=m;i++)
//		cout<<Log[i]<<" ";
	for(int i=1;i<=m;i++)
		st[i][0]=a[i];
	for(int i=1;i<=Log[m];i++)
		for(int j=1;j+power[i]<=m;j++)
			st[j][i]=min(st[j][i-1],st[j+power[i-1]][i-1]);
	while(n--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d ",query(l,r));
	}
}
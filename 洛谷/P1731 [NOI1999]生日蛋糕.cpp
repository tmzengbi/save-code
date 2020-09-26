#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int N,M,H[20],R[20],minn=2e9;
bool flag=false;
bool maxv(int x,int h,int r,int v)//之后最大的加起来 都不够 正在确认x层的i(x) j(r)
{
	int sum=v;
	for(int i=1;i<=M-x+1;i++)
	{
		sum+=h*r*r;
		h--;r--;
	}
	if(sum<N)	return false;
	else return true;
}
bool minv(int x,int h,int r,int v)
{
	int sum=v;sum+=h*r*r;
	for(int i=1;i<M-x+1;i++)
		sum+=i*i*i;
	if(sum>N)	return false;
	else return true;
}
void dfs(int x,int h,int r,int v,int s)
{
	if(x>1)
		if((s+R[1]*R[1])>minn)	return;
	if(x==M+1&&v==N)
	{
		minn=min(minn,s+R[1]*R[1]);
		flag=true;
	}
	if(x>M)	return;
	if(v>N)	return;
	for(int i=M-x+1;i<h;i++)
		for(int j=M-x+1;j<r;j++)
		{
			if(!maxv(x,i,j,v))	continue;
			if(!minv(x,i,j,v))	break;
			H[x]=i;R[x]=j;
			dfs(x+1,i,j,v+i*j*j,s+i*j*2);
		}
}
int main()
{

	scanf("%d%d",&N,&M);
	H[0]=N;R[0]=sqrt(N);
	dfs(1,H[0],R[0],0,0);
	if(!flag)	minn=0;
	printf("%d\n",minn );
//	system("pause");
}
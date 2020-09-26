#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[27],n,rank[27],cnt=0;
char st[4][27];
bool vis[27],getnum[27];//vis表示哪些已经赋值了 getnum表示那些数字用过了
inline int getindex(char ch)
{
	int c=(int)ch;
	return c-'A'+1;
}
bool win()
{
	for(int i=n,j=0;i>=1;i--)
	{
		int a[4],b[4];
		for(int k=1;k<=3;k++)
		{
			a[k]=getindex(st[k][i]);
			b[k]=num[a[k]];
		}
		if(j){b[1]++;j=0;}
		if((b[1]+b[2])>=n){b[1]-=n;j=1;}
		if((b[1]+b[2])!=b[3]) return false;
		if(i==1&&j==1) return false; 
	}
	return true;
}
bool judge()
{
	for(int i=n;i>=1;i--)
	{
		int a[4],b[4];bool flag=false;
		for(int j=1;j<=3;j++)
		{
			a[j]=getindex(st[j][i]);
			if(!vis[a[j]]) {flag=true;break;}
			b[j]=num[a[j]];
		}

		if(flag) continue;
		if((b[1]+b[2])%n!=b[3]&&(b[1]+b[2]+1)%n!=b[3]) return false;
	}
	return true;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		if(win())
		{
			for(int i=1;i<=n;i++)
				cout<<num[i]<<" ";
//			system("pause");
			exit(0);
		}
	}
	if(dep>3&&!judge()) return;
	for(int i=n-1;i>=0;i--)
	{
		if(!getnum[i])
		{
			vis[rank[dep]]=true;
			num[rank[dep]]=i;
			getnum[i]=true;
			dfs(dep+1);
			vis[rank[dep]]=false;
			getnum[i]=false;
		}
	}
}
int main()
{
	scanf("%d",&n);getchar();
	for(int i=1;i<=3;i++)
		scanf("%s",st[i]+1);
	memset(getnum,false,sizeof getnum);
	memset(vis,false,sizeof vis);
	for(int i=n;i>=1;i--)
	{
		int a[4];
		for(int j=1;j<=3;j++)
		{
			a[j]=getindex(st[j][i]);
			if(!vis[a[j]]){rank[++cnt]=a[j];vis[a[j]]=true;}
		}
	}

	memset(vis,false,sizeof vis);
	dfs(1);



}
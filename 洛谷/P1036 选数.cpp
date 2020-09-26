#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n,k,a[25],ans=0;
bool judge(long long sum)
{
	for(ll i=2;i<=sqrt(sum);i++)
		if(sum%i==0)	return false;
	return true;
}
void dfs(int x,long long sum,int z)
{

	if(z==k)	
	{
		if(judge(sum)) ans++;
		return;
	}
	if(x<=n)
	{
		dfs(x+1,sum+a[x],z+1);
		dfs(x+1,sum,z);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,0);
	cout<<ans<<endl;
//	system("pause");
}
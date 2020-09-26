#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,ta,tb,k,a[200005],b[200005],ans=-1;
inline ll read();
int main()
{
	n=read();m=read();ta=read();tb=read();k=read();
	for(ll i=1;i<=n;i++)
	{
		a[i]=read();
		a[i]+=ta;
	}
	for(ll i=1;i<=m;i++)
		b[i]=read();
	ll Index=1; 
	if(a[1+k]>b[m])
	{
		cout<<ans;
		return 0;
	}
	if(m<=k||n<=k)
	{
		cout<<ans;
		return 0;
	}
	while(k>=0)
	{
		ll t=lower_bound(b+1,b+m,a[Index])-b;
		if(t+k>m) break;
		else	
			ans=max(ans,b[t+k]+tb);
		k--;
		Index++;
	}
	cout<<ans;
}
inline ll read()
{
	ll f=1,shu=0;char ch=getchar();
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

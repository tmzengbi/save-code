#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e6+10;
int n;
const int P=1e9+7;
const int key=2333333;
int val[maxn],a[maxn],ans[maxn];
int read()
{
	int shu=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu;
}
int Next[maxn],pre[maxn];
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	val[0]=1;
	for(int i=1;i<maxn;i++)
		val[i]=(ll)val[i-1]*key%P;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
		Next[i]=i+1,pre[i]=i-1;
	int now=n/2+(n%2==1);
	for(int i=n;i;i--)
	{
		ans[i]=now;
		int pe=pre[a[i]],ne=Next[a[i]];
		Next[pe]=ne;pre[ne]=pe;
		if(i&1)
		{
			if(a[i]>=now)
				now=pre[now];
		}
		else
		{
			if(a[i]<=now)
				now=Next[now];
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%d\n",ans[i]);
	ll ss=0;
	for(int i=1;i<=n;i++)
		ss=(ss+(ll)val[i]*ans[i])%P;
	printf("%lld\n",ss);
//	system("pause");
}
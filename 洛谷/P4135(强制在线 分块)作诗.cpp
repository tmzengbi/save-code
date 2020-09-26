#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int Block=355;
int n,c,m,a[maxn];
int belong[maxn],bk,le[Block],ri[Block],f[Block][maxn],k[Block][Block];
int cnt[maxn],s[maxn],Index=0;
int query(int l,int r)
{
	for(int i=l;i<=min(ri[belong[l]],r);i++)
	{
		if(!cnt[a[i]]) s[Index++]=a[i];
		cnt[a[i]]++;
	}
	if(belong[l]!=belong[r])
	{
		for(int i=le[belong[r]];i<=r;i++)
		{
			if(!cnt[a[i]]) s[Index++]=a[i];
			cnt[a[i]]++;
		}
	}
	int sum=k[belong[l]+1][belong[r]-1];
	for(int i=0;i<Index;i++)
	{
		int num=f[belong[r]-1][s[i]]-f[belong[l]][s[i]];
		if(num<0) num=0;
		if((num+cnt[s[i]])%2==0)
		{
			if(num&1) sum++;
			else if(!num) sum++;
		}
		else if(num&&num%2==0) sum--;
		cnt[s[i]]=0;
	}
	Index=0;
	return sum;
}
int main()
{
//	freopen("a.in","r",stdin);
	scanf("%d%d%d",&n,&c,&m);
	bk=(int)sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bk+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=ri[i-1]+1;
		ri[i]=bk*i;
	}
	for(int i=1;i<=n;i++) f[belong[i]][a[i]]++;
	for(int i=1;i<=belong[n];i++)
		for(int j=1;j<=c;j++)
			f[i][j]+=f[i-1][j];
	for(int i=1;i<=belong[n];i++)
	{
		int sum=0;
		for(int j=le[i];j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]%2==0) sum++;
			else if(cnt[a[j]]>2)sum--;
			k[i][belong[j]]=sum;
		}
		memset(cnt,0,sizeof cnt);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		l=(ans+l)%n+1;r=(ans+r)%n+1;
		if(l>r) swap(l,r);
		printf("%d\n",ans=query(l,r));
	}
//	system("pause");
}
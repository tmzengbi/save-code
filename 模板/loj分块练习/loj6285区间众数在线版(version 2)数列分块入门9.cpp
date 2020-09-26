#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=100010;
const int Block=510;
int a[maxn],belong[maxn],le[Block],ri[Block],f[Block][Block],pre[Block][maxn];
int n,bk,val[maxn],cnt[maxn];
int s[maxn],Index=0;
map<int,int>mp;
int solve(int l,int r)
{
	int ans=f[belong[l]+1][belong[r]-1],mx=pre[belong[r]-1][ans]-pre[belong[l]][ans];
	for(int i=l;i<=min(r,ri[belong[l]]);i++)
	{
		int k=pre[belong[r]-1][a[i]]-pre[belong[l]][a[i]];
		if(k<0) k=0;
		if(!cnt[a[i]]) s[Index++]=a[i];
		cnt[a[i]]++;
		k+=cnt[a[i]];
		if(mx<k||mx==k&&val[a[i]]<val[ans])
			ans=a[i],mx=k;
	}
	if(belong[l]!=belong[r])
		for(int i=le[belong[r]];i<=r;i++)
		{
			int k=pre[belong[r]-1][a[i]]-pre[belong[l]][a[i]];
			if(k<0) k=0;
			if(!cnt[a[i]]) s[Index++]=a[i];
			cnt[a[i]]++;
			k+=cnt[a[i]];
			if(mx<k||mx==k&&val[a[i]]<val[ans])
				ans=a[i],mx=k;
		}
	while(Index) cnt[s[--Index]]=0;
	return ans;
}
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("a11.out","w",stdout);
//	scanf("%d",&n);
	n=read();
	bk=(int)sqrt(n);
	int id=0;
	for(int i=1;i<=n;i++) a[i]=read();//scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/bk+1;
		if(!mp.count(a[i]))
		{
			mp[a[i]]=++id;
			val[id]=a[i];
		}
		a[i]=mp[a[i]];
		pre[belong[i]][a[i]]++;
	}
	for(int i=1;i<=belong[n];i++)
		for(int j=1;j<=id;j++)
			pre[i][j]+=pre[i-1][j];
	for(int i=1;i<=belong[n];i++)
	{
		le[i]=(i-1)*bk+1;
		ri[i]=i*bk;
		memset(cnt,0,sizeof cnt);
		int sum=0,ans=0;
		for(int j=le[i];j<=n;j++)
		{
			cnt[a[j]]++;
			if(sum<cnt[a[j]]||sum==cnt[a[j]]&&val[a[j]]<val[ans])
			{
				sum=cnt[a[j]];
				ans=a[j];
			}
			f[i][belong[j]]=ans;
		}
	}
	memset(cnt,0,sizeof cnt);
	for(int cas=1;cas<=n;cas++)
	{
		int l,r;//scanf("%d%d",&l,&r);
		l=read();r=read();
		if(r<l) swap(l,r);
		printf("%d\n",val[solve(l,r)]);
	}
//	cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
//	system("pause");
}
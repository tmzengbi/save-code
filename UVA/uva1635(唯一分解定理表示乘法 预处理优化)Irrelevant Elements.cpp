//用唯一分解定理表示乘法
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
const int maxn=1e5;
int ans[maxn+10];
bool notprime[maxn+10];
vector<int>p;
vector<pii>ck;
vector<int>fac[maxn+10];
int n,m;
void presol()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!notprime[i])
		{
			p.push_back(i);
			fac[i].push_back(i);
			for(ll j=(ll)i+i;j<=maxn;j+=i)
				notprime[j]=1,fac[j].push_back(i);
		}
	}
}
int cnt[maxn+10];
void calc(int x,int v)
{
	int tmp=x;
	for(int i:fac[tmp])
	{
		while(x%i==0)
		{
			cnt[i]+=v;
			x/=i;
		}
	}
}
bool check()
{
	if(ck.back().first>maxn) return false;
	for(auto i:ck)
		if(cnt[i.first]<i.second) return false;
	return true;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a11.out","w",stdout);
	presol();
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i:p) cnt[i]=0;
		ck.clear();
		for(int i=0;i<p.size();i++)
		{
			if(m%p[i]==0)
			{
				ck.push_back(make_pair(p[i],0));
				while(m%p[i]==0) ck.back().second++,m/=p[i];
			}
			if(m==1) break;
		}
		vector<int>ans;
		if(m==1)
		{
			--n;
			for(int i=1;i<=n;i++)
			{
				calc(n-i+1,1);calc(i,-1);
				if(check()) ans.push_back(i+1);
			}
		}
		int sum=(int)ans.size();
		printf("%d\n",sum);
		if(sum)
		{
			printf("%d",ans[0]);
			for(int i=1;i<sum;i++) printf(" %d",ans[i]);
		}
		puts("");
//		cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
	}
//	system("pause");
}
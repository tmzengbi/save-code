#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll idt=1,tmp[1001],ans[1001];
map<ll,ll> Map;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll start(ll a,ll b)
{
	return b/a+1;
}
bool better(ll dep)
{
	for(ll i=dep;i>=1;i--)
	{
		if(tmp[i]!=ans[i])
			return ans[i]==0||tmp[i]<ans[i];
	}
	return false;
}
bool dfs(ll dep,ll a,ll b)
{
	bool ok=false;
	if(dep==idt)
	{
		if(b%a) return false;
		if(Map.find(b/a)!=Map.end()) return false;
		tmp[dep]=b/a;
		if(better(dep)) memcpy(ans+1,tmp+1,sizeof(ll)*(dep+1));
		return true;
	}
	ll from=max(tmp[dep-1],start(a,b));
	for(ll i=from;;i++)
	{

//		cout<<dep<<" "<<i<<endl;
//		system("pause");
		if(Map.find(i)!=Map.end()) continue;
		if(a*i>=b*(idt-dep+1)) break;
		Map[i]=1;
		tmp[dep]=i;
		ll x=a*i-b,y=b*i,r=gcd(x,y);
		if(dfs(dep+1,x/r,y/r)) ok=true;
		Map.erase(i);
	}
	return ok;
}
int main()
{
	ll T;
	scanf("%lld",&T);
	for(int Cas=1;Cas<=T;Cas++)
	{
		Map.clear();
		idt=1;
		memset(ans,0,sizeof ans);
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll t,ban;
		scanf("%lld",&t);
		while(t--)
		{
			scanf("%lld",&ban);
			Map[ban]=1;
		}
		while(true)
		{
			memset(tmp,0,sizeof tmp);
			if(dfs(1,x,y)) break;
			idt++;
//			cout<<idt<<" ";
		}
		
		printf("Case %d: %lld/%lld=",Cas,x,y);
		printf("1/%lld",ans[1]);
		for(ll i=2;i<=idt;i++)
			printf("+1/%lld",ans[i]);
		printf("\n");

	}

//	system("pause");

}
/*
1
596 829 0


*/
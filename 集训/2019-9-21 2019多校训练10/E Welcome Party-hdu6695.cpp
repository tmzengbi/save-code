#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,n,x,y,ans;
struct Ability
{
	ll sing,talk;
}m[100010];
multiset<ll> s1;
multiset<ll> s2;
multiset<ll>::iterator it;
bool cmp(Ability a,Ability b)
{
	return a.sing<b.sing;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=2e18L;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld%lld",&m[i].sing,&m[i].talk);
		sort(m+1,m+n+1,cmp);
		s1.clear();s2.clear();
		for(ll i=1;i<=n;i++)
			s1.insert(m[i].talk);
		for(ll i=1;i<=n;i++)
		{
			ll maxs;
			it=s1.find(m[i].talk);
			s1.erase(it);
			if(i>1) s2.insert(m[i-1].talk);
			if(i<n) maxs=*(--s1.end());
			else if(i==n) maxs=-2e18L;
			if(s2.empty()) ans=min(ans,abs(m[i].sing-maxs));
			else
			{
				ll sums2;
				it=s2.lower_bound(m[i].sing);
				if(it==s2.end()) sums2=*(--it);
				else if(it==s2.begin()) sums2=*it;
				else 
				{
					ll tmp;
					sums2=*it;tmp=*(--it);
					if(abs(sums2-m[i].sing)>abs(tmp-m[i].sing)) swap(sums2,tmp);
				}
				ll dis1,dis2;
				dis1=abs(maxs-m[i].sing);dis2=abs(sums2-m[i].sing);
//				cout<<dis1<<" "<<dis2<<endl;
				if(dis2<dis1&&sums2>maxs)
					swap(maxs,sums2);
				ans=min(ans,abs(maxs-m[i].sing));
			}
		}
		printf("%lld\n",ans);
	}
//	system("pause");
}

/*
2
5
27 46
89 13
55 8
71 86
22 35
3
3 5
4 7
6 2



2
3
19 72
84 27
38 21
4
17 38
12 16
53 36
25 32

*/
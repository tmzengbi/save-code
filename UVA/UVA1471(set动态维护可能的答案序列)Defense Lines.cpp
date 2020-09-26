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
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int t,n,a[maxn],l[maxn],r[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		set<pii>s;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=a[n+1]=0;
		int Index=1;
		while(Index<=n)
		{
			int start=Index,cnt=1;
			while(Index<=n&&a[Index]<a[Index+1]) Index++,cnt++;
			for(int i=Index,j=1;i>=start;i--,j++)
			{
				l[i]=j;r[i]=cnt--;
			}
			Index++;
		}
		int ans=l[1];
		s.insert(make_pair(a[1],r[1]));
		for(int i=2;i<=n;i++)
		{
			auto v=s.lower_bound(make_pair(a[i],0));
			if(v!=s.begin()) ans=max(ans,(--v)->second+l[i]);
			else ans=max(ans,l[i]);
			pii Add=make_pair(a[i],r[i]);
			v=s.lower_bound(Add);
			if(v==s.begin()) s.insert(Add);
			else if((--v)->second>=Add.second) continue;
			else s.insert(Add);
			while((v=s.upper_bound(Add))!=s.end())
			{
				if(Add.second>=v->second) s.erase(v);
				else break;
			}
		}
		printf("%d\n",ans);
	}
//	system("pause");
}
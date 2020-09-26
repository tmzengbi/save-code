#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<random>
#include<ctime>
using namespace std;
mt19937 rnd(time(NULL));
#define rd(a,b) rnd()%(b-a+1)+a
const int P=1e9+7;
const int maxn=1e6+10;
int t,n,a[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=1;
		set<int>s;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int l=1;
		s.insert(a[1]);
		for(int i=2;i<=n;i++)
		{
			while(s.count(a[i]))
			{
				s.erase(a[l]);
				l++;
			}
			s.insert(a[i]);
			ans=max(ans,i-l+1);
		}
		printf("%d\n",ans);
	}
//	system("pause");
}
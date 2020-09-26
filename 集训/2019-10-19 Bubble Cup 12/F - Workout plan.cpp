#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll ans=0;
const int maxn=100010;
priority_queue<int,vector<int>,greater<int> > q;
int n,k,x[maxn],A,c[maxn];
bool work()
{
	for(int i=1;i<=n;i++)
	{
		q.push(c[i]);
		if(k<x[i])
		{
			int num=(x[i]-k)/A;
			if((x[i]-k)%A) num++;
			while(num--)
			{
				if(q.empty()) return false;
				int tmp=q.top();q.pop();
				ans+=tmp;k+=A;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	scanf("%d",&A);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(work()) printf("%lld\n",ans);
	else printf("-1\n");
 
//	system("pause");
}
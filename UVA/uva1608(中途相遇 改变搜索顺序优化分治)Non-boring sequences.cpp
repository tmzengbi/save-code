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
int n,a[maxn],t,pre[maxn],Next[maxn];
map<int,int>M;
bool solve(int l,int r)
{
	if(l>=r) return true;
	int mk=0;
	int i=l,j=r;
	while(i<=j)
	{
		if((!pre[i]||pre[i]<l)&&(!Next[i]||Next[i]>r)){mk=i;break;}
		i++;
		if((!pre[j]||pre[j]<l)&&(!Next[j]||Next[j]>r)){mk=j;break;}
		j--;
	}
		
//	for(int i=l;i<=r;i++)
//		if((!pre[i]||pre[i]<l)&&(!Next[i]||Next[i]>r)){mk=i;break;}
	bool ok=1;
	if(!mk) return false;
	if(l<=mk-1) ok=ok&&solve(l,mk-1);
	if(mk+1<=r) ok=ok&&solve(mk+1,r);
	return ok;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		M.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			if(M.count(a[i]))
			{
				Next[M[a[i]]]=i;
				Next[i]=0;
				pre[i]=M[a[i]];
				M[a[i]]=i;
			}
			else 
			{
				M[a[i]]=i;
				Next[i]=pre[i]=0;
			}
		}
		if(solve(1,n)) printf("non-boring\n");
		else printf("boring\n");
	}
//	system("pause");
}
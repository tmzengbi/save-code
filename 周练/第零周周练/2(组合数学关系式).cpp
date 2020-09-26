#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main()
{
	const int P=998244353;
	ll n,ans[100010];
	ans[1]=0;ans[2]=1;
	scanf("%lld",&n);
	for(int i=3;i<=n;i++)
		ans[i]=(i-1)*(ans[i-1]+ans[i-2])%P;
	printf("%lld\n",ans[n]);
//	system("pause");
}
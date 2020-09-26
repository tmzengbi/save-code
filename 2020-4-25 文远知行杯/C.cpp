#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a,b,c;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	int ans=a;
	for(int i=1;i<c;i++,a+=b)
	{
		ans=gcd(ans,a);
	}
	printf("%d\n",ans);
//	system("pause");
}
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
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int P=10001;
const int maxn=110;
int t,s[maxn];
int exgcd(int a,int b,int &x,int &y)
{
	if(!b){x=1,y=0;return a;}
	int r=exgcd(b,a%b,x,y);
	int tmp=x;
	x=y;y=tmp-a/b*y;
	return r;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a11.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d",&s[i]);
	int a,b;
	for(a=0;a<P;a++)
	{
		int x,y,r=exgcd(a+1,P,x,y);
		if(r!=1) continue;
		x=(x+P)%P;
		b=(ll)x*((s[2]-(ll)a*a*s[1])%P+P)%P;
		bool ok=true;
		for(int i=3;i<=t;i++)
			if(s[i]!=(((ll)s[i-1]*a*a+a*b+b))%P){ok=false;break;}
		if(ok) break;
	}
	for(int i=1;i<=t;i++)
		printf("%d\n",((ll)s[i]*a+b)%P);
//	system("pause");
}
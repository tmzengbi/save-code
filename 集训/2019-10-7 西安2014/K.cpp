#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll a,b,ans,T;
int main()
{	
	scanf("%lld",&T);
	for(ll Cas=1;Cas<=T;Cas++)
	{
		scanf("%lld%lld",&a,&b);
		ans=1;bool spe=false;
		if(a==0&&b==0) {printf("Case #%lld: 1\n",Cas );spe=true;}
		else if(a==0||b==0) {printf("Case #%lld: 2\n",Cas );spe=true;}
		if(!spe)
		{ 
			while(b)
			{	
				ans+=a/b;
				ll tmp=a;
				a=b;b=tmp%b;
				
			}
			printf("Case #%lld: %lld\n",Cas,ans);
		}
	}
}
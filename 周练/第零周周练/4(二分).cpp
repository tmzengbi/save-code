#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
int main()
{	
	int jw=0,ans=0;
	scanf("%d",&n);
	while(n)
	{
		if(n>1&&n&1) jw=1;
		n>>=1;
		ans++;
	}
	if(!jw) ans--;
	printf("%d\n",ans);

//	system("pause");
}
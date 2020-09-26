
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int d=b-a,ans;
	if((n-b)%d) ans=((n-b)/d+1)*2+1;
	else ans=(n-b)/d*2+1;
	printf("%d\n",ans);
//	system("pause");
}
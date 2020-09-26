#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T,a,n;
	scanf("%d",&T);
	for(int Cas=1;Cas<=T;Cas++)
	{
		scanf("%d",&n);bool win=true;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a%3) win=false;
		}
		if(win) printf("Case #%d: Yes\n",Cas);
		else printf("Case #%d: No\n",Cas);

	}
//	system("pause");
}
/*
2 3 1 2 3 2 3000 996
*/
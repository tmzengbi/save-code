#include<iostream>
#include<cstdio>
using namespace std;
int ans,T,tmp_add;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=4;tmp_add=1;
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x>a) swap(x,a);
		if(y>b) swap(y,b);
		if(x<0&&a>0) tmp_add*=2;
		if(y<0&&b>0) tmp_add*=2;
		ans+=tmp_add;
		printf("%d\n",ans);
	}
//	while(1);
}
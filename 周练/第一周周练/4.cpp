#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int sing=0,nor=0,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double x,y;scanf("%lf%lf",&x,&y);
		if((x+y)==(int)(x+y)) sing++;
		else nor++;
	}
	if(sing>nor) printf("Lose\n");
	else if(sing<nor) printf("Win\n");
	else printf("O_O\n");
}
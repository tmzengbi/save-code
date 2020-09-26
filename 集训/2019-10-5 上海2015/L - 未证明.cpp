#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int T,x,y;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&T);
	for(int C=1;C<=T;C++)
	{
		int ans=1;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		int r=gcd(x,y);
		while(true)
		{
			if(y%(r+x) ) break;
			int div=x/r+1;
			y=y/div;
			ans++;
			if(x>y) swap(x,y);
//			cout<<x<<" "<<y<<endl;
		}
		printf("Case #%d: %d\n",C,ans);
	}

	system("pause");
}

/*
3 6 10 6 8 2 8
*/
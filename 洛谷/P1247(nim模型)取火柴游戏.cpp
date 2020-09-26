#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=500010;
int n,a[maxn];
int main()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans^=a[i];
	}
	if(!ans){puts("lose");return 0;}
	int Max=0;
	for(int i=30;i>=0;i--)
		if((1<<i)&ans){Max=(1<<i);break;}
	int to,id;
	for(int i=1;i<=n;i++) if(a[i]&Max)
	{
		id=i;
		to=ans^a[i];
		printf("%d %d\n",a[i]-to,i);
		break;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==id) printf("%d ",to);
		else printf("%d ",a[i]);
	}
}
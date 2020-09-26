#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct Node
{
	int v,rank;	
}a[10010];
bool cmp(Node n1,Node n2)
{
	return n1.v<n2.v;
}

ll sum=0,s[10010];
int main()
{
	memset(s,0,sizeof s);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){a[i].rank=i;scanf("%d",&a[i].v);}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i].v;
		sum+=s[i];
	}
	double ans=sum/double(n);
	printf("%d",a[1].rank);
	for(int i=2;i<=n;i++)
		printf(" %d",a[i].rank);
	printf("\n");
	printf("%.2lf\n",ans);
}
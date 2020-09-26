#include<iostream>
#include<cstdio>
using namespace std;
int n,ans[200010],a[200010],k=-100001;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=max(0,ans[i-1])+ans[i];
		k=max(ans[i],k);
	}
	cout<<k<<endl;
//	system("pause");
}
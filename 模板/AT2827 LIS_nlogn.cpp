#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=1e8;
int len=1,n,a[100010],f[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=inf;
	}
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>f[len])	f[++len]=a[i];
		else
		{
			int k=lower_bound(f+1,f+len+1,a[i])-f;
			f[k]=a[i];
		}
	}
//	for(int i=1;i<=len;i++)
//	cout<<f[i]<<" ";
	//system("pause");
	cout<<len<<endl;
}
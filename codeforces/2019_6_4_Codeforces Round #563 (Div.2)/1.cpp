#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[4010],sum1=0;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
		sum1+=a[i];
	}
	sort(a+1,a+2*n+1);
	int sum2=0;
	for(int i=1;i<=n;i++)
	{
		sum2+=a[i];
	}
	if(sum2*2==sum1)	cout<<-1;
	else
		for(int i=1;i<=2*n;i++)
			cout<<a[i]<<" ";
}

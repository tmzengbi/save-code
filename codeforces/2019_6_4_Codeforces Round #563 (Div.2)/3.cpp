#include<iostream>
#include<cstring>
using namespace std;
int cnt=0;
int main()
{
	int n,a[100010];
	memset(a,0,sizeof a);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!a[i])
		{
			cnt++;
			for(int j=i;j<=n;j=j+i)
				a[j]=cnt;
		}
	}
	for(int i=2;i<=n;i++)
		cout<<a[i]<<" ";
} 

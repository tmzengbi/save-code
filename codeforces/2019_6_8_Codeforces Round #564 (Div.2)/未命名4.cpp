#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans;
	if((n-1)%2==0)	ans=(n-1)/2+1;
	if((n-1)%2==1)	ans=n/2+1;
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		printf("1 %d\n",i);
//		cout<<1<<" "<<i<<endl;
	n=n-ans;
	for(int i=2;i<=n+1;i++)
//		cout<<ans<<" "<<i<<endl;
		printf("%d %d\n",i,ans);
}

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> ys;
ll fb[55];
int main()
{
	fb[1]=fb[2]=1;
	int n;ll mod=(1<<31);
	cin>>n;
	for(int i=3;i<=n;i++)
		fb[i]=(fb[i-1]+fb[i-2])%mod;
	int ans=fb[n];
	for(int i=2;i*i<=ans;i++)
		while(ans%i==0){ys.push_back(i);ans/=i;}
	if(ans>1)	ys.push_back(ans);
	printf("%lld=%d",fb[n],ys[0]);
	for(int i=1;i<ys.size();i++)
		printf("*%d",ys[i]);
	printf("\n");
//	system("pause");
}
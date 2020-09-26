#include<iostream>
#include<cstring>
using namespace std;
int h,k,ans[100010],s;
int main()
{
	cin>>h>>k;
	memset(ans,0,sizeof ans);
	ans[0]=k+1;
	for(int i=1;i<=h;i++)
	{
		for(int j=0;j<i;j++)
			ans[i]+=ans[j];
	}
	int k=0;
	for(int i=0;i<=h;i++)
		k+=ans[i];
	cout<<k<<endl;
//	system("pause");
}
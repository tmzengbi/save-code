#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool vis[10000010];
vector<int> ans;
int main()
{
	int n;
	memset(vis,false,sizeof vis);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])	ans.push_back(i);
		for(int j=i*i;j<=n;j+=i)
			vis[j]=true;
	}
	for(unsigned i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
}

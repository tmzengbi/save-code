#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int vis[1000010];
vector<int> ans;
int main()
{
	memset(vis,false,sizeof vis);
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]){vis[i]=i;ans.push_back(i);}
		for(unsigned j=0;j<ans.size();j++)
		{
			if(vis[i]<ans[j]||ans[j]>n/i) break;
			vis[ans[j]*i]=ans[j];
		}
	}
	for(unsigned i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cnt=0;
		vector<int>ans;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				n/=i;
				cnt++;
				ans.push_back(i);
			}
			if(cnt==2) break;
		}
		if(cnt<2||n==ans[1]) printf("NO\n");
		else
		{
			puts("YES");
			for(int i=0;i<ans.size();i++)
				printf("%d ",ans[i]);
			printf("%d\n",n);
		}
	}
//	system("pause");
}
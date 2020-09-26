#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
priority_queue< int,vector<int>,greater<int> > q;
int ans=0;
int main()
{
	int n,g;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&g);
		q.push(g);
	}
	while(!q.empty())
	{
		int sum1=q.top();
		q.pop();
		int sum2=q.top();
		q.pop();
		ans+=sum1+sum2;
		if(q.empty())	break;
		q.push(sum1+sum2);
	}
	printf("%d",ans);
	system("pause");
}
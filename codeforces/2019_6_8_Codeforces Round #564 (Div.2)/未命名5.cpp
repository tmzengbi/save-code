#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n;
int a[200010],b[200010],d[200010],ans=0;
int main()
{
	bool can_find1=false;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)	can_find1=true;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
/*	if(n==1)
	{
		if(a[1]==0)
		{
			cout<<0;
			return 0;
		}
		if(b[1]==0)
		{
			cout<<1;
			return 0;
		}
	}
*/
	if(can_find1)
	{
/*		while(true)
		{
			bool win=true;
			for(int i=1+k;i<=n;i++)
			{
				if(b[i]==0) continue;
				d[b[i]]=i-k;
				if(d[b[i]]>b[i]-1)
				{
					win=false;
					ans++;
					break;
				}
			}
			if(win)
			{
				ans+=n;
				cout<<ans;
				return 0;
			}
			k++;
		}
*/		int ans_add2=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0) continue;
			d[b[i]]=i;
			ans_add2=max(ans_add2,d[b[i]]-b[i]+1);
		}
		cout<<ans+ans_add2+n;
		return 0;
	}
	int find_1=1;
	while(b[find_1]!=1)	find_1++;
	int test_1=1,temp_1=find_1;
	bool flag=false;
	while(b[temp_1]==test_1)
	{
		temp_1++;test_1++;	
		if(temp_1==n+1)
			flag=true;
	}
	if(flag)
	{
		bool failed=false;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)	continue;
			else d[a[i]]=0;
		}
		for(int i=1;i<find_1;i++)
		{
			if(b[i]==0)	continue;
			else d[b[i]]=i;
		}
		for(int i=test_1;i<=n;i++)
			if(d[i]>i-test_1)
			{
				failed=true;
				break;
			}
		if(!failed)
		{
			ans=n-test_1+1;
			cout<<ans;
			return 0;
		}
	}
	ans+=find_1;
/*	while(true)
	{
		bool win=true;
		for(int i=1;i+find_1<=n;i++)
		{
			if(b[i+find_1]==0) continue;
			d[b[i+find_1]]=i;
			if(d[b[i+find_1]]>b[i+find_1]-1)
			{
				win=false;
				ans++;
				break;
			}
		}
		if(win)
		{
			ans+=n;
			break;
		}
		find_1++;

		
	}
	
*/
	int ans_add=0;
	for(int i=1;i+find_1<=n;i++)
		{
			if(b[i+find_1]==0) continue;
			d[b[i+find_1]]=i;
			ans_add=max(ans_add,d[b[i+find_1]]-b[i+find_1]+1);
		}
	cout<<ans+ans_add+n;
}

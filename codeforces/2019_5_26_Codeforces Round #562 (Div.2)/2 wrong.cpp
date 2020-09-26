#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[300005][3],sum=0,Index=1,num[300005],s[300005];
bool judge[300005];
int main()
{
	memset(judge,false,sizeof judge);
	memset(s,0,sizeof s);
	cin>>n>>m;
	for(int i=1; i<=m; i++) 
	{
		cin>>a[i][1]>>a[i][2];
		s[a[i][1]]++;
		s[a[i][2]]++;
		if(!judge[a[i][1]]&&sum<=n+2) 
		{
			judge[a[i][1]]=true;
			sum++;
			num[Index]=a[i][1];
			Index++;
		}
		if(!judge[a[i][2]]&&sum<=n+2) 
		{
			judge[a[i][2]]=true;
			sum++;
			num[Index]=a[i][2];
			Index++;
		}
	}
	if(sum>n+2) 
	{
		cout<<"NO";
		return 0;
	}
	Index--;
	sort(s+1,s+Index);
	/*	for(int i=1;i<Index;i++)
			for(int j=i+1;j<Index;j++)
			{
				int num1=i,num2=j;
				bool flag=true;
				for(int k=1;k<=m;k++)
				{
					if(a[k][1]!=num1&&a[k][2]!=num1&&a[k][1]!=num2&&a[k][2]!=num2)
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					cout<<"YES";
					return 0;
				}
			}

		cout<<"NO";
		*/
	for(int i=Index; i>=1; i--)
		for(int j=i; j>=1; j--) 
		{
			if(s[i]+s[j]>=m) 
			{
				int num1=i,num2=j;
				bool flag=true;
				for(int k=1; k<=m; k++) 
				{
					if(a[k][1]!=num1&&a[k][2]!=num1&&a[k][1]!=num2&&a[k][2]!=num2) 
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					cout<<"YES";
					return 0;
				}
			}
		}
	cout<<"NO";
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,ans[510][510];
char s[510][510];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s[i][j]-='0';
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			ans[i][j]=s[i][j];
			if(s[i][j])
			{
				for(int k=0;k<n;k++)
				{
					s[i][k]-=s[j][k];
					while(s[i][k]<0)
						s[i][k]+=10;
				}
			}
		}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d",ans[i][j]);
		printf("\n");
	}	

//	system("pause");
}
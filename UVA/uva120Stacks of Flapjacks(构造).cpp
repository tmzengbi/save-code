#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int Index,a[110];
void read()
{
	Index=0;
	char ch;
	while((ch=getchar())!='\n'&&ch!=EOF)
	{
		int num=0;
		while(isdigit(ch))
		{
			num=num*10+ch-'0';
			ch=getchar();
		}
		a[Index++]=num;
		if(ch=='\n') break;
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(1)
	{
		vector<int>ans;
		read();
		if(Index==0) break;
		for(int i=0;i<Index-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[Index-1]);
		for(int i=0,k=Index-1;i<Index;i++,k--)
		{
			int Max=0,mk;
			for(int j=0;j<=k;j++)
				if(Max<a[j]){Max=a[j];mk=j;}
			if(mk!=k)
			{
				if(mk!=0){reverse(a,a+mk+1);ans.push_back(Index-mk);}
				reverse(a,a+k+1);ans.push_back(Index-k);
			}
		}
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		puts("0");
	}
//	system("pause");
}

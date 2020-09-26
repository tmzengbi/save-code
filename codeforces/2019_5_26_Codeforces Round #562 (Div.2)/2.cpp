#include<iostream>
using namespace std;
int m,n,x,y,a[300005][3],Index[3];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i][1]>>a[i][2];
	for(int ii=1;ii<=2;ii++)
	{
		int flag=false;
		x=a[1][ii];
		for(int i=2;i<=m;i++)
		{
			if(x!=a[i][1]&&x!=a[i][2])
			{
				Index[ii]=i;
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
		{
			bool flag=true;
			for(int k=1;k<=m;k++)
			{
				x=a[1][i];y=a[Index[i]][j];
				if(x!=a[k][1]&&x!=a[k][2]&&y!=a[k][1]&&y!=a[k][2])
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	cout<<"NO"<<endl;
	return 0;
}

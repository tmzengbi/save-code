#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int read();
struct num
{
	int val;
	int Index;
}numk[100010];
bool cmp(num& num1,num& num2)
{
	return num1.val<num2.val;
}
int main() 
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		numk[i].val=read();
		numk[i].Index=i;
	}
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(numk[i].val%2!=0) flag=true;
	if(!flag)
	{
		for(int i=1;i<=n;i++)
			cout<<numk[i].val<<" ";
		return 0;
	}
	flag=false;
	for(int i=1;i<=n;i++)
		if(numk[i].val%2!=1) flag=true;
	if(!flag)
	{
		for(int i=1;i<=n;i++)
			cout<<numk[i].val<<" ";
		return 0;
	}
/*	int Min=2000000000;
	int mark;
	for(int i=1;i<=n;i++)
	{
		if(Min>numk[i].val)
		{
			Min=numk[i].val;
			mark=numk[i].Index;
		}
	}
	if(Min%2==0)
	{
		int temp;
		for(int i=1;i<=n;i++)
		{
			if(numk[i].val%2==1) temp=numk[i].Index;
			int tempk=numk[temp].val;numk[temp].val=numk[mark].val;numk[mark].val=tempk;
			break;
		}
		for(int i=1;i<=n;i++)
			cout<<numk[i].val<<" ";
	}
	if(Min%2==1)
	{
		int temp;
		for(int i=1;i<=n;i++)
		{
			if(numk[i].val%2==0) temp=numk[i].Index;
			int tempk=numk[temp].val;numk[temp].val=numk[mark].val;numk[mark].val=tempk;
			break;
		}
		for(int i=1;i<=n;i++)
			cout<<numk[i].val<<" ";
	}
	*/
	sort(numk+1,numk+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<numk[i].val<<" ";
}
inline int read()
{
	int f=1,shu=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}

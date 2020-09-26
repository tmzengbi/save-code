#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
struct num
{
	int num1,num2;
	num(int num1,int num2):num1(num1),num2(num2){	}
	
};
ostream& operator << (ostream&out,const num &Num)
{
	if(Num.num1>Num.num2)
		out<<Num.num2<<" "<<Num.num1;
	else out<<Num.num1<<" "<<Num.num2;
	return out;
}
vector<num> ans;
int n,p[300005];
bool vis[300005];
inline int read();
bool judge();
int main()
{
	memset(vis,false,sizeof vis);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	n=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	int k=(n+1)/2;
	
	while(!judge())
	{
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i)
		{
			vis[i]=true;
			continue;
		}
		if(abs(p[i]-i)>=k)
		{
			int temp=p[i];
			ans.push_back(num(i,temp));
			swap(p[i],p[temp]);
			vis[temp]=true;
			continue;
		}
		int m=((i+k)>n)?(1):(n);
		if(abs(m-p[i])>=k)
		{	int temp=p[i];
			ans.push_back(num(m,i));
			swap(p[m],p[i]);
			ans.push_back(num(m,temp));
			swap(p[m],p[temp]);
			ans.push_back(num(i,m));
			swap(p[i],p[m]);
			vis[temp]=true;
			continue;
		}

		if(abs(m-p[i])<k)
		{
			int temp=p[i];
			vis[temp]=true;
			int m2=(m==1)?n:1;
			ans.push_back(num(i,m));
			swap(p[i],p[m]);
			ans.push_back(num(m,m2));
			swap(p[m],p[m2]);
			ans.push_back(num(m2,temp));
			swap(p[m2],p[temp]);
			ans.push_back(num(m,m2));
			swap(p[m],p[m2]);
			ans.push_back(num(m,i));
			swap(p[m],p[i]);
			continue;
		}
	}
}
	int len=ans.size();
////	for(int i=1;i<=n;i++)
//		cout<<p[i]<<" ";
//	cout<<endl;
	cout<<len<<endl;
	for(int i=0;i<len;i++)
		cout<<ans[i]<<endl;
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
bool judge()
{
	for(int i=1;i<=n;i++)
		if(!vis[i]) return false;
	return true;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int read();
const int maxn=100005;
char k[maxn];
int Next[maxn];
int main()
{
	while(scanf("%s",k+1)==1)
	{
		int pos=0,last=0,len=strlen(k+1);
		Next[0]=0;						//Next[0]=1;
		for(int i=1;i<=len;i++)
		{
			if(k[i]=='[') pos=0;
			else if(k[i]==']') pos=last;
			else
			{
				Next[i]=Next[pos];		//Next[i]=Next[Next[pos]]
				Next[pos]=i;
				if(pos==last) last=i;
				pos=i;					//pos++;
			}
		}
		for(int i=Next[0];i!=0;i=Next[i])
			cout<<k[i];
		cout<<endl;
	}
	
}
int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch=='-') 
	{
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return f*shu;
}

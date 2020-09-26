#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=100010;
int N,K,d[maxn],a[maxn],Max=0;
bool ym(int m,int n)
{
	int tmp=K;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>m)
		{
			tmp=tmp-d[i]/(m+1);
			if(tmp<0)	return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&N,&K);
	char c=getchar();
	int ret=1,Index=0;
	for(int i=1;i<=N;i++)
	{
		char ch=c;
		c=getchar();
		if(c=='F')	a[i]=1;
		if(c=='N')	a[i]=0;
		if(ch==c)	ret++;
		else{d[Index++]=ret;Max=max(ret,Max);ret=1;}
	}
	d[Index]=ret;
	Max=max(ret,Max);
	if(Max==1){cout<<1;return 0;}
	int l=1,r=Max;
	bool Find=false;
	while(l<r)
	{
		int mid=(l+r)>>1;
		int tmp,cnt1=0,cnt2=0,cnt;
		if(mid==1)
		{
			int k=1;
			for(int i=1;i<=N;i++)
			{
				if(a[i]==k)	cnt1++;
				k=(!k);
			}
			k=0;
			for(int i=1;i<=N;i++)
			{
				if(a[i]==k)	cnt2++;
				k=(!k);
			}
			cnt=min(cnt1,cnt2);
			if(cnt<=K){cout<<1;Find=true;break;}
			else{cout<<2;Find=true;break;}
		}
		if(ym(mid,Index))	r=mid;
		else l=mid+1;
	}
	if(!Find)
		cout<<l;
	//system("pause");
}
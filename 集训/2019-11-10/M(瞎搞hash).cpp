#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Hash
{
	int key,v;
	bool valued;
	Hash *Next;
	Hash(){key=v=0;valued=false;Next=NULL;}
}H[100003];
const int F=100003;
int gethash(int k)
{
	return abs(k)%F;
}
void insert(int key)
{
	int k=gethash(key);
	Hash *tmp=&H[k];
	while(tmp->valued)
	{
		if(tmp->key==key) break;
		tmp=tmp->Next;
	}
	if(!tmp->valued)
	{
		tmp->key=key;
		tmp->valued=true;
		tmp->Next=new Hash();
	}
	tmp->v++;
	
}
int Find(int key)
{
	int k=gethash(key);
	Hash *tmp=&H[k];
	while(tmp->valued)
	{
		if(tmp->key==key) return tmp->v;
		tmp=tmp->Next;
	}
	return 0;
	
}
inline int read()
{
	int shu=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		shu=shu*10+ch-'0';
		ch=getchar();
	}
	return shu*f;
}
int T,n,a[2010];
int main()
{
	T=read();
	while(T--)
	{
		for(int i=0;i<100003;i++)
			H[i]=Hash();
		int ans=0;
		n=read();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<n;i++)
		{
			for(int j=1;j<i;j++)	insert(a[i]-a[j]+a[i]);
			ans+=Find(a[i+1]);
		}
		printf("%d\n",ans);
	}
//	system("pause");
}
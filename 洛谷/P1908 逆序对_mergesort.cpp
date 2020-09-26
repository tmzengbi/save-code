#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int n,a[500010],b[500010];
ll ans=0;
/*inline int read()
{
	int shu=0,f=-1;char ch=getchar();
	while(ch<'0'&&ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){shu=shu*10+ch-'0';ch=getchar();}
	return f*shu;
}
*/
void merge(int l,int r)
{
	int Index=l;
	int mid=(l+r)>>1,nl=l,nr=mid+1;
	while(nl<=mid&&nr<=r)
	{
		if(a[nl]>a[nr]){b[Index++]=a[nr++];ans+=mid-nl+1;}
		else b[Index++]=a[nl++];
	}
	while(nl<=mid)	b[Index++]=a[nl++];
	while(nr<=r)	b[Index++]=a[nr++];
	for(int i=l;i<=r;i++)
		a[i]=b[i];
}
void mergesort(int l,int r)
{
	if(l==r)	return;
	int mid=(l+r)>>1;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,r);
}
int main()
{
//	n=read();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//	a[i]=read();
	mergesort(1,n);
//	for(int i=1;i<=n;i++)
//		cout<<b[i]<<" ";
//	cout<<endl;
	printf("%lld\n",ans);
//	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1000010;
int t1[maxn],t2[maxn],n,sa[maxn],c[maxn],m;
char s[1000010];
int trans(char ch)
{
	if(ch>='0'&&ch<='9') return ch-'0';
	if(ch>='A'&&ch<='Z') return ch-'A'+10;
	if(ch>='a'&&ch<='z') return ch-'a'+36;
	return -1;
}
void getsa()
{
	int *x=t1,*y=t2;
	for(int i=0;i<m;i++) c[i]=0;
	for(int i=0;i<n;i++) x[i]=trans(s[i]);
	for(int i=0;i<n;i++) c[x[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i; 
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k;i<n;i++) y[p++]=i;
		for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<n;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);p=1;x[sa[0]]=0;
		for(int i=1;i<n;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
//		for(int i=0;i<n;i++) printf("%d ",x[i]);
		printf("\n");
		if(p>=n) break;
		m=p;
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);m=62;
	getsa();
	for(int i=0;i<n;i++) printf("%d ",sa[i]+1);
	printf("\n");
//	for(int i=0;i<n;i++) printf("%d ",t1[i]);

//	system("pause");
}
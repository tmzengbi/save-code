#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<random>
#include<unordered_map>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=133333+20;
const int maxnum=1e6+10;
int n,m,a[maxn],belong[maxn],cnt=0,que=0,ans[maxn],bk,ct[maxnum];
pii c[maxn];
struct Node
{
	int l,r,t,id;
	Node(){}
	Node(int l,int r,int t,int id):l(l),r(r),t(t),id(id){}
}q[maxn];
bool cmp(const Node&rhs1,const Node&rhs2)
{
	return (belong[rhs1.l]^belong[rhs2.l])?(belong[rhs1.l]<belong[rhs2.l]):((belong[rhs1.r]^belong[rhs2.r])?(belong[rhs1.r]<belong[rhs2.r]):rhs1.t<rhs2.t);
}
int sum=0;
inline void del(int x)
{
	ct[a[x]]--;
	if(!ct[a[x]]) sum--;
}
inline void add(int x)
{
	if(!ct[a[x]]) sum++;
	ct[a[x]]++;
}
inline void del_t(int Old,int New)
{
	ct[Old]--;
	if(!ct[Old]) sum--;
	if(!ct[New]) sum++;
	ct[New]++;
}
inline void add_t(int Old,int New)
{
	if(!ct[New]) sum++;
	ct[New]++;
	ct[Old]--;
	if(!ct[Old]) sum--;
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
int main()
{
//	freopen("a1.in","r",stdin);
//	freopen("a11.out","w",stdout);
	n=read();m=read();
//	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=read(); //scanf("%d",&a[i]);
	bk=(int)pow(n,2.0/3.0);
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bk+1;
	for(int i=1;i<=m;i++)
	{
		char s[5];int l,r;
//		scanf("%s%d%d",s,&l,&r);
		scanf("%s",s);l=read();r=read();
		if(s[0]=='Q'){que++;q[que]=Node(l,r,cnt,que);}
		else c[++cnt]=make_pair(l,r);
	}
	sort(q+1,q+que+1,cmp);
	int l=1,r=0,t=0;
	for(int i=1;i<=que;i++)
	{
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		while(t<q[i].t)
		{
			int now=c[++t].first,num=c[t].second;
			if(l<=now&&now<=r) add_t(a[now],num);
			swap(a[now],c[t].second);
		}
		while(t>q[i].t)
		{
			int now=c[t].first,num=c[t].second;
			if(l<=now&&now<=r) del_t(a[now],num);
			swap(a[now],c[t--].second);
		}
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=que;i++)
		printf("%d\n",ans[i]);
//	system("pause");
}

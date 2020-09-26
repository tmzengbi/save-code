#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=500010;
int n,f[maxn],m,s[maxn],a[maxn];
int gety(int x,int y)
{
	if(x>y) swap(x,y);
	return f[y]+s[y]*s[y]-f[x]-s[x]*s[x];
}
int getx(int x,int y)
{
	if(x>y) swap(x,y);
	return 2*(s[y]-s[x]);
}
int getval(int x,int y)
{
	if(x>y) swap(x,y);
	return f[x]+(s[y]-s[x])*(s[y]-s[x])+m;
}
struct myqueue
{
	int queue[maxn],head,tail;
	myqueue(){head=0;tail=-1;}
	bool empty(){return head>tail;}
	void push(int x){queue[++tail]=x;}
	void pop_front(){++head;}
	void pop_back(){--tail;}
	void clear(){head=0;tail=-1;}
	int size(){return tail-head+1;}
	int front(){return queue[head];}
	int back(){return queue[tail];}
	int next_front(){return queue[head+1];}
	int next_back(){return queue[tail-1];}
}q;
int main()
{
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		q.clear();
		for(int i=1;i<=n;i++)
		{	
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		f[0]=0;
		q.push(0);
		for(int i=1;i<=n;i++)
		{
			while(q.size()>=2&&gety(q.next_front(),q.front())<getx(q.next_front(),q.front())*s[i]) q.pop_front();
			f[i]=getval(q.front(),i);
			while(q.size()>=2&&gety(i,q.back())*getx(q.back(),q.next_back())<=gety(q.back(),q.next_back())*getx(q.back(),i)) q.pop_back();
			q.push(i);
		}
//		for(int i=1;i<=n;i++)
//			printf("%d ",f[i]);puts("");
		printf("%d\n",f[n]);
	}
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
ll dp[2][maxn],n,m,t[maxn],c[maxn];
ll *f=dp[0],*ans=dp[1],realans=2e18L;
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
ll gety(int i,int j)
{
	if(i>j) swap(i,j);
	return f[j]-f[i];
}
ll getx(int x,int y)
{
	if(x>y) swap(x,y);
	return c[y]-c[x];
}
ll calc(int i,int k,int j)
{
	return f[k]-c[k]*(t[i]+j*m)+c[i]*(t[i]+j*m);
}
int main()
{
	#ifdef DEBUG
		freopen("a1.in","r",stdin);
		freopen("a11.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&c[i]);
		t[i]=t[i]+t[i-1];c[i]=c[i]+c[i-1];
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
		f[i]=(m+t[i])*c[i];
	#ifdef DEBUG
//		for(int i=1;i<=n;i++)
//			printf("%d ",f[n]);puts("");
	#endif
	realans=f[n];
	for(int i=2;i<=n;i++)
	{
		q.clear();ll tmpd=m*i;
		q.push(i-1);
		for(int j=i;j<=n;j++)
		{
			ll d=tmpd+t[j];
			while(q.size()>=2&&gety(q.front(),q.next_front())<=getx(q.front(),q.next_front())*d) q.pop_front();
			ans[j]=calc(j,q.front(),i);
			if(j==n) realans=min(ans[j],realans);
			while(q.size()>=2&&gety(j,q.back())*getx(q.back(),q.next_back())<=getx(j,q.back())*gety(q.back(),q.next_back())) q.pop_back();
			q.push(j);
		}
		swap(f,ans);
		#ifdef DEBUG
//			for(int i=1;i<=n;i++)
//				printf("%d ",f[n]);puts("");
		#endif
	}
	printf("%lld\n",realans);
}
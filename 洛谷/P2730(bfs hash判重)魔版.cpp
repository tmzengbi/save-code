#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int hash_key=233333;
struct Hash
{
	int v;
	Hash *Next;
	Hash(){Next=NULL;}
}h[hash_key];
void hash_clear()
{
	for(int i=0;i<hash_key;i++)
	{
		Hash *now=h[i].Next;
		while(now)
		{
			Hash *tmp=now->Next;
			delete now;
			now=tmp;
		}
		h[i].Next=NULL;
	}
}
bool Find(int v)
{
	Hash *now=&h[v%hash_key];
	while(now->Next)
	{
		if(now->Next->v==v) return true;
		now=now->Next;
	}
	return false;
}
void insert(int v)
{
	Hash *now=&h[v%hash_key];
	while(now->Next)
	{
		if(now->Next->v==v) return;
		now=now->Next;
	}
	now->Next=new Hash();
	now->Next->v=v;
}
const int maxn=100010;
struct Node
{
	int f[8],step;
	int getNum()
	{
		int num=0;
		for(int i=0;i<8;i++) num=num*10+f[i];
		return num;
	}
	Node stepA()
	{
		Node tmp;
		for(int i=7,j=0;i>=4;i--,j++) tmp.f[i]=f[j];
		for(int i=0,j=7;i<4;i++,j--) tmp.f[i]=f[j];
		tmp.step=step+1;
		return tmp;
	}
	Node stepB()
	{
		Node tmp;
		for(int i=1;i<4;i++) tmp.f[i]=f[i-1];
		for(int i=6;i>=4;i--) tmp.f[i]=f[i+1];
		tmp.f[0]=f[3];tmp.f[7]=f[4];
		tmp.step=step+1;
		return tmp;
	}
	Node stepC()
	{
		Node tmp;
		memcpy(tmp.f,f,sizeof(int)*8);
		tmp.f[1]=f[6];tmp.f[2]=f[1];
		tmp.f[5]=f[2];tmp.f[6]=f[5];
		tmp.step=step+1;
		return tmp;
	}
}q[maxn],start;
char s[maxn];
int pre[maxn],to[8];
char S[maxn];int Index=0;
void solve()
{
	int head=1,tail=1;
	q[1]=start;
	insert(start.getNum());
	while(head<=tail)
	{
		Node u=q[head];
//		printf("%d",u.getNum());puts("");
//		system("pause");
		if(memcmp(u.f,to,sizeof(int)*8)==0){printf("%d\n",u.step);break;}
		Node tmp;int k;
		tmp=u.stepA();
		k=tmp.getNum();
		if(!Find(k))
		{
			insert(k);
			q[++tail]=tmp;
			s[tail]='A';
			pre[tail]=head;
		}
		tmp=u.stepB();
		k=tmp.getNum();
		if(!Find(k))
		{
			insert(k);
			q[++tail]=tmp;
			s[tail]='B';
			pre[tail]=head;
		}
		tmp=u.stepC();
		k=tmp.getNum();
		if(!Find(k))
		{
			insert(k);
			q[++tail]=tmp;
			s[tail]='C';
			pre[tail]=head;
		}
		head++;
	}
	while(head!=1)
	{
		S[++Index]=s[head];
		head=pre[head];
	}
	while(Index) printf("%c",S[Index--]);puts("");
}
int main()
{
	int tt;
	while(cin>>tt)
	{
		if(tt==-1){hash_clear();continue;}
		int d=Find(tt);
		if(!d) insert(tt);
		printf("%d\n",d);
	}
	for(int i=0;i<8;i++) scanf("%d",&to[i]);
	for(int i=0;i<8;i++) start.f[i]=i+1;
	start.step=0;
	solve();
	system("pause");
}
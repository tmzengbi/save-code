#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int P=1e9+7;
const int hashkey=233333;
const int maxn=2e5+10;
int hashcnt;
struct Hash
{
	int v;
	Hash *Next;
	Hash(){Next=NULL;}
}hash[233333],dizhi[maxn];
void hashinit()
{
	hashcnt=0;
	for(int i=0;i<hashkey;i++)
	{
		Hash *now=&hash[i];
		while(now->Next)
		{
			Hash *tmp=now->Next;
			now->Next=NULL;
			now=tmp;
		}
	}
}
void insert(int v)
{
	Hash *now=&hash[v%hashkey];
	while(now->Next) now=now->Next;
	now->Next=&dizhi[hashcnt++];
	now->Next->v=v;
}
bool Find(int v)
{
	Hash *now=&hash[v%hashkey];
	while(now->Next)
	{
		if(now->Next->v==v) return true;
		now=now->Next;
	}
	return false;
}
int main()
{
	int k,d;
	while(scanf("%d",&k)==1)
	{
		if(k==0) hashinit();
		else
		{
			scanf("%d",&d);
			int k=Find(d);
			if(!Find(d)) insert(d);
			printf("%d\n",k);
		}
	}
}

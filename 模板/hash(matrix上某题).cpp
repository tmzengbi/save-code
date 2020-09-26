/*
input:
00110011

output
10
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000010];
const int Key=23333;
struct Hash
{
	int v,k;
	Hash *Next;
	Hash(){v=1;k=0;Next=NULL;}
}myhash[23333];
int Find(int k)
{
	int key=(k%Key+Key)%Key;
	Hash *now=&myhash[key];
	while(now->Next)
	{
		if(k==now->Next->k) return now->Next->v;
		now=now->Next;
	}
	return 0;
}
void insert(int k)
{
	int key=(k%Key+Key)%Key;
	Hash *now=&myhash[key];
	while(now->Next)
	{
		if(k==now->Next->k){now->Next->v++;return;}
		now=now->Next;
	}
	now->Next=new Hash;
	now->Next->k=k;
}
int main()
{
	scanf("%s",s);
	insert(0);
	int len=strlen(s),sum=0;
	long long ans=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0') sum--;
		else sum++;
		ans+=Find(sum);
		insert(sum);
	}
	printf("%lld\n",ans);

//	system("pause");
}
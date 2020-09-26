#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000010];
const int Key=23333;
struct Hash
{
	int v,k;
	struct Hash *Next;
}hash[23333];
void init(struct Hash*H)
{
	H->v=1;
	H->Next=NULL;
}
int Find(int k)
{
	int key=(k%Key+Key)%Key;
	struct Hash *now=&hash[key];
	while(now->Next)
	{
		if(k==(now->Next->k)) return now->Next->v;
		now=now->Next;
	}
	return 0;
}
void insert(int k)
{
	int key=(k%Key+Key)%Key;
	struct Hash *now=&hash[key];
	while(now->Next)
	{
		if(k==now->Next->k){now->Next->v++;return;}
		now=now->Next;
	}
	now->Next=(struct Hash*)malloc(sizeof(struct Hash));
	init(now->Next);
	now->Next->k=k;
}
int main()
{
	for(int i=0;i<23333;i++) init(&hash[i]);
	scanf("%s",s);
	insert(0);
	int len=strlen(s),sum=0;
	long long int ans=0;
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
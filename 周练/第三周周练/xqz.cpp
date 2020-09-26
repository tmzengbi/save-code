#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int Index=0,s[100010],q[100010];
int main()
{
	int head=1,tail=0;
	int c;scanf("%d",&c);
	while(true)
	{
		int mod,k;scanf("%d",&mod);
		if(mod==0) break;
		if(mod==1)
		{
			scanf("%d",&k);
			s[++Index]=k;
		}
		else if(mod==2)
		{
			if(Index) printf("%d\n",s[Index--]);
			else printf("Error: the stack is empty!\n");
		}
		else if(mod==3)
		{
			if(Index<c) printf("Error: less than c elements in the stack!\n");
			else
			{
				for(int i=1;i<=c;i++) q[++tail]=s[Index--];
				for(int i=1;i<=c;i++) s[++Index]=q[head++];
			}
		}
	}
}
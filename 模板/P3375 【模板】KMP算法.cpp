#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> ans;
int Next[1000010],len1,len2;
char a[1000010],b[1000010];
void getnext()
{
    int i=2,j=1;
    Next[0]=-1;Next[1]=0;
    while(i<=len2)
    {
    	if(j==0||b[i]==b[j])
    	{
    		Next[i]=j;
    		i++;j++;
    	}
    	else j=Next[j-1]+1;
    }
}
void KMP()
{
	int i=1,j=1;
	for(i=1;i<=len1;i++)
	{
		while(j&&a[i]!=b[j]) j=Next[j-1]+1;
		if(j==0) j=1;
		else if(a[i]==b[j]) j++;
		if(j==len2+1) ans.push_back(i-len2+1);
	}
}
int main()
{
	scanf("%s%s",a+1,b+1);
	len1=strlen(a+1);len2=strlen(b+1);
	getnext();
	KMP();
	int len=ans.size();
	for (int i=0;i<len;i++)
		printf("%d\n",ans[i]);
	for(int i=1;i<=len2;i++)
		printf("%d ",Next[i]);
	printf("\n");


//	system("pause");
}
/*
ABCDABABCDABD
ABCDABD


abbaaaaaa
ba

k
aksdjjasdadsaxasxadxasxasxas
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,num[22],ans=0,sum=0;
char s[22][1010],st;
int check(char *pre,char *now)
{
	int len1=strlen(pre),len2=strlen(now);
	for(int i=len1-1;i;i--)
	{
		int j=i,k=0;bool win=true;
		for(;j<len1&&k<len2;j++,k++)
			if(pre[j]!=now[k]){win=false;break;}
		if(k==len2) win=false;
		if(win) return len2-k;
	}
	return 0;
}
void dfs(char *pre)
{
	for(int i=1;i<=n;i++)
	{
		if(!num[i]) continue;
		int k=check(pre,s[i]);
//		cout<<pre<<" "<<s[i]<<" "<<k<<endl;
		if(k)
		{
			sum+=k;
			ans=max(ans,sum);
			num[i]--;
			dfs(s[i]);
			num[i]++;
			sum-=k;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) num[i]=2;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	scanf("%s",&st);
	for(int i=1;i<=n;i++)
		if(s[i][0]==st) {sum=strlen(s[i]);ans=max(ans,sum);num[i]--;dfs(s[i]);num[i]++;}
	printf("%d\n",ans);
//	system("pause");
}
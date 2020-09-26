#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=2e2+10;
int t,sg[maxn],d[3][maxn];
char s[maxn];
bool vis[maxn];
bool bound(int x,int n)
{
	return x>0&&x<=n;
}
int main()
{
	sg[0]=0;sg[1]=sg[2]=sg[3]=1;
	for(int i=4;i<=200;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=1;j<=(i+1)/2;j++)
		{
			int t1=max(0,j-3),t2=i-j-2;
			vis[sg[t1]^sg[t2]]=1;
		}
		for(int j=0;;j++)
			if(!vis[j]){sg[i]=j;break;}
	}
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof vis);
		memset(d,0,sizeof d);
		vector<int>p;
		scanf("%s",s+1);
		int n=strlen(s+1);
		bool ok=false;
		for(int i=1;i<=n;i++)
			for(int j=-2;j<=2;j++) if(s[i]=='X'&&bound(i+j,n))
			{
				vis[i+j]=true;
				if(j&&s[i+j]=='X') ok=true;
			}
		if(ok)
		{
			puts("WINNING");
			for(int i=1;i<=n;i++) if(s[i]=='.')
			{
				if(bound(i+2,n)&&s[i+1]=='X'&&s[i+2]=='X') p.push_back(i);
				else if(bound(i-2,n)&&s[i-2]=='X'&&s[i-1]=='X') p.push_back(i);
				else if(bound(i+1,n)&&bound(i-1,n)&&s[i-1]=='X'&&s[i+1]=='X') p.push_back(i);
			}
			printf("%d",p[0]);
			for(int i=1;i<(int)p.size();i++)
				printf(" %d",p[i]);puts("");
			continue;
		}
		else p.clear();
		for(int i=1;i<=n;i++) if(!vis[i]) d[0][i]=d[0][i-1]+1;
		for(int i=n;i>=0;i--) if(!vis[i]) d[1][i]=d[1][i+1]+1;
		for(int i=1;i<=n;i++) if(!vis[i])
		{
			int num=0;
			while(i<=n&&!vis[i]){num++;i++;}
			p.push_back(num);
		}
		int win=0;
		for(int i:p) win^=sg[i];
		p.clear();
		if(win)
		{
			puts("WINNING");
			for(int i=1;i<=n;i++) if(!vis[i])
			{
				int now=d[0][i]+d[1][i]-1;
				if(!(win^sg[now]^sg[d[0][i]-3]^sg[d[1][i]-3])) p.push_back(i);
			}
			printf("%d",p[0]);
			for(int i=1;i<(int)p.size();i++)
				printf(" %d",p[i]);puts("");
		}
		else puts("LOSING\n");
	}
}
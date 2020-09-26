#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int maxn=4e5+10;
int q,x,mul[maxn];
bool vis[maxn];
int main()
{
	scanf("%d%d",&q,&x);
	int ans=0;
	for(int i=1;i<=q;i++)
	{
		int num;scanf("%d",&num);
		num=num%x;
		if(num+mul[num]*x<=q)
		{ 
			vis[num+mul[num]*x]=1;
			mul[num]++;
		}
		while(vis[ans]) ans++;
		printf("%d\n",ans);
	}
	system("pause");
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,H,d,sum=0,kk=0;
vector<int>t;
struct Node
{
	int a,b,id;
}k[100010];
bool cmp(Node n1,Node n2)
{
	return n1.a>n2.a;
}
int main()
{
	scanf("%d%d",&n,&H);
	for(int i=1;i<=n;i++)
	{
		k[i].id=i;
		scanf("%d%d",&k[i].a,&k[i].b);
	}
	sort(k+1,k+n+1,cmp);
	d=k[1].a;
	for(int i=1;i<=n;i++)
		if(k[i].b>d){sum+=k[i].b;kk++;t.push_back(k[i].b);}
	int ans=0;
	if(H-sum>0)
	{
		int tt=(H-sum)/d;
		if((H-sum)%d) tt++;
		ans+=tt;
		H-=tt*d;
	}
	sort(t.begin(),t.end(),greater<int>() );
	for(int i=0;i<t.size();i++)
	{
		if(H<=0) break;
		ans++;
		H-=t[i];
	}
	printf("%d\n",ans);

	system("pause");
}
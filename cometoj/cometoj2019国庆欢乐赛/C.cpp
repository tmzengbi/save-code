#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans=0;
struct buildings
{
	int beg,end;
}Left[200010],Right[200010];
bool cmp(buildings a,buildings b)
{
	return a.beg<b.beg;
}
bool isdoor(buildings a,buildings b)
{
	if(a.beg>=b.beg&&a.beg<=b.end) return true;
	if(b.beg>=a.beg&&b.beg<=a.end) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&Left[i].beg,&Left[i].end);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&Right[i].beg,&Right[i].end);
	sort(Left+1,Left+n+1,cmp);sort(Right+1,Right+m+1,cmp);
	int l=1,r=1;
	while(l<=n&&r<=m)
	{
		if(isdoor(Left[l],Right[r])) ans++;
		if(Left[l].end<Right[r].end) l++;
		else if(Left[l].end==Right[r].end)
		{
			if(l<n&&Left[l].end==Left[l+1].beg) ans++;
			if(r<m&&Right[r].end==Right[r+1].beg) ans++;
			l++;r++;
		}
		else r++;

	}
	printf("%d\n",ans);

//	while(1);
}
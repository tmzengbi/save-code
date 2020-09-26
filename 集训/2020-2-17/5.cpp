#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
vector<int>v[1010];
vector<char>ans;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans.clear();
		int Maxx=0;
		for(int i=0;i<=1000;i++) v[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			v[x].push_back(y);
			Maxx=max(Maxx,x);
		}
		for(int i=0;i<=1000;i++)
			sort(v[i].begin(),v[i].end());
		int now=0;
		bool win=true;
		for(int i=0;i<=Maxx;i++)
		{
			if(v[i].size()>0)
			{
				if(now>*(v[i].begin())){win=false;break;}
				for(int j=now;j<*(--v[i].end());j++)
					ans.push_back('U');
				now=*(--v[i].end());
			}
			if(i<Maxx)ans.push_back('R');
		}
		if(!win) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=0;i<ans.size();i++)
				printf("%c",ans[i]);
			puts("");
		}
	}
//	system("pause");
}
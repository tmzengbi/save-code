#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
int T,n,m;
set<int> s;
set<int>::iterator it;
map<int,int> setnum;
struct army
{
	int atk,def;
}my[100010],enemy[100010];
bool cmp_enemy(army a1,army a2)
{
	if(a1.def==a2.def) return a1.atk>a2.atk;
	return a1.def>a2.def;
}
bool cmp_my(army a1,army a2)
{
	return a1.atk>a2.atk;
}
int main()
{
	scanf("%d",&T);
	for(int Cas=1;Cas<=T;Cas++)
	{
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&my[i].atk,&my[i].def);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&enemy[i].atk,&enemy[i].def);
		if(n<m){printf("Case #%d: -1\n",Cas);continue;}
		sort(enemy+1,enemy+m+1,cmp_enemy);
		sort(my+1,my+n+1,cmp_my);
		s.clear();
		setnum.clear();
		int now=1;
		for(int i=1;i<=m;i++)
		{
			while(my[now].atk>=enemy[i].def&&now<=n)
			{
				s.insert(my[now].def);
				if(setnum.find(my[now].def)!=setnum.end()) setnum[my[now].def]++;
				else setnum[my[now].def]=1;
				now++;
			}
			if(s.empty()){ans=-1;break;}
			else
			{
				it=s.upper_bound(enemy[i].atk);
				if(it==s.end())
				{
					setnum[*s.begin()]--;
					if(setnum[*s.begin()]==0) s.erase(*s.begin());
				}
				else
				{
					ans++;
					setnum[*it]--;
					if(setnum[*it]==0) s.erase(*it);
				}
			}
			
		}
		if(ans!=-1)	ans=ans+(n-m);
		printf("Case #%d: %d\n",Cas,ans);
	}

//	system("pause");

}

/*
2
3 2 
5 7 
7 3 
1 2 
4 4 
2 2

2 1 
3 4 
1 10 
5 6
*/
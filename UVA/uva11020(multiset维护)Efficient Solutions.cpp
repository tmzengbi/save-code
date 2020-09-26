#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
struct Node
{
	int x,y;
	bool operator <(const Node &r) const
	{
		return x<r.x||(x==r.x&&y<r.y);
	}
};
multiset<Node>s;
multiset<Node>::iterator it;
int T,N,a,b;
int main()
{
	int cas=0;
	scanf("%d",&T);
	while(T--)
	{
		s.clear();
		scanf("%d",&N);
		if(cas) printf("\n");
		printf("Case #%d:\n",++cas);
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d",&a,&b);
			Node tmp=(Node){a,b};
			it=s.lower_bound(tmp);
			if(it==s.begin()||(--it)->y>b)
			{
				s.insert(tmp);
				it=s.upper_bound(tmp);
				while(it!=s.end()&&it->y>=b) s.erase(it++);
			}
			printf("%d\n",s.size());
		}
	}
//	system("pause");
}
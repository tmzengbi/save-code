#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
int T,N,M,K;
typedef vector<int> v;
int main()
{
	scanf("%d",&T);
	for(int Cas=1;Cas<=T;Cas++)
	{
		scanf("%d%d%d",&N,&M,&K);
		vector<v> map(N+10,v(M+10,0));
		getchar();
		int x=1,y=1;
		for(int i=1;i<=K;i++)
		{
			char ch;int step;
			scanf("%c%d",&ch,&step);getchar();
			if(ch=='D')
			{
				map[x][y]++;
				map[x+step][y]--;
				x+=step;
			}
			else if(ch=='U')
			{
				map[x][y]++;
				map[x-step][y]--;
				x-=step;
			}
			else if(ch=='L')	y-=step;
			else if(ch=='R')	y+=step;
//			cout<<x<<" "<<y<<endl;
		}
		ll ans=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				map[i][j]+=map[i][j-1]+map[i-1][j]-map[i-1][j-1];
//				cout<<map[i][j]<<" ";
				ans+=map[i][j]*map[i][j];
			}
//			cout<<endl;
		}
		printf("Case #%d: %lld\n",Cas,ans);
	}
//	system("pause");
}
/*
4
1 1 4
R 1
D 1
L 1
U 1
1 1 4
D 1
R 1
U 1
L 1
2 2 6
R 1
D 2
R 1
U 1
L 2
U 1
2 2 8
R 1
D 1
R 1
D 1
L 1
U 1
L 1
U 1
*/
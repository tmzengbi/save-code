#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
int N,M,cnt[maxn];
bool vis[maxn];
int main()
{
	scanf("%d%d",&N,&M);
	vector<vi> v(N+10,vi(M+10,0));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&v[i][j]);
	int ans=0;
	for(int j=0;j<M;j++)
	{
		int sum=1e9;
		if(j) for(int i=0;i<N;i++) vis[i*M+j]=0;
		for(int i=0;i<N;i++) vis[i*M+j+1]=1;
		for(int i=0;i<N;i++) cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			if(vis[v[i][j]])
			{
				int p=((i-(v[i][j]-j-1)/M)+N)%N;
				cnt[p]++;
			}
		}
		for(int i=0;i<N;i++)
			sum=min(sum,i+N-cnt[i]);
//		printf("%d %d\n",j,sum);
		ans+=sum;
	}
	printf("%d\n",ans);
//	system("pause");
}
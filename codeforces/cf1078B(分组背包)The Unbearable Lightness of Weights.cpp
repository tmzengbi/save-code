#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
typedef pair<double,double>pdd;
const int maxn=1e2+10;
int n,a[maxn],s=0;
ll dp[maxn][10010];
map<int,int>mp;
struct Node{
	int v,c;
	Node(int v=0,int c=0):v(v),c(c){}
}p[maxn];
vector<Node>g[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s+=a[i];
		++mp[a[i]];
	}
	if(mp.size()==2){
		printf("%d\n",n);
		return 0;
	}
	int Index=0;
	for(auto &now:mp){
		++Index;
		for(int i=1;i<=now.second;++i)
			g[Index].push_back(Node(now.first*i,i));
	}
	dp[0][0]=1;
	for(int ii=1;ii<=Index;++ii){
		for(int i=n;i>=0;--i)
			for(int j=s;j>=0;--j)
				for(auto k:g[ii])
					if(i-k.c>=0&&j-k.v>=0)
						dp[i][j]+=dp[i-k.c][j-k.v];
			}
	int ans=0;
	for(auto &now:mp){
		for(int i=1;i<=now.second;++i){
			int x=now.first;
			if(dp[i][x*i]==1){
				ans=max(ans,i);
			}
		}
	}
	printf("%d\n",ans);
}
/*
10
4 4 4 4 5 5 5 5 5 2
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
struct Node
{
	int w,c;
	Node(int w,int c):w(w),c(c){}
};
vector<Node>vec[15];
int f[210],N,V,T;
int main()
{
	scanf("%d%d%d",&V,&N,&T);
	for(int i=1;i<=N;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		vec[c].push_back(Node(a,b));
	}
	for(int i=1;i<=T;i++)
		for(int j=V;j>=0;j--)
			for(int k=0;k<vec[i].size();k++)
			{
				Node s=vec[i][k];
				if(j>=s.w) f[j]=max(f[j-s.w]+s.c,f[j]);
			}
	printf("%d\n",f[V]);

//	system("pause");
}
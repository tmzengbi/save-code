#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=22;
const int P=1000;
int n,m,t;
struct Matrix
{
	int ma[maxn][maxn];
	Matrix(){memset(ma,0,sizeof ma);}
	Matrix operator *(const Matrix &m)const
	{
		Matrix ans;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					ans.ma[i][j]=(ans.ma[i][j]+ma[i][k]*m.ma[k][j])%P;
		return ans;
	}
}mp,now,ut;
Matrix Pow(Matrix a,int n)
{
	Matrix sum=ut;
	for(;n;n>>=1)
	{
		if(n&1) sum=sum*a;
		if(n) a=a*a;
	}
	return sum;
}
int main()
{
	#ifdef DEBUG
		freopen("a.in","r",stdin);
		freopen("a11.out","w",stdout);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		mp=Matrix();
		for(int i=1;i<=m;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			mp.ma[u+1][v+1]=1;
		}
		for(int i=1;i<=n;i++)
			ut.ma[i][i]=1;
		scanf("%d",&t);
		while(t--)
		{
			int u,v,k;scanf("%d%d%d",&u,&v,&k);
			printf("%d\n",k?Pow(mp,k).ma[u+1][v+1]:u==v);
		}
	}
}
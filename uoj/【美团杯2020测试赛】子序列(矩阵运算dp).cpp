#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int P=998244353;
struct Matrix{
	int x[27][27];
	Matrix(){
		memset(x,0,sizeof x);
	}
	Matrix operator*(const Matrix&rhs){
		Matrix tmp;
		for(int i=0;i<27;++i)
			for(int j=0;j<27;++j)
				for(int k=0;k<27;++k)
					tmp.x[i][j]=(tmp.x[i][j]+1LL*x[i][k]*rhs.x[k][j])%P;
		return tmp;
	}
}ch[26],u;
const int maxn=2e3+10;
int n;
char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=0;i<26;++i){
		for(int j=0;j<27;++j)
			ch[i].x[j][j]=ch[i].x[i][j]=1;
	}
	u=ch[s[n]-'a'];
	for(int i=n-1;i;--i){
		int now=s[i]-'a';
		u=u*ch[now]*u;
	}
	int ans=0;
	for(int i=0;i<26;++i)
		ans=(ans+u.x[i][26])%P;
	printf("%d\n",ans);
}
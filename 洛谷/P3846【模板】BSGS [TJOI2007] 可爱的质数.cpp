#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
int p,b,n;
unordered_map<int,int>mp;
ll Pow(ll a,ll b,ll p){
	ll sum=1,z=a;
	for(;b;b>>=1){
		if(b&1) sum=sum*z%p;
		if(b) z=z*z%p;
	}
	return sum;
}
ll bsgs(int a,int b,int p){
	if(b==0) return 1;
	unordered_map<int,int>mp;
	int bk=sqrt(p)+1;
	for(int i=0;i<bk;++i){
		int val=Pow(a,i,p)*b%p;
		mp[val]=i;
	}
	for(int i=1;i<bk;++i){
		int val=Pow(a,1LL*i*bk,p);
		if(mp.count(val)){
			return bk*i-mp[val];
		}
	}
	return -1;
}
int main(){
	scanf("%d%d%d",&p,&b,&n);
	int res=bsgs(b,n,p);
	if(res==-1) puts("no solution");
	else printf("%d\n",res);
	
}
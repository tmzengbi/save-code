#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<ctime>
#include<random>
#include<bitset>
using namespace std;
typedef long long ll;
vector<int>ss;
int main(){
	int n;scanf("%d",&n);
	while(n){
		if(n==2){
			ss.push_back(1);
			ss.push_back(1);
			break;
		}
		ss.push_back((n+1)/2);
		n/=2;
	}
	cout<<ss.size()<<endl;
	for(int i=ss.size()-1;i>=0;--i){
		if(i==ss.size()-1){
			cout<<ss[i];
		} else {
			cout<<" "<<ss[i];
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int maxn=2e4+10;
int n;
struct Node{
	int l,r;
	Node(int l=0,int r=0):l(l),r(r){}
	bool operator < (const Node&rhs) const{
		return l<rhs.l;
	}
}p[maxn];
multiset<pii>s;
bool check(int x){
	s.clear();
	int k=0,kk=1;
	while(k<20000){
		while(kk<=n&&p[kk].l-x<=k){
			s.insert(make_pair(p[kk].r+x,p[kk].r-p[kk].l));
			++kk;
		}
		while(!s.empty()&&s.begin()->first<=k) s.erase(s.begin());
		if(s.empty()) return false;
		k=min(s.begin()->first,k+s.begin()->second);
		s.erase(s.begin());
	}
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].l*=2;p[i].r*=2;
	}
	sort(p+1,p+n+1);
	int l=0,r=20001;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(l%2==0){
		printf("%d\n",l/2);
	} else {
		printf("%d.5\n",l/2);
	}
}
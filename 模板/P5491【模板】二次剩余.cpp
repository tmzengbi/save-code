#include<bits/stdc++.h>
using namespace std;
int P=1e9+9;
typedef long long ll;
mt19937 rnd(time(NULL));
ll k;
struct Node{
    ll x,y;
    Node(ll x=0,ll y=0):x(x),y(y){}
    Node operator * (const Node &rhs) const {
        return Node((x*rhs.x%P+y*rhs.y%P*k%P)%P,(x*rhs.y%P+rhs.x*y%P)%P);
    }
};
ll Pow(ll a,ll b){
    ll sum=1;
    for(;b;b>>=1) {
        if(b&1) sum=sum*a%P;
        if(b) a=a*a%P;
    }
    return sum;
}
Node Pow(Node a,ll b){
    Node sum(1,0);
    for(;b;b>>=1) {
        if(b&1) sum=sum*a;
        if(b) a=a*a;
    }
    return sum;
}
void solve(int a){
    int tmp=Pow(a,(P-1)/2);
    if(tmp==P-1) {
        puts("Hola!");
        return;
    } else if(tmp==0){
        puts("0");
        return;
    }
    int x,w;
    while(1){
        x=rnd()%P;
        w=(Pow(x,2)-a+P)%P;
        if(Pow(w,(P-1)/2)==P-1) break;
    }
	k=w;
    Node tot(x,1);
    Node res=Pow(tot,(P+1)/2);
    int resA=res.x,resB=P-resA;
    if(resA>resB) swap(resA,resB);
    printf("%d %d\n",resA,resB);
}
int t,a;
int main() {
#ifdef DEBUG
    freopen("a.in","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&P);
        solve(a);
    }
}

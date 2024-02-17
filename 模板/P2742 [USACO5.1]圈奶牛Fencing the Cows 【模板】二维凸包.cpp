#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Node {
    double x,y;
    Node(double x=0,double y=0):x(x),y(y){}  
    Node operator - (const Node &rhs) const {
        return Node(x-rhs.x,y-rhs.y);
    }
}p[maxn];
bool cmp(const Node &lhs, const Node &rhs) {
    return lhs.x<rhs.x||(lhs.x==rhs.x&&lhs.y<rhs.y);
}
double dis(const Node &lhs,const Node &rhs) {
    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}
double cross(const Node &lhs, const Node &rhs) {
    return lhs.x*rhs.y-lhs.y*rhs.x;
}
map<pair<double,double>,int>mp;
int n,m;
int sta[maxn],idx;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        double x,y;
        scanf("%lf%lf",&x,&y);
        if(mp.count({x,y})) continue;
        p[++m]=Node(x,y);
        mp[{x,y}]=1;
    }
    sort(p+1,p+m+1,cmp);
    sta[idx=1]=1;
    for(int i=2;i<=m;++i) {
        while(idx>1&&cross(p[i]-p[sta[idx]],p[sta[idx]]-p[sta[idx-1]])>=0) --idx;
        sta[++idx]=i;
    }
    int tmp=idx;
    for(int i=m-1;i>=1;--i) {
        while(idx>tmp&&cross(p[i]-p[sta[idx]],p[sta[idx]]-p[sta[idx-1]])>=0) --idx;
        sta[++idx]=i;
    }
    double res=0;
    for(int i=2;i<=idx;++i)
        res+=dis(p[sta[i]],p[sta[i-1]]);
    printf("%.2lf\n",res);
}
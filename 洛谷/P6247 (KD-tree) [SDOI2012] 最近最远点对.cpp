#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int n, root;
struct Node {
    double x, y;
}a[maxn];

struct TreeNode {
    int left, right;
    double max_x,min_x,max_y,min_y;
}b[maxn];

bool cmp_x(const Node &a,const Node &b) {
    return a.x<b.x;
}

bool cmp_y(const Node &a,const Node &b) {
    return a.y<b.y;
}

int build(int l,int r,bool flag) {
    int mid=(l+r)>>1;
    nth_element(a+l,a+mid,a+r+1,flag?cmp_x:cmp_y);
    b[mid].left=b[mid].right=0;
    b[mid].max_x=b[mid].min_x=a[mid].x;
    b[mid].max_y=b[mid].min_y=a[mid].y;
    if(l<mid) b[mid].left=build(l,mid-1,flag^1);
    if(mid<r) b[mid].right=build(mid+1,r,flag^1);
    if(b[mid].left) {
        b[mid].max_x=max(b[mid].max_x,b[b[mid].left].max_x);
        b[mid].min_x=min(b[mid].min_x,b[b[mid].left].min_x);
        b[mid].max_y=max(b[mid].max_y,b[b[mid].left].max_y);
        b[mid].min_y=min(b[mid].min_y,b[b[mid].left].min_y);
    }
    if(b[mid].right) {
        b[mid].max_x=max(b[mid].max_x,b[b[mid].right].max_x);
        b[mid].min_x=min(b[mid].min_x,b[b[mid].right].min_x);
        b[mid].max_y=max(b[mid].max_y,b[b[mid].right].max_y);
        b[mid].min_y=min(b[mid].min_y,b[b[mid].right].min_y);
    }
    return mid;
}
double dis(const Node &a,const Node &b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mindisnode2area(const TreeNode& tnode,const Node &a) {
    double ans=2e18;
    if(a.x>=tnode.min_x&&a.x<=tnode.max_x&&a.y>=tnode.min_y&&a.y<=tnode.max_y) return 0;
    ans = min(ans,dis(a,Node{tnode.max_x,tnode.max_y}));
    ans = min(ans,dis(a,Node{tnode.max_x,tnode.min_y}));
    ans = min(ans,dis(a,Node{tnode.min_x,tnode.max_y}));
    ans = min(ans,dis(a,Node{tnode.min_x,tnode.min_y}));
    return ans;
}
double maxdisnode2area(const TreeNode& tnode,const Node &a) {
    double ans=0;
    ans = max(ans,dis(a,Node{tnode.max_x,tnode.max_y}));
    ans = max(ans,dis(a,Node{tnode.max_x,tnode.min_y}));
    ans = max(ans,dis(a,Node{tnode.min_x,tnode.max_y}));
    ans = max(ans,dis(a,Node{tnode.min_x,tnode.min_y}));
    return ans;
}


double minres=2e18, maxres=0;
int id;

void mindfs(int rt) {
    if(!rt) return;
    if(id!=rt) minres = min(minres,dis(a[id],a[rt]));
    if(b[rt].left&&mindisnode2area(b[b[rt].left],a[id])<minres)
        mindfs(b[rt].left);
    if(b[rt].right&&mindisnode2area(b[b[rt].right],a[id])<minres)
        mindfs(b[rt].right);
}

void maxdfs(int rt) {
    if(!rt) return;
    maxres = max(maxres,dis(a[id],a[rt]));
    if(b[rt].left&&maxdisnode2area(b[b[rt].left],a[id])>maxres)
        maxdfs(b[rt].left);
    if(b[rt].right&&maxdisnode2area(b[b[rt].right],a[id])>maxres)
        maxdfs(b[rt].right);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    root=build(1,n,0);
    for(int i=1;i<=n;++i) {
        id=i;
        mindfs(root);
        maxdfs(root);
    }
    printf("%.2lf %.2lf\n",minres,maxres);
}
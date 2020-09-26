#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50010;
int pre[maxn*3],N,K,ans=0;
int Find(int root)
{
    return pre[root]==root?root:(pre[root]=Find(pre[root]));
}
void merge(int r1,int r2)
{
    pre[Find(r1)]=Find(r2);
}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N*3;i++) pre[i]=i;
    while(K--)
    {
        int m,x,y;scanf("%d%d%d",&m,&x,&y);
        if(x>N||y>N) ans++;
        else if(m==1)
        {
            if(Find(x)==Find(y+N)||Find(x+N)==Find(y)) ans++;
            else
            {
                merge(x,y);merge(x+N,y+N);merge(x+2*N,y+2*N);
            }
        }
        else if(m==2)
        {
            if(Find(x)==Find(y)||Find(x+N)==Find(y)) ans++;
            else
            {
                merge(x,y+N);merge(x+N,y+2*N);merge(x+2*N,y);
            }
        }        
    }
    printf("%d\n",ans);
    system("pause");
}
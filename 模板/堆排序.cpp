#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
void down(int a[],int k)
{
    for(int i=k*2;i<=n;)
    {
        int mk=i,Max=a[i];
        if(i<n&&a[i]<a[i+1]){Max=a[i+1];mk=i+1;}
        if(a[k]<Max){swap(a[mk],a[k]);i=mk*2;k=mk;}
        else break;
    }
}
void heap(int a[])
{
    for(int i=n/2;i;i--)
        down(a,i);
}
void heapsort(int a[])
{
    while(n)
    {
        printf("%d ",a[1]);
        swap(a[1],a[n]);
        n--;
        down(a,1);
    }
}
int main()
{
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heap(a);
    heapsort(a);
    printf("\n");
    system("pause");
}
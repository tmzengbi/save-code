#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5000010;
const int mid=maxn/2;
int ans[maxn];//,Min,Max;
void build(int p);
int main()
{
	int n,Index=1;
	while(cin>>n)
	{
		if(n==-1)	break;
		
//		Min=Max=mid;
		memset(ans,0,sizeof ans);
		ans[mid]+=n;			//initial 
		
		build(mid-1);build(mid+1);
		int p=0;
		while(ans[p]==0)	p++;
		printf("Case %d:\n%d",Index,ans[p++]);
//		for(int i=Min;i<=Max;i++)
//		cout<<ans[i]<<" ";
		while(ans[p]!=0)	cout<<" "<<ans[p++];
		printf("\n\n");
		Index++;
	}
	
}
void build(int p)
{
	int val;
	cin>>val;
	if(val==-1)	return;
//	Min=min(p,Min);
//	Max=max(p,Max);
	ans[p]+=val;
	build(p-1);build(p+1);
}

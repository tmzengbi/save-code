#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int N;
struct node
{
	int v,id;
	bool belong;
	bool operator < (const node&NN)
	{
		return v>NN.v;
	}
}a[100010],b[100010];
vector<node>vec;
vector<int>a1;
vector<int>a2;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){scanf("%d",&a[i].v);a[i].id=i;a[i].belong=true;vec.push_back(a[i]);}
	for(int i=1;i<=N;i++){scanf("%d",&b[i].v);b[i].id=i;b[i].belong=false;vec.push_back(b[i]);}
	sort(vec.begin(),vec.end());
	for(int i=0;i<N;i++)
		if(vec[i].belong) a1.push_back(vec[i].id);
	for(int i=N;i<2*N;i++)
		if(!vec[i].belong) a2.push_back(vec[i].id);
	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());
	long long ans=0;
	for(int i=0;i<a1.size();i++)
	{
		printf("%d %d\n",a1[i],a2[i]);
		ans+=abs(a1[i]-a2[i]);
	}
	printf("%lld\n",ans);
	system("pause");
}
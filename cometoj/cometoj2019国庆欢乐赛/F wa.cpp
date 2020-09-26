#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int N,lim[100010],Real[100010];
ll sum=0,ans=0;
vector<int> pos;
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&lim[i]);
	for(int i=2;i<=N;i++)
		Real[i]=min(lim[i],lim[i-1]+10);
	for(int i=1;i<N;i++)
		Real[i]=min(lim[i],lim[i+1]+10);
	for(int i=1;i<=N;i++)
	{
		sum+=Real[i];
		if(Real[i]==lim[i]) pos.push_back(i);
	}
	for(int i=0;i<pos.size();i++)
	{
		int tmp_Real=2e9,p=pos[i];
		if(p>1) tmp_Real=min(tmp_Real,lim[p-1]+10);
		if(p<N) tmp_Real=min(tmp_Real,lim[p+1]+10);
		ans=max(ans,sum-Real[p]+tmp_Real);
	}

	printf("%d\n",ans);


	while(1);
}
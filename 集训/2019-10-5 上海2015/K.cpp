#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
ll T,Part[100010];
ll sum=0,ans=0;
char s[100010];
int main()
{
	scanf("%lld",&T);getchar();
	for(ll C=1;C<=T;C++)
	{
		ll cnt=0;sum=0;ans=0;
		scanf("%s",s+1);
		ll len=strlen(s+1),Count=1;
		for(ll i=2;i<=len;i++)
		{
			if(s[i]!=s[i-1]) {Part[++cnt]=Count;Count=1;}
			else Count++;
		}
		Part[++cnt]=Count;Part[0]=Part[cnt+1]=0;
		for(ll i=1;i<=cnt;i++)
			sum+=Part[i]*Part[i];
		ans=sum;
		for(ll i=1;i<=cnt;i++)
		{
			ll tmp_sum=sum;
			if(Part[i]==1) 
			{
				ll tmp_add=Part[i-1]+Part[i+1]+1;
				tmp_sum=tmp_sum-Part[i-1]*Part[i-1]-Part[i+1]*Part[i+1]-1+tmp_add*tmp_add;
			}
			else
			{
				tmp_sum=tmp_sum-Part[i]*Part[i]-Part[i+1]*Part[i+1]+(Part[i]-1)*(Part[i]-1)+(Part[i+1]+1)*(Part[i+1]+1);
				ll tmp_sum2=sum;
				tmp_sum2=tmp_sum2-Part[i]*Part[i]-Part[i-1]*Part[i-1]+(Part[i]-1)*(Part[i]-1)+(Part[i-1]+1)*(Part[i-1]+1);
				tmp_sum=max(tmp_sum,tmp_sum2);
			}

			ans=max(ans,tmp_sum);
		}
		printf("Case #%lld: %lld\n",C,ans);
//		cout<<ans<<endl;
	}


//	system("pause");
//	while(1);
}

/*
2 000011 0101
*/
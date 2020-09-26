#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
typedef long long ll;
stack <ll>s;
const ll Int=2147483647;
const ll Int_Max=Int*2+1;
ll ans=0,temp_add[100010],dep=0;
int main()
{
	int n;
	cin>>n;
	while(n-- >0)
	{
//		memset(temp_add,0,sizeof temp_add);
//		dep=0;ans=0;
		char ch[10];
		cin>>ch;
		if(ch[0]=='a')
			if(dep==0)	ans++;
			else temp_add[dep]++;
		if(ch[0]=='f')
		{
			ll shu;
			cin>>shu;
			s.push(shu);
			dep++;
		}
		if(ch[0]=='e')
		{
			ll t=s.top();s.pop();
			temp_add[dep-1]+=temp_add[dep]*t;
			temp_add[dep]=0;
			dep--;
			if(s.empty())
			{
				ans+=temp_add[dep];
				temp_add[dep]=0;
			}
		}
		if(temp_add[dep]>Int_Max)
		
		{
			cout<<"OVERFLOW!!!";
			return 0;
		}
	}
	if(ans>Int_Max)
	{
		cout<<"OVERFLOW!!!";
		return 0;
	}
	cout<<ans;
}
 

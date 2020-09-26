#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int pass[27];
bool vis[27];
int change(char ch){return (int)ch-'A';}
char changeback(int x){return (char)(x+'A');}
int main()
{
	
//	string Cas;
//	while(cin>>Cas)
//	{
		memset(pass,-1,sizeof pass);
		memset(vis,false,sizeof vis);
		bool win=true;
		string a,b;cin>>a>>b;
		int len=a.length();
		for(int i=0;i<len;i++)
		{
			int x=change(a[i]),y=change(b[i]);
//			cout<<x<<" "<<y<<endl;
			if(pass[x]==-1&&!vis[y]) {pass[x]=y;vis[y]=true;}
			else if(vis[y]&&pass[x]==y) continue;
			else {win=false;break;}
		}
		string s;cin>>s;
		len=s.length();
		vector<char> ans;
		for(int i=0;i<len;i++)
		{
			int x=change(s[i]);	
			if(pass[x]==-1){win=false;break;}
			ans.push_back(changeback(pass[x]));
		}
//		cout<<Cas<<endl;
		if(win)
		{
			int len=ans.size();
			for(int i=0;i<len;i++) 
				cout<<ans[i];
		}
		else cout<<"Failed";
//		cout<<endl;
//	}
}
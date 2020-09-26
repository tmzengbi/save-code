#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	int a,b;
	int Index;
}node[300010];
ostream& operator <<(ostream& out, const Node a1)
{
	out<<a1.a<<" "<<a1.b<<endl;
	return out;
} 
vector<Node> v1;
vector<Node> v2;
bool cmp1(Node a1,Node a2);
bool cmp2(Node a1,Node a2);
bool isupper(Node a1);

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>node[i].a>>node[i].b;
		node[i].Index=i;
		if(isupper(node[i]))	v1.push_back(node[i]);
		else v2.push_back(node[i]);
	}
	sort(v1.begin(),v1.end(),cmp1);
	sort(v2.begin(),v2.end(),cmp2);
	
/*	cout<<endl;
	for(int i=0;i<v1.size();i++)
		cout<<v1[i];							//test input
	for(int i=0;i<v2.size();i++)	
		cout<<v2[i];
*/
	int ans1=0,temp1=1;
	vector<int>v;
	vector<int>t1;
	if(!v1.empty())
	{
		t1.push_back(v1[0].Index);
	}
	else temp1=0;
	int len1=(v1.empty())?0:v1.size();
	for(int i=1;i<len1;i++)
	{
		if(v1[i].a<v1[i-1].b)
		{
			temp1++;
			t1.push_back(v1[i].Index);
		}
		else
		{
			if(ans1<temp1)
			{
				ans1=temp1;
				v.clear();
				v=t1;
				temp1=0;
				t1.clear();
			}
			else
			{
				temp1=0;
				t1.clear();
			}
		}
	}
	if(ans1<temp1)
	{
		ans1=temp1;
		v=t1;
	}
	


	int ans2=0,temp2=1;
	vector<int> vv;
	vector<int> t2;
	if(!v2.empty()) 
	{
		t2.push_back(v2[0].Index);
	}
	else temp2=0;
	int len2=(v2.empty())?0:v2.size();
	for(int i=1;i<len2;i++)
	{
		if(v2[i].a>v2[i-1].b)
		{
			temp2++;
			t2.push_back(v2[i].Index);
		}
		else
		{
			if(ans2<temp2)
			{
				ans2=temp2;
				vv.clear();
				vv=t2;
				temp2=0;
				t2.clear();
			}
			else
			{
				temp2=0;
				t2.clear();
			}
		}
	}
	if(ans2<temp2)
	{
		ans2=temp2;
		vv=t2;
	}
	int ans=max(ans1,ans2);
	cout<<ans<<endl;
	if(ans1>ans2)
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
	else 
		for(int i=0;i<vv.size();i++)
			cout<<vv[i]<<" ";
			
}
bool cmp1(Node a1,Node a2)
{
	return a1.a>a2.a;
}
bool cmp2(Node a1,Node a2)
{
	return a1.b<a2.b;
}
bool isupper(Node a1)
{
	if(a1.a<a1.b)	return true;
	else return false;
}

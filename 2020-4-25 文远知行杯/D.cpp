#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct Node
{
	int x,y;
	Node(int x=0,int y=0):x(x),y(y){}
	void scan()
	{
		scanf("%d%d",&x,&y);
	}
};
typedef Node Vector;
struct Line
{
	Node a,b;
	void scan()
	{
		a.scan();b.scan();
	}
	int maxx()
	{
		return max(a.x,b.x);
	}
	int minx()
	{
		return min(a.x,b.x);
	}
	int maxy()
	{
		return max(a.y,b.y);
	}
	int miny()
	{
		return min(a.y,b.y);
	}
}a,b;
ll cross(Vector a,Vector b)
{
	return (ll)a.x*b.y-(ll)a.y*b.x;
}
Vector del(Vector a,Vector b)
{
	return Vector(a.x-b.x,a.y-b.y);
}
int sign(ll x)
{
	if(x==0) return 0;
	if(x>0) return 1;
	return -1;
}
int main()
{
	a.scan();b.scan();
	if(a.maxx()<b.minx()||a.maxy()<b.miny()||b.maxx()<a.minx()||b.maxy()<a.miny())
	{
		puts("no");
		return 0;
	}
	Vector mid=del(a.a,a.b);
	Vector v1=del(b.a,a.a);
	Vector v2=del(b.b,a.a);
	int s1=sign(cross(v1,mid)),s2=sign(cross(v2,mid));
	if(s1*s2>0){puts("no");return 0;}
	mid=del(b.a,b.b);
	v1=del(a.a,b.a);
	v2=del(a.b,b.a);
	s1=sign(cross(v1,mid));s2=sign(cross(v2,mid));
	if(s1*s2>0){puts("no");return 0;}
	puts("yes");
//	system("pause");
}
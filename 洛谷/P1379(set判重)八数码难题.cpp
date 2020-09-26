#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
	int S[9],Step;
	int Find()
	{
		for(int i=0;i<9;i++)
			if(!S[i]) return i;
	}
	void swap(int x,int y,int nx,int ny)
	{
		int x1=x*3+y,x2=nx*3+ny;
		int tmp=S[x1];
		S[x1]=S[x2];
		S[x2]=tmp;
	}
	int getNum()
	{
		int num=0;
		for(int i=0;i<9;i++)
			num=num*10+S[i];
		return num;
	}
}From;

int To[9]={1,2,3,8,0,4,7,6,5};
set<int>s;
const int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
int bfs()
{
	queue<Node>q;
	q.push(From);
	while(!q.empty())
	{
		Node st=q.front();q.pop();

		if(memcmp(st.S,To,sizeof(int)*9)==0) return st.Step;
		int x=st.Find(),y=x%3;x/=3;
		for(int i=0;i<4;i++)
		{
			Node tmp=st;
			int nx=x+fx[i],ny=y+fy[i];
			if(nx<0||ny<0||nx>2||ny>2) continue;
			tmp.swap(x,y,nx,ny);
			int key=tmp.getNum();
			if(!s.count(key))
			{
				s.insert(key);
				tmp.Step++;
				q.push(tmp);
			}
		}
	}
}
int main()
{
	for(int i=0;i<9;i++) scanf("%1d",&From.S[i]);
	From.Step=0;
	printf("%d\n",bfs());
//	system("pause");
}
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
*/
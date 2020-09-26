#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
using namespace std;
const int hash_key=233333;
struct Hash
{
	int v,Step;
	Hash *Next;
	Hash(){Next=NULL;}
}h[2][233333];
bool insert(int v,int m,int step)
{
	int vv=v%233333;
	Hash *now=&h[m][vv];
	while(now->Next)
	{
		if(now->Next->v==v) return 0;
		now=now->Next;
	}
	now->Next=new Hash;
	now->Next->v=v;
	now->Next->Step=step;
	return 1;
}
int Find(int v,int m)
{
	int vv=v%233333;
	Hash *now=&h[m][vv];
	while(now->Next)
	{
		if(now->Next->v==v) return now->Next->Step;
		now=now->Next;
	}
	return -1;
}
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
}From,To;
const int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
int bfs()
{
	queue<Node>q1,q2;
	q1.push(From);
	q2.push(To);
	int t1=From.getNum(),t2=To.getNum();
	insert(t1,0,0);insert(t2,1,0);
	while(!q1.empty()&&!q2.empty())
	{
		Node st=q1.front();q1.pop();
		int f=Find(st.getNum(),1);
		if(f!=-1) return st.Step+f;
		int x=st.Find(),y=x%3;x/=3;
		for(int i=0;i<4;i++)
		{
			Node tmp=st;
			int nx=x+fx[i],ny=y+fy[i];
			if(nx<0||ny<0||nx>2||ny>2) continue;
			tmp.swap(x,y,nx,ny);
			int key=tmp.getNum();
			if(insert(key,0,tmp.Step+1))
			{
				tmp.Step++;
				q1.push(tmp);
			}
		}
		Node st2=q2.front();q2.pop();
		f=Find(st2.getNum(),0);
		if(f!=-1) return st2.Step+f;
		x=st2.Find();y=x%3;x/=3;
		for(int i=0;i<4;i++)
		{
			Node tmp=st2;
			int nx=x+fx[i],ny=y+fy[i];
			if(nx<0||ny<0||nx>2||ny>2) continue;
			tmp.swap(x,y,nx,ny);
			int key=tmp.getNum();
			if(insert(key,1,tmp.Step+1))
			{
				tmp.Step++;
				q2.push(tmp);
			}
		}
	}
	return -1;
}
int main()
{
	int n;
	for(int i=0;i<9;i++) scanf("%1d",&From.S[i]);
//	for(int i=0;i<9;i++) scanf("%d",&To.S[i]);
	int tmp[]={1,2,3,8,0,4,7,6,5};
	memcpy(To.S,tmp,sizeof(int)*9);
	From.Step=0;To.Step=0;
	printf("%d\n",bfs());
//	system("pause");
}
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
*/
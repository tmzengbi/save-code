#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 30
#define NullPtr -1
typedef int ValueType;
typedef int Pointer;
typedef int Position;
typedef int Index;
typedef unsigned int SizeType;
typedef struct node{
    ValueType value;
    Pointer next;
}Node;
struct manager;
struct memoryManager{
    Node Memory[MaxSize];
    struct manager* Manager;
};
typedef struct staticLinkedList{
    Pointer head;
    SizeType size;
}StaticLinkedList;
/*
<body>
*/

struct manager
{
	Position pos;
	struct manager* Next;
};
void inserttomanager(struct memoryManager*m,Position pos)
{
	struct manager* add=(struct manager*)malloc(sizeof(struct manager));
	add->Next=NULL;add->pos=pos;
	if(m->Manager==NULL) m->Manager=add;
	else
	{
		add->Next=m->Manager->Next;
		m->Manager->Next=add;
	}
}
void popmanager(struct memoryManager*head)
{
	struct manager*del=head->Manager;
	head->Manager=del->Next;
	free(del);
}
int eraselast(struct memoryManager*head)
{
	if(head->Manager==NULL) return -1;
	struct manager*del=head->Manager,*pre=del;
	if(del->Next==NULL)
	{
		head->Manager=NULL;
		int d=del->pos;
		free(del);
		return d;
	}
	while(del->Next!=NULL)
	{
		pre=del;
		del=del->Next;
	}
	pre->Next=NULL;
	int d=del->pos;
	free(del);
	return d;
}
int allocated(struct memoryManager* m)
{
	return eraselast(m);
}
void iniManager(struct memoryManager* m)
{
	m->Manager=NULL;
	for(int i=0;i<MaxSize;i++)
	{
		m->Memory[i].next=NullPtr;
		inserttomanager(m,i);
	}
}
void releaseManager(struct memoryManager*m)
{
	for(int i=0;i<MaxSize;i++)
		m->Memory[i].next=NullPtr;
	struct manager* Manager=m->Manager;
	while(Manager)
	{
		struct manager*tmp=Manager->Next;
		free(Manager);
		Manager=tmp;
	}
}
void iniList(StaticLinkedList* m)
{
	m->head=NullPtr;
	m->size=0;
}
bool insert(StaticLinkedList* list,struct memoryManager*m,ValueType val,Position pos)
{
	if(pos<0) return false;
	int now=list->head,memorypos;
	if(pos)
	{
		if(now==-1) return false;
		for(int i=1;i<pos;i++)
		{
			now=m->Memory[now].next;
			if(now==-1) return false;
		}
	}
	if((memorypos=allocated(m))!=-1)
	{
		if(pos==0)
		{
			m->Memory[memorypos].next=now;
			m->Memory[memorypos].value=val;
			list->head=memorypos;
		}
		else
		{
			m->Memory[memorypos].value=val;
			m->Memory[memorypos].next=m->Memory[now].next;
			m->Memory[now].next=memorypos;
		}
		list->size++;
		return true;
	}
	return false;
}
Pointer erase(StaticLinkedList* list,struct memoryManager* m,Position pos)
{
	int now=list->head;
	if(list->size<=pos) return -1;
	if(pos==0)
	{
		Node del=m->Memory[now];
		list->head=del.next;
		inserttomanager(m,now);
		list->size--;
		return del.next;
	}
	for(int i=1;i<pos;i++)
	{
		now=m->Memory[now].next;
		if(m->Memory[now].next==-1) return -1;
	}
	int Next=m->Memory[now].next;
	Node del=m->Memory[Next];
	m->Memory[now].next=del.next;
	inserttomanager(m,Next);
	list->size--;
	return del.next;
}
void show(StaticLinkedList* list,struct memoryManager*m)
{
	int now=list->head;
	while(now!=-1)
	{
		printf("%d -> ",m->Memory[now].value);
		now=m->Memory[now].next;
	}
	printf("Null\n");
	printf("The size of this list is %d\n",list->size);
}
bool pushBack(StaticLinkedList*list,struct memoryManager*m,ValueType val)
{
	int memorypos;
	if((memorypos=allocated(m))!=-1)
	{
		int now=list->head;
		Node *add=&m->Memory[memorypos];
		add->value=val;
		if(now==-1)
		{
			m->Memory[memorypos].next=-1;
			list->head=memorypos;
		}
		else
		{
			while(m->Memory[now].next!=-1)
				now=m->Memory[now].next;
			add->next=m->Memory[now].next;
			m->Memory[now].next=memorypos;
		}
		list->size++;
		return true;
	}
	return false;
}
bool popBack(StaticLinkedList*list,struct memoryManager*m)
{
	int now=list->head,pre=now;
	if(now==-1) return false;
	if(m->Memory[now].next==-1) list->head=-1;
	else
	{
		while(m->Memory[now].next!=-1)
		{
			pre=now;
			now=m->Memory[now].next;
		}
		m->Memory[pre].next=-1;
	}
	list->size--;
	inserttomanager(m,now);
	return true;
}
//2
void reverse(StaticLinkedList*list,struct memoryManager*m)
{
    if(list->size<=1) return;
	int now=list->head;
	while(m->Memory[now].next!=-1)
	{
		int Next=m->Memory[now].next,front=list->head;
		list->head=Next;
		m->Memory[now].next=m->Memory[Next].next;
		m->Memory[Next].next=front;
	}
}
//2
//3
int remove_if(StaticLinkedList* list,struct memoryManager*m,bool (fun)(const Node*))
{
	if(list->size==0) return 0;
	int cnt=0,now=list->head,nowpos=0;
	while(now!=-1)
	{
		int tmp=m->Memory[now].next;
		if(fun(&m->Memory[now]))
		{
			erase(list,m,nowpos);
			cnt++;
		}
		else nowpos++;
		now=tmp;
	}
	return cnt;
}
//3
//4
int divide(int head,struct memoryManager *m)
{
	int slow,fast;
	fast=m->Memory[head].next;slow=head;
	while(fast!=-1&&m->Memory[fast].next!=-1)
	{
		slow=m->Memory[slow].next;
		fast=m->Memory[fast].next;
		fast=m->Memory[fast].next;
	}
	int ans=m->Memory[slow].next;
	m->Memory[slow].next=-1;
	return ans;
}
int merge(int list1,int list2,struct memoryManager*m)
{
	if(list2==-1) return list1;
	Node tmp,*now=&tmp;
	int ptr1=list1,ptr2=list2;
	while(ptr1!=-1||ptr2!=-1)
	{
		int num1=ptr1==-1?2e9:m->Memory[ptr1].value;
		int num2=ptr2==-1?2e9:m->Memory[ptr2].value;
		if(num1<num2)
		{
			now->next=ptr1;
			now=&m->Memory[ptr1];
			ptr1=m->Memory[ptr1].next;
		}
		else
		{
			now->next=ptr2;
			now=&m->Memory[ptr2];
			ptr2=m->Memory[ptr2].next;
		}
	}
	return tmp.next;
}
int mergesort(int list,struct memoryManager*m)
{
	if(list==-1||m->Memory[list].next==-1) return list;
	int head=list,mid=divide(head,m);
	int l1=mergesort(head,m),l2=mergesort(mid,m);
	return merge(l1,l2,m);
}
void sort(StaticLinkedList*list, struct memoryManager*m)
{
	if(list->size==0||list->size==1) return;
	list->head=mergesort(list->head,m);
}
//4
// </body>
int main(){
    struct memoryManager myManager;
    StaticLinkedList List1,List2;
    iniManager(&myManager);
    iniList(&List1);
    iniList(&List2);

    if (true){
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            int value,position;
            scanf("%d",&value);
            scanf("%d",&position);
            insert(&List1,&myManager,value,position);
//          insert(&List2,&myManager,2*value,position/2);
        }
        show(&List1,&myManager);
//        show(&List2,&myManager);
		sort(&List1,&myManager);
		show(&List1,&myManager);
        int m;
        scanf("%d",&m);
        for (int i = 0; i < m; ++i) {
            int position;
            scanf("%d",&position);
            erase(&List1,&myManager,position);
            erase(&List2,&myManager,position/2);
        }
        show(&List1,&myManager);
        show(&List2,&myManager);
        int t;
        scanf("%d",&t);
        for (int i = 0; i < t; ++i) {
            int value,position;
            scanf("%d",&value);
            scanf("%d",&position);
            insert(&List1,&myManager,value,position);
            insert(&List2,&myManager,2*value,position/2);
        }
        if (t){
            show(&List1,&myManager);
            show(&List2,&myManager);
        }

        pushBack(&List1,&myManager,n);
        pushBack(&List2,&myManager,m);
        show(&List1,&myManager);
        show(&List2,&myManager);

        popBack(&List1,&myManager);
        popBack(&List2,&myManager);
        show(&List1,&myManager);
        show(&List2,&myManager);

    }
    releaseManager(&myManager);
	system("pause");
    return 0;
}
/*
10
1 0 1 0 2 0 2 0 3 0 3 0 4 0 4 0 5 0 5 0
*/
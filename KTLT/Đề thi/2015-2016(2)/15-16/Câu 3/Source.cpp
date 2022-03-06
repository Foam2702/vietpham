#include<iostream>
using namespace std;

struct NODE
{
	int key;
	NODE* pNext;
};

struct List {
	NODE* pHhead = NULL;
};
NODE* CreateNode(int value)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	p->key = value;
	p->pNext = NULL;
	return p;
}

void InsertTail(NODE*& pHead, int x)
{

}
void InsertHead(NODE* &pHead, int x)
{
	if (pHead == NULL)
	{
		NODE* p = CreateNode(x);
		pHead = p;
	}
	else
	{
		NODE* p = CreateNode(x);
		p->pNext = pHead;
		pHead = p;
	}

}
void DestroyList(NODE*& pHead)
{
	NODE* p = new NODE;
	while (pHead)
	{
		p = pHead;
		pHead = pHead->pNext;
		delete p;
	}

}
int main()
{
	List l;
	NODE* pHead =NULL ;
	int n;cin >> n;
	int* arr=new int[n];
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		InsertHead(pHead, arr[i]);
	}

	for (NODE* g = pHead; g ; g = g->pNext)
	{
		cout << g->key << " ";
	}
	
	delete[]arr;
	DestroyList(pHead);
	return 0;
	
}


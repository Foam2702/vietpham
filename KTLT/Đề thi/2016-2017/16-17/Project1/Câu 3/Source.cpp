#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

struct List
{
	Node* pHead = NULL;
};

Node* CreateNode(int &value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = value;
		p->next = NULL;
	}
	return p;
}

void push_back(List& l, int value)
{
	Node* p = CreateNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		Node* g = l.pHead;
		while (g->next) {
			g = g->next;
		}
		g->next = p;
	}
}

void deleteDuplicates(Node*& head)
{	
	for (Node* g = head; g ; g = g->next)
	{	
		
		for (Node* k = g; k->next ; k = k->next)
		{	

			if (g->data == k->next->data)
			{	
				Node* dup = k->next;
				k->next = k->next->next;
				delete dup;
			}
		}
	}
}
void ExportList(List l)
{
	for (Node* g = l.pHead; g; g = g->next)
	{
		cout << g->data<<" ";
	}
}
void DestroyList(List &l)
{	
	Node* p=new Node;
	while (l.pHead)
	{	
		Node* p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
	}
}
int main()
{
	List l;
	int arr[] = { 1,3,1,5,6,3 };
	int n = (sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < n; i++)
	{
		push_back(l, arr[i]);
	}
	
	deleteDuplicates(l.pHead);
	ExportList(l);
	DestroyList(l);
	
}
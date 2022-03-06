#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* pHead = NULL;
};
Node* CreateNode(int value)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = value;
		p->pNext = NULL;
	}
	return p;
}

void push_back(List& l, int x)
{
	if (l.pHead == NULL)
	{	
		Node* p = CreateNode(x);
		l.pHead = p;
	}
	else
	{	
		Node* g = l.pHead;
		while (g->pNext)
		{
			g = g->pNext;
		}
		g->pNext = CreateNode(x);
	}
}

Node* getTail(Node* head)
{
	Node* g = head;
	while (g->pNext)
	{
		g = g->pNext;
	}
	return g;
}
void deleteLast(Node*& head)
{
	Node* g = head;
	Node* h = new Node;
	while (g->pNext)
	{	
		h = g;
		g=g->pNext;

	}
	delete g;
	h->pNext = NULL;
	for (Node* k = head; k; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

int main()
{
	List l;
	int n; cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push_back(l, x);
	}
	Node* p = getTail(l.pHead);
	cout << p->data;
	deleteLast(l.pHead);
	
}


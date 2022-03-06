#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
struct List {
	Node* head=NULL;
};

Node* CreateNode(int data)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "NOT ENOUGH MEMORY";
	}
	else
	{
		p->data = data;
		p->next = NULL;
	}
	return p;
}

void push_back(List& l, int value)
{	
	
	if (l.head == NULL)
	{
		Node* p = CreateNode(value);
		l.head = p;
	}
	else
	{
		Node* g = l.head;
		while (g->next)
		{
			g = g->next;
		}
		g->next = CreateNode(value);
	}
}
int countNodes(List ls)
{	
	int count = 0;
	Node* h = ls.head;
	Node* g = ls.head->next;
	Node* k	= g->next;
	while (k)
	{
		cout << "phan tu truoc:" << h->data <<endl;
		cout << "phan tu xet:" << g->data<<endl;
		cout << "phan tu sau:" << k->data<<endl;
		cout << endl << endl;
		if ((h->data + k->data) == g->data)
		{
			count++;
		}
		h = h->next;
		g = g->next;
		k = g->next;
	}
	return count;
	

}
int main()
{
	List l;
	int n,count;
	cin >> n;
	int arr[] = { 6,7,1,4,3,-1,11 };
	for (int i = 0; i < n; i++)
	{
		
		push_back(l, arr[i]);
	}
	count = countNodes(l);
	cout << count;
}